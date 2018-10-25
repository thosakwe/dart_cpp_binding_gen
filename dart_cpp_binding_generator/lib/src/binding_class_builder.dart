import 'dart:async';
import 'package:analyzer/dart/element/element.dart';
import 'package:analyzer/dart/element/type.dart';
import 'package:build/build.dart';
import 'package:c_builder/c_builder.dart' as c;
import 'package:code_buffer/code_buffer.dart';
import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';
import 'package:path/path.dart' as p;
import 'package:recase/recase.dart';
import 'package:source_gen/source_gen.dart';
import 'cpp_gen.dart';

Builder cppBindingClassBuilder(_) => const CppBindingClassBuilder();

class CppBindingClassBuilder implements Builder {
  const CppBindingClassBuilder();

  @override
  Map<String, List<String>> get buildExtensions {
    return {
      '.dart': ['.g.hpp', '.g.cpp']
    };
  }

  Future build(BuildStep buildStep) async {
    var lib = await buildStep.inputLibrary;
    var rdr = new LibraryReader(lib);
    var binding = const TypeChecker.fromRuntime(Binding);
    var genBindings = rdr.annotatedWith(binding);

    if (genBindings.isEmpty) {
      return null;
    } else {
      var rc = new ReCase(
          p.basenameWithoutExtension(buildStep.inputId.path) + '_binding_h');
      var defName = rc.constantCase;
      var header = new c.CompilationUnit()
        ..body.addAll([
          new c.Include.system('dart_api.h'),
          new c.Include.system('string'),
          new c.Code('#ifndef $defName'),
          new c.Code('#define $defName')
        ]);

      var impl = new c.CompilationUnit()
        ..body.add(new c.Include.quotes(
            p.basename(p.setExtension(buildStep.inputId.path, '.g.hpp'))));

      var namespace =
          new Namespace(new ReCase(buildStep.inputId.package).snakeCase);

      for (var annElement in genBindings) {
        if (annElement.element is ClassElement) {
          namespace.body.add(new c.Code('class ${annElement.element.name};'));
        }
      }

      for (var annElement in genBindings) {
        if (annElement.element is ClassElement) {
          new _Gen(buildStep, annElement.element as ClassElement, namespace,
                  impl)
              .walk();
        } else {
          throw new UnsupportedError(
              'Only classes can be annotated with @binding.');
        }
      }

      header.body.addAll([namespace, new c.Code('#endif')]);

      var headerBuf = new CodeBuffer(), implBuf = new CodeBuffer();
      header.generate(headerBuf);
      impl.generate(implBuf);

      buildStep
        ..writeAsString(
            buildStep.inputId.changeExtension('.g.hpp'), headerBuf.toString())
        ..writeAsString(
            buildStep.inputId.changeExtension('.g.cpp'), implBuf.toString());
    }
  }
}

final _dartHandle = new c.CType('Dart_Handle');

bool _isList(DartType t) =>
    const TypeChecker.fromRuntime(List).isAssignableFromType(t);

bool _isMap(DartType t) =>
    const TypeChecker.fromRuntime(Map).isAssignableFromType(t);

bool _isString(DartType t) =>
    const TypeChecker.fromRuntime(String).isAssignableFromType(t);

bool _isInt(DartType t) =>
    const TypeChecker.fromRuntime(int).isAssignableFromType(t);

bool _isDouble(DartType t) =>
    const TypeChecker.fromRuntime(double).isAssignableFromType(t);

bool _isBool(DartType t) =>
    const TypeChecker.fromRuntime(bool).isAssignableFromType(t);

bool _isNum(DartType t) => const TypeChecker.fromRuntime(num).isExactlyType(t);

class _Gen {
  final BuildStep buildStep;
  final ClassElement element;
  final Namespace namespace;
  final c.CompilationUnit impl;
  Class _clazz;
  MemberSection _public, _private;

  _Gen(this.buildStep, this.element, this.namespace, this.impl);

  c.CType get _ctype => new c.CType(_clazz.name);

  c.Parameter _convertParameter(ParameterElement p,
      [bool withNamespace = false]) {
    return new c.Parameter(
        _convertParameterType(p.type, withNamespace), p.name);
  }

  c.CType _convertParameterType(DartType t, [bool withNamespace = false]) {
    if (_isString(t))
      return reference(new c.CType('std::string')).const$();
    else if (_isInt(t))
      return c.CType.int64_t;
    else if (_isDouble(t))
      return c.CType.double;
    else if (_isBool(t))
      return new c.CType('bool');
    else if (_isList(t) && t is InterfaceType && t.typeArguments.isNotEmpty) {
      var rc = new ReCase(t.typeArguments.first.name);
      var listName = '${rc.pascalCase}List';
      return new c.CType(listName);
    } else {
      if (!withNamespace) return reference(new c.CType(t.name)).const$();
      return reference(namespacedType(namespace, new c.CType(t.name))).const$();
    }
  }

