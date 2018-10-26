import 'dart:async';

import 'package:analyzer/dart/ast/ast.dart';
import 'package:build/build.dart';
import 'package:c_builder/c_builder.dart' as c;
import 'package:code_buffer/code_buffer.dart';
import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';
import 'package:path/path.dart' as p;
import 'package:recase/recase.dart';
import 'package:source_gen/source_gen.dart';

/// [ExtensionBuilder] factory.
Builder extensionBuilder(_) => const ExtensionBuilder();

const TypeChecker extensionTypeChecker =
    const TypeChecker.fromRuntime(Extension);

final _dartHandleType = new c.CType('Dart_Handle');

class ExtensionBuilder implements Builder {
  const ExtensionBuilder();

  @override
  Map<String, List<String>> get buildExtensions {
    return {
      '.dart': ['.extension.g.hpp', '.extension.g.cpp']
    };
  }

  @override
  Future build(BuildStep buildStep) async {
    var lib = await buildStep.inputLibrary.catchError((_) => null);
    if (lib == null) return null;

    ConstantReader annotation;

    for (var m in lib.metadata) {
      var cr = new ConstantReader(m.constantValue);
      if (cr.instanceOf(extensionTypeChecker)) {
        annotation = cr;
        break;
      }
    }

    if (annotation == null) return null;
    var natives = <String, NativeFunctionBody>{};
    var headerBuf = new CodeBuffer(), helperBuf = new CodeBuffer();

    for (var unit in lib.units) {
      for (var f in unit.computeNode().declarations) {
        if (f is FunctionDeclaration) {
          var body = f.functionExpression.body;

          if (body is NativeFunctionBody) {
            natives[f.name.name] = body;
          }
        }
      }
    }

    if (natives.isEmpty) return null;

    var headerFile = new c.CompilationUnit();
    var ifDefRc = new ReCase(buildStep.inputId.package +
        '_' +
        p.basename(buildStep.inputId.path) +
        '_Extension_H');

    headerFile.body.addAll([
      new c.Code('#ifndef ${ifDefRc.constantCase}'),
      new c.Code('#define ${ifDefRc.constantCase}'),
      new c.Include.system('string'),
      new c.Include.system('dart_api.h'),
    ]);

    var resolveName = new c.CFunction(new c.FunctionSignature(
        new c.CType('Dart_NativeFunction'), 'ResolveName'));
    headerFile.body.add(resolveName.signature);
    resolveName.signature.parameters.addAll([
      new c.Parameter(_dartHandleType, 'name'),
      new c.Parameter(c.CType.int, 'argc'),
      new c.Parameter(new c.CType('bool').pointer(), 'auto_setup_scope'),
    ]);

    // Create foo_init.
    var initRc = new ReCase(p.basenameWithoutExtension(buildStep.inputId.path));
    var initFn = new c.CFunction(new c.FunctionSignature(
        _dartHandleType.prefix('DART_EXPORT'), initRc.snakeCase + '_Init'));
    headerFile.body.add(initFn.signature);
    initFn.signature.parameters
        .add(new c.Parameter(_dartHandleType, 'parent_library'));
    initFn.body.addAll('''
if (Dart_IsError(parent_library)) return parent_library;

Dart_Handle result_code =
        Dart_SetNativeResolver(parent_library, ResolveName, NULL);
if (Dart_IsError(result_code)) return result_code;

return Dart_Null();
    '''
        .trim()
        .split('\n')
        .where((s) => s.isNotEmpty)
        .map((s) => new c.Code(s)));

    /**
     * // If we fail, we return NULL, and Dart throws an exception.

        if (strcmp("SystemSrand", cname) == 0) result = SystemSrand;
     */
    resolveName.body.addAll([
      new c.Code('if (!Dart_IsString(name)) return NULL;'),
      new c.Code('Dart_NativeFunction result = NULL;'),
      new c.Code('const char* cname;'),
      new c.Code(
          'Dart_Handle stringHandle = (Dart_StringToCString(name, &cname));'),
      new c.Code(
          'if (Dart_IsError(stringHandle)) Dart_PropagateError(stringHandle);'),
    ]);

    natives.forEach((name, body) {
      var literal = body.stringLiteral.stringValue;
      var n = buildStep.inputId.package + '_extension_' + name;
      resolveName.body
          .add(new c.Code('if (strcmp("$literal", cname) == 0) result = $n;'));

      // Lastly, generate a stub for each function.
      headerFile.body.add(new c.FunctionSignature(c.CType.void$, n)
        ..parameters.add(
            new c.Parameter(new c.CType('Dart_NativeArguments'), 'arguments')));
    });

    resolveName.body.add(new c.Code('return result;'));

    var helperFile = new c.CompilationUnit();
    helperFile.body.addAll([
      new c.Include.quotes(
          p.setExtension(p.basename(buildStep.inputId.uri.path), '.h')),
      resolveName,
      initFn
    ]);

    headerFile.body.add(new c.Code('#endif'));
    headerFile.generate(headerBuf);
    helperFile.generate(helperBuf);

    buildStep.writeAsString(
        buildStep.inputId.changeExtension('.extension.g.hpp'),
        headerBuf.toString());
    buildStep.writeAsString(
        buildStep.inputId.changeExtension('.extension.g.cpp'),
        helperBuf.toString());
  }
}
