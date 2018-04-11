import 'dart:async';

import 'package:analyzer/dart/element/element.dart';
import 'package:build/build.dart';
import 'package:c_builder/c_builder.dart' as c;
import 'package:code_buffer/code_buffer.dart';
import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';
import 'package:path/path.dart' as p;
import 'package:recase/recase.dart';
import 'package:source_gen/source_gen.dart';

/// [DelegateBuilder] factory.
Builder delegateBuilder(_) => const DelegateBuilder();

const TypeChecker delegateTypeChecker = const TypeChecker.fromRuntime(Binding);

final c.CType dartHandleType = new c.CType('Dart_Handle');

final RegExp _doc = new RegExp(r'^///\s*');

String stripDoc(String s) => s.replaceAll(_doc, '');

class DelegateBuilder implements Builder {
  const DelegateBuilder();

  @override
  Map<String, List<String>> get buildExtensions {
    return {
      '.dart': ['.delegate.h', '.delegate.cpp']
    };
  }

  @override
  Future build(BuildStep buildStep) async {
    var lib = await buildStep.inputLibrary.catchError((_) => null);
    if (lib == null) return null;

    var rdr = new LibraryReader(lib);
    var classes = rdr.annotatedWith(delegateTypeChecker);
    if (classes.isEmpty) return null;

    var headerFile = new c.CompilationUnit(),
        implementationFile = new c.CompilationUnit();
    var ifDefRc = new ReCase(buildStep.inputId.package +
        '_' +
        p.basename(buildStep.inputId.path) +
        '_H');

    headerFile.body.addAll([
      new c.Code('#ifndef ${ifDefRc.constantCase}'),
      new c.Code('#define ${ifDefRc.constantCase}'),
      new c.Include.system('dart_api.h'),
    ]);

    implementationFile.body.add(
      new c.Include.quotes(
          p.basename(p.setExtension(buildStep.inputId.path, '.delegate.h'))),
    );

    for (var element in classes)
      await generateBindings(
          buildStep, element, headerFile, implementationFile);

    headerFile.body.add(new c.Code('#endif'));

    var hBuf = new CodeBuffer(), iBuf = new CodeBuffer();
    headerFile.generate(hBuf);
    implementationFile.generate(iBuf);

    buildStep.writeAsString(
        buildStep.inputId.changeExtension('.delegate.h'), hBuf.toString());
    buildStep.writeAsString(
        buildStep.inputId.changeExtension('.delegate.cpp'), iBuf.toString());
  }

  generateBindings(
      BuildStep buildStep,
      AnnotatedElement element,
      c.CompilationUnit headerFile,
      c.CompilationUnit implementationFile) async {
    if (element.element is ClassElement) {
      var clazz = element.element as ClassElement;
      var packageRc = new ReCase(buildStep.inputId.package);
      var rc = new ReCase(clazz.name);
      generateConstructors(
          buildStep, rc, packageRc, clazz, headerFile, implementationFile);
      generateFields(rc, packageRc, clazz, headerFile, implementationFile);
      generateMethods(rc, packageRc, clazz, headerFile, implementationFile);
    }
  }

  generateConstructors(
      BuildStep buildStep,
      ReCase rc,
      ReCase packageRc,
      ClassElement clazz,
      c.CompilationUnit headerFile,
      c.CompilationUnit implementationFile) {
    for (var constructor in clazz.constructors) {
      var name = '${packageRc.snakeCase}_new_${rc.snakeCase}';
      var suffix = '';

      if (constructor.name.isNotEmpty) {
        if (!constructor.name.startsWith('_')) name += '_';
        name += constructor.name;
        suffix = '.${constructor.name}';
      }

      var sig = new c.FunctionSignature(dartHandleType, name);

      if (constructor.documentationComment == null)
        sig
          ..comments
              .add('Creates a new instance of `${rc.pascalCase}$suffix.`');
      else
        sig.comments
            .addAll(constructor.documentationComment.split('\n').map(stripDoc));

      var f = new c.CFunction(sig);
      headerFile.body.add(sig);
      implementationFile.body.add(f);

      var libPath = p.join(
          'package:${buildStep.inputId.package}', buildStep.inputId.path);

      f.body.addAll([
        new c.Code(
            'Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("$libPath"));'),
        new c.Code(
            'Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("${clazz
                .name}"));'),
        new c.Code('Dart_Handle arguments[${constructor.parameters.length}];'),
      ]);

      applyParams(sig, f, constructor.parameters);

      sig.comments.add('@return A handle to the created instance.');
      f.body.add(new c.Code(
          'return Dart_New(clazz, Dart_NewStringFromCString("' +
              constructor.name +
              '"), ${constructor.parameters.length}, arguments);'));
    }
  }