  c.Expression _defaultValue(DartType t) {
    if (_isString(t))
      return new c.Expression('""');
    else if (_isInt(t))
      return new c.Expression('0');
    else if (_isDouble(t))
      return new c.Expression('0.0');
    else if (_isBool(t)) return new c.Expression('false');
    return new c.Expression('nullptr');
  }

  void walk() {
    // Generate a class Foo {};
    namespace.body.add(_clazz = new Class(element.name));
    _clazz.body.addAll([
      _public = new MemberSection('public'),
      _private = new MemberSection('private')
    ]);

    // static  Dart_HandleHandleError(Dart_Handle handle);
    _private.body
        .add(new c.Code('static Dart_Handle handleError(Dart_Handle handle);'));
    impl.body.add(new Method(namespace.name, _ctype, 'handleError',
        returnType: _dartHandle)
      ..parameters.add(new c.Parameter(_dartHandle, 'handle'))
      ..body.addAll([
        new c.Code('if (Dart_IsError(handle)) Dart_PropagateError(handle);'),
        new c.Code('return handle;')
      ]));

    // Foo(const Dart_Handle handle);
    _public.body.add(new c.Code('${_clazz.name}(Dart_Handle handle);'));
    _genConstructor();

    // const Dart_Handle handle;
    _private.body.add(new c.Field(_dartHandle, 'handle'));

    // const Dart_Handle getHandle() const;
    _genGetHandle();

    // Generate constructors.
    for (var constructor in element.constructors) {
      var headerParams = constructor.parameters.map(_convertParameter);
      var implParams = constructor.parameters
          .map((p) => _convertParameter(p, true))
          .toList();
      var body = <c.Code>[];
      var requiredCount =
          constructor.parameters.where((p) => p.isNotOptional).length;

      int i = 0;
      var sigParams = headerParams.map((p) {
        var nullptr = _defaultValue(constructor.parameters[i++].type).code;
        var dart = constructor.parameters.firstWhere((pp) => pp.name == p.name);
        return dart.isNotOptional
            ? p
            : new c.Parameter(p.type, '${p.name} = $nullptr');
      });

      if (constructor.isDefaultConstructor || constructor.name.isEmpty) {
        _public.body
            .add(new c.Code('${_clazz.name}(${sigParams.join(', ')});'));
      } else {
        var sig = new c.FunctionSignature(_ctype.static(), constructor.name)
          ..parameters.addAll(sigParams);
        _public.body.add(sig);
      }

      // Next, create the impl. A Dart_Handle is created, and then returned.
      /*
      Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/test/foo.dart"));
      Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
      Dart_Handle arguments[0];
      return Dart_New(clazz, Dart_NewStringFromCString(""), 0, arguments);
    */
      var packagePath = p.join(
          'package:${buildStep.inputId.package}', buildStep.inputId.path);

      body.addAll([
        new c.Code('Dart_Handle arguments[${constructor.parameters.length}];'),
        new c.Code('int argLen = $requiredCount;'),
        new c.Code(
            'Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("$packagePath"));'),
        new c.Code(
            'Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("${element.name}"));'),
      ]);

      for (int i = 0; i < constructor.parameters.length; i++) {
        var dart = constructor.parameters[i];
        var cpp = implParams[i];
        var value = new c.Expression('${dart.name}.getHandle()');

        if (_isString(dart.type)) {
          value = new c.Expression(
              'Dart_NewStringFromCString(${dart.name}.c_str())');
        } else if (_isInt(dart.type)) {
          value = new c.Expression('Dart_NewInteger(${dart.name})');
        } else if (_isDouble(dart.type)) {
          value = new c.Expression('Dart_NewDouble(${dart.name})');
        } else if (_isBool(dart.type)) {
          value = new c.Expression('Dart_NewBoolean(${dart.name})');
        }

        List<c.Code> b = body;

        if (dart.isOptional) {
          var nullptr = _defaultValue(dart.type).code;
          var cond = new c.Expression('${dart.name} != $nullptr');
          var ifThen = new c.ControlFlow.if$(cond)
            ..body.addAll(
                [new c.Code('argLen++;'), value.assignTo('arguments[$i]')]);
          var else$ = new c.ControlFlow.else$()
            ..body.add(new c.Code('arguments[$i] = Dart_Null();'));
          b.addAll([ifThen, else$]);
        } else {
          b.add(value.assignTo('arguments[$i]'));
        }
      }

      var handle = new c.Expression(
          'Dart_New(clazz, Dart_NewStringFromCString("${constructor.name}"), argLen, arguments)');

      if (constructor.isDefaultConstructor || constructor.name.isEmpty) {
        body.add(handle.assignTo('this->handle'));
      } else {
        body.add(handle.asReturn());
      }

      c.CType returnType;
      String name = constructor.name;

      if (!constructor.isDefaultConstructor && constructor.name.isNotEmpty) {
        returnType = namespacedType(namespace, _ctype);
      } else {
        name = _clazz.name;
      }

      impl.body.add(
          new Method(namespace.name, _ctype, name, returnType: returnType)
            ..parameters.addAll(implParams)
            ..body.addAll(body));
    }

    // Generate getters, setters for fields.
    for (var field in element.fields) {
      // TODO: String, int, bool, null, Lists, Maps

      var outType = _convertParameterType(
          field.type); //reference(new c.CType(field.type.name));
      var namespaced = _convertParameterType(
          field.type, true); //namespacedType(namespace, outType);
      var setterType = outType, setterNamespaced = namespaced;

      // Special Dart types require special handling.
      if (_isString(field.type)) {
        setterNamespaced = namespaced = outType = new c.CType('std::string');
      } else if (_isInt(field.type)) {
        setterNamespaced = namespaced = outType = c.CType.int64_t;
      } else if (_isDouble(field.type)) {
        setterNamespaced = namespaced = outType = c.CType.double;
      } else if (_isBool(field.type)) {
        setterNamespaced = namespaced = outType = new c.CType('bool');
      } else {
        setterNamespaced = namespaced.const$();
        setterType = outType.const$();
      }

      var getterName = 'get' + new ReCase(field.name).pascalCase;
      var setterName = 'set' + new ReCase(field.name).pascalCase;

      if (field.getter != null) {
        // Bar& getBar() const;
        var sig = new c.FunctionSignature(outType, getterName);
        _public.body.add(new ConstSignature(sig));

        // Bar& package::Foo::getBar() const {
        //  return Dart_GetField(instance, Dart_NewStringFromCString("baz"));
        // }
        var rawHandle = new c.Expression(
            'Dart_GetField(handle, Dart_NewStringFromCString("${field.name}"))');
        var m = new Method(namespace.name, _ctype, getterName,
            isConst: true, returnType: namespaced);
        c.Expression retVal = rawHandle;

        if (_isString(field.type)) {
          // Assign to a char*, return it (will be converted by C++ automatically)
          m.body.addAll([
            rawHandle.assignTo('Dart_Handle rawHandle'),
            new c.Code('const char *value;'),
            new c.Code('handleError(Dart_StringToCString(rawHandle, &value));')
          ]);
          retVal = new c.Expression('value');
        } else if (_isInt(field.type)) {
          m.body.addAll([
            rawHandle.assignTo('Dart_Handle rawHandle'),
            new c.Code('int64_t value;'),
            new c.Code('handleError(Dart_IntegerToInt64(rawHandle, &value));')
          ]);
          retVal = new c.Expression('value');
        } else if (_isDouble(field.type)) {
          m.body.addAll([
            rawHandle.assignTo('Dart_Handle rawHandle'),
            new c.Code('double value;'),
            new c.Code('handleError(Dart_DoubleValue(rawHandle, &value));')
          ]);
          retVal = new c.Expression('value');
        } else if (_isDouble(field.type)) {
          m.body.addAll([
            rawHandle.assignTo('Dart_Handle rawHandle'),
            new c.Code('bool value;'),
            new c.Code('handleError(Dart_BooleanValue(rawHandle, &value));')
          ]);
          retVal = new c.Expression('value');
        }

        // Ultimately, return something..
        m.body.add(retVal.asReturn());

        impl.body.add(m);
      }

      if (field.setter != null) {
        // void setBar(const Bar& value);
        _public.body.add(new c.FunctionSignature(c.CType.void$, setterName)
          ..parameters.add(new c.Parameter(outType, 'value')));

        // void package::Foo::setBar(Bar& value) {
        //   Dart_SetField(handle, Dart_NewStringFromCString("baz"), value.getHandle());
        // }
        var m = new Method(namespace.name, _ctype, setterName,
            returnType: c.CType.void$)
          ..parameters.add(new c.Parameter(setterNamespaced, 'value'));
        c.Expression setVal = new c.Expression('value.getHandle()');

        if (_isString(field.type)) {
          setVal = new c.Expression('Dart_NewStringFromCString(value.c_str())');
        } else if (_isInt(field.type)) {
          setVal = new c.Expression('Dart_NewInteger(value)');
        } else if (_isDouble(field.type)) {
          setVal = new c.Expression('Dart_NewDouble(value)');
        } else if (_isBool(field.type)) {
          setVal = new c.Expression('Dart_NewBoolean(value)');
        }

        impl.body.add(m
          ..body.add(new c.Code(
              'Dart_SetField(handle, Dart_NewStringFromCString("${field.name}"), ${setVal.code});')));
      }
    }
  }

  void _genConstructor() {
    impl.body.add(new Method(namespace.name, _ctype, _clazz.name)
      ..parameters.add(new c.Parameter(_dartHandle, 'handle'))
      ..body.add(new c.Code('this->handle = handle;')));
  }

  void _genGetHandle() {
    // const Dart_Handle getHandle() const;
    var sig = new c.FunctionSignature(_dartHandle, 'getHandle');
    _public.body.add(new ConstSignature(sig));
    impl.body.add(new Method(namespace.name, _ctype, 'getHandle',
        isConst: true, returnType: _dartHandle)
      ..body.add(new c.Code('return handle;')));
  }
}