  void applyParams(
      c.FunctionSignature sig, c.CFunction f, List<ParameterElement> params) {
    int i = 0;

    for (var param in params) {
      var name = new ReCase(param.name).camelCase;
      var suffix = param.documentationComment == null
          ? null
          : param.documentationComment.split('\n').map(stripDoc).join(' ');
      suffix ??= (param.hasRequired || param.isNotOptional) ? 'Required.' : '';
      sig.comments.add('@param $name $suffix');
      sig.parameters.add(new c.Parameter(dartHandleType, name));
      f.body.add(new c.Code('arguments[${i++}] = $name;'));
    }
  }

  void generateFields(ReCase rc, ReCase packageRc, ClassElement clazz,
      c.CompilationUnit headerFile, c.CompilationUnit implementationFile) {
    for (var p in clazz.accessors) {
      String upper, lower;

      if (p.isGetter) {
        upper = 'Get';
        lower = 'get';
      } else if (p.isSetter) {
        upper = 'Set';
        lower = 'set';
      } else {
        continue;
      }

      var name = '${packageRc.snakeCase}_${rc.snakeCase}_${lower}_${p
          .displayName}';
      name = new ReCase(name).snakeCase;
      var sig = new c.FunctionSignature(
          p.isGetter ? dartHandleType : c.CType.void$, name);
      var f = new c.CFunction(sig);
      headerFile.body.add(sig);
      implementationFile.body.add(f);
      sig.parameters.add(new c.Parameter(dartHandleType, 'instance'));

      if (p.isSetter)
        sig.parameters.add(new c.Parameter(dartHandleType, 'value'));

      sig.comments.add(
          '${upper}s the `${p.displayName}` property of an instance of `${rc
              .pascalCase}`.');

      // Dart_GetField(instance, Dart_NewStringFromCString("baz"));
      var fieldMethod = new c.Expression('Dart_${upper}Field');
      var arguments = <c.Expression>[
        new c.Expression('instance'),
        new c.Expression('Dart_NewStringFromCString').invoke([
          new c.Expression.value(p.displayName),
        ]),
      ];

      if (p.isSetter) arguments.add(new c.Expression('value'));

      fieldMethod = fieldMethod.invoke(arguments);

      if (p.isGetter) fieldMethod = fieldMethod.asReturn();
      f.body.add(fieldMethod);
    }
  }

  void generateMethods(ReCase rc, ReCase packageRc, ClassElement clazz,
      c.CompilationUnit headerFile, c.CompilationUnit implementationFile) {
    for (var method in clazz.methods) {
      var name = '${packageRc.snakeCase}_${rc.snakeCase}_invoke_${method.name}';
      var sig =
          new c.FunctionSignature(dartHandleType, new ReCase(name).snakeCase);
      var f = new c.CFunction(sig);
      headerFile.body.add(sig);
      implementationFile.body.add(f);
      sig.parameters.add(new c.Parameter(dartHandleType, 'instance'));

      if (method.documentationComment == null)
        sig
          ..comments
              .add('Invokes the `${method.name}` method of an instance of `${rc
              .pascalCase}`.');
      else
        sig.comments
            .addAll(method.documentationComment.split('\n').map(stripDoc));

      f.body.add(
          new c.Code('Dart_Handle arguments[${method.parameters.length}];'));

      applyParams(sig, f, method.parameters);

      sig.comments.add('@return The result of calling the function.');
      f.body.add(new c.Code(
          'return Dart_Invoke(instance, Dart_NewStringFromCString("' +
              method.name +
              '"), ${method.parameters.length}, arguments);'));
    }
  }
}
