import 'dart:async';
import 'package:analyzer/dart/element/element.dart';
import 'package:analyzer/dart/element/type.dart';
import 'package:build/build.dart';
import 'package:c_builder/c_builder.dart' as c;
import 'package:code_buffer/code_buffer.dart';
import 'package:cpp_binding/cpp_binding.dart';
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
      var forwardDeclarations = <c.Code>[];
      var walked = <DartType>[];

      for (var annElement in genBindings) {
        if (annElement.element is ClassElement) {
          forwardDeclarations
              .add(_forwardDeclare((annElement.element as ClassElement).type));
        }
      }

      for (var annElement in genBindings) {
        if (annElement.element is ClassElement) {
          var clazz = annElement.element as ClassElement;
          walked.add(clazz.type);
          new _Gen(buildStep, forwardDeclarations, walked, clazz, namespace,
                  impl)
              .walk();
        } else {
          throw new UnsupportedError(
              'Only classes can be annotated with @binding.');
        }
      }

      namespace.body.insertAll(0, forwardDeclarations);
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

c.Code _forwardDeclare(DartType t) {
  var out = new c.Code('class ${t.name};');

  if (t is InterfaceType && t.typeParameters.isNotEmpty) {
    var template = t.typeParameters.map((p) => 'typename ${p.name}').join(', ');
    out = new c.Code('template < $template > ${out.code}');
  }

  return out;
}

bool _isList(DartType t) =>
    const TypeChecker.fromRuntime(List).isAssignableFromType(t);

//bool _isMap(DartType t) =>
//    const TypeChecker.fromRuntime(Map).isAssignableFromType(t);

bool _isString(DartType t) =>
    const TypeChecker.fromRuntime(String).isAssignableFromType(t);

bool _isInt(DartType t) =>
    const TypeChecker.fromRuntime(int).isAssignableFromType(t);

bool _isDouble(DartType t) =>
    const TypeChecker.fromRuntime(double).isAssignableFromType(t);

bool _isBool(DartType t) =>
    const TypeChecker.fromRuntime(bool).isAssignableFromType(t);

class _Gen {
  final BuildStep buildStep;
  final List<c.Code> forwardDeclarations;
  final List<DartType> walked;
  final ClassElement element;
  final Namespace namespace;
  final c.CompilationUnit impl;
  Class _clazz;
  MemberSection _public, _private;
  Iterable<TemplateArgument> _tmplArgs;

  _Gen(this.buildStep, this.forwardDeclarations, this.walked, this.element,
      this.namespace, this.impl);

  c.CType get _ctype => new c.CType(_clazz.name);

  c.Parameter _convertParameter(ParameterElement p,
      [bool withNamespace = false]) {
    c.CType type;

    try {
      type = _convertParameterType(p.type, withNamespace);
    } catch (_) {
      type = _dartHandle;
    }

    return new c.Parameter(type, p.name);
  }

  c.Expression _readReturn(
      c.Expression rawHandle, DartType type, List<c.Code> body) {
    c.Expression retVal = rawHandle;

    if (type == null || type.isDynamic) return rawHandle;

    if (_isString(type)) {
      // Assign to a char*, return it (will be converted by C++ automatically)
      body.addAll([
        rawHandle.assignTo('Dart_Handle rawHandle'),
        new c.Code('const char *value;'),
        new c.Code('handleError(Dart_StringToCString(rawHandle, &value));')
      ]);
      retVal = new c.Expression('value');
    } else if (_isInt(type)) {
      body.addAll([
        rawHandle.assignTo('Dart_Handle rawHandle'),
        new c.Code('int64_t value;'),
        new c.Code('handleError(Dart_IntegerToInt64(rawHandle, &value));')
      ]);
      retVal = new c.Expression('value');
    } else if (_isDouble(type)) {
      body.addAll([
        rawHandle.assignTo('Dart_Handle rawHandle'),
        new c.Code('double value;'),
        new c.Code('handleError(Dart_DoubleValue(rawHandle, &value));')
      ]);
      retVal = new c.Expression('value');
    } else if (_isBool(type)) {
      body.addAll([
        rawHandle.assignTo('Dart_Handle rawHandle'),
        new c.Code('bool value;'),
        new c.Code('handleError(Dart_BooleanValue(rawHandle, &value));')
      ]);
      retVal = new c.Expression('value');
    }

    return retVal;
  }

  void _readParameters(List<ParameterElement> parameters, List<c.Code> body) {
    for (int i = 0; i < parameters.length; i++) {
      var dart = parameters[i];
      var value = new c.Expression('${dart.name}.getHandle()');

      if (_isString(dart.type)) {
        value =
            new c.Expression('Dart_NewStringFromCString(${dart.name}.c_str())');
      } else if (_isInt(dart.type)) {
        value = new c.Expression('Dart_NewInteger(${dart.name})');
      } else if (_isDouble(dart.type)) {
        value = new c.Expression('Dart_NewDouble(${dart.name})');
      } else if (_isBool(dart.type)) {
        value = new c.Expression('Dart_NewBoolean(${dart.name})');
      } else if (dart.type.isDynamic ||
          _convertParameterType(dart.type).code == _dartHandle.code) {
        value = new c.Expression(dart.name);
      }

      List<c.Code> b = body;

      if (dart.isOptional) {
        var nullptr = _defaultValue(dart.type)?.code;
        var cond = new c.Expression(
            _isBool(dart.type) ? dart.name : '${dart.name} != $nullptr');
        if (nullptr == null)
          cond = new c.Expression(
              '!Dart_IdentityEquals(${dart.name}.getHandle(), Dart_Null())');
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
  }

  static const ignoredClasses = const [
    const TypeChecker.fromRuntime(List),
    const TypeChecker.fromRuntime(Iterable),
    const TypeChecker.fromRuntime(Iterator),
    const TypeChecker.fromRuntime(Invocation),
    const TypeChecker.fromRuntime(Map),
    const TypeChecker.fromRuntime(MapEntry),
    const TypeChecker.fromRuntime(Set),
    const TypeChecker.fromRuntime(Stream),
    const TypeChecker.fromRuntime(Future),
    const TypeChecker.fromRuntime(StreamSubscription),
  ];

  c.CType _convertParameterType(DartType t, [bool withNamespace = false]) {
    if (t.name == 'void' || t.isVoid) {
      return c.CType.void$;
    } else if (_isString(t))
      return reference(new c.CType('std::string')).const$();
    else if (_isInt(t))
      return c.CType.int64_t;
    else if (_isDouble(t))
      return c.CType.double;
    else if (_isBool(t))
      return new c.CType('bool');
    else if (t is TypeParameterType) {
      return new c.CType(t.name);
    } else if (ignoredClasses.any((tt) => tt.isAssignableFromType(t))) {
      return _dartHandle;
    } else {
      // Bind the type, if it hasn't been bound yet.
      var tc = new TypeChecker.fromStatic(t);
      if (t.element is ClassElement && !walked.any(tc.isExactlyType)) {
        var decl = _forwardDeclare(t);

        // Additional guard to prevent dupe classes...
        if (!forwardDeclarations.any((c) => c.code == decl.code)) {
          forwardDeclarations.add(decl);
          walked.add(t);
          new _Gen(buildStep, forwardDeclarations, walked,
                  t.element as ClassElement, namespace, impl)
              .walk();
        }
      }

      if (t is InterfaceType && t.typeArguments.isNotEmpty) {
        var targs = t.typeArguments
            .map((t) => _convertParameterType(t, withNamespace))
            .map((t) => t.code)
            .join(', ');
        return !withNamespace
            ? reference(new c.CType('${t.name}< $targs >'))
            : reference(
                namespacedType(namespace, new c.CType('${t.name}< $targs >')));
      } else {
        if (t.name == null || t.element.isSynthetic) {
          //throw new UnimplementedError(
          //    'The name of this type (${t.runtimeType}) is null or empty; file an issue.');
          return _dartHandle;
        }

        if (!withNamespace) return reference(new c.CType(t.name)); //.const$();
        return reference(namespacedType(namespace, new c.CType(t.name)));
        //.const$();
      }
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
    return null;
  }

  void walk() {
    // Generate a class Foo {};
    c.Code root = _clazz = new Class(element.name);

    if (element.type.typeParameters.isNotEmpty) {
      root = new Template(root)
        ..arguments.addAll(_tmplArgs = element.type.typeParameters
            .map((p) => new TemplateArgument.typename(p.name)));
    }

    namespace.body.add(root);
    _clazz.body.addAll([
      _public = new MemberSection('public'),
      _private = new MemberSection('private')
    ]);

    // static  Dart_HandleHandleError(Dart_Handle handle);
    _private.body
        .add(new c.Code('static Dart_Handle handleError(Dart_Handle handle);'));
    impl.body.add(_maybeApplyTemplate(new Method(
        namespace.name, _ctype, 'handleError',
        returnType: _dartHandle)
      ..parameters.add(new c.Parameter(_dartHandle, 'handle'))
      ..body.addAll([
        new c.Code('if (Dart_IsError(handle)) Dart_PropagateError(handle);'),
        new c.Code('return handle;')
      ])));

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
        var nullptr = _defaultValue(constructor.parameters[i++].type)?.code;
        var dart = constructor.parameters.firstWhere((pp) => pp.name == p.name);
        return (dart.isNotOptional || nullptr == null)
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
      var packagePath = element.library.librarySource.uri
          .toString()
          .replaceAll(new RegExp(r'^asset:'), 'package:');

      body.addAll([
        new c.Code('Dart_Handle arguments[${constructor.parameters.length}];'),
        new c.Code('int argLen = $requiredCount;'),
        new c.Code(
            'Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("$packagePath"));'),
        new c.Code(
            'Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("${element.name}"));'),
      ]);

      _readParameters(constructor.parameters, body);

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

      impl.body.add(_maybeApplyTemplate(
          new Method(namespace.name, _ctype, name, returnType: returnType)
            ..parameters.addAll(implParams)
            ..body.addAll(body)));
    }

    // Finally, methods.
    for (var method in element.methods) {
      var headerParams = method.parameters.map(_convertParameter);
      var implParams =
          method.parameters.map((p) => _convertParameter(p, true)).toList();
      var requiredCount =
          method.parameters.where((p) => p.isNotOptional).length;

      int i = 0;
      var sigParams = headerParams.map((p) {
        var nullptr = _defaultValue(method.parameters[i++].type)?.code;
        var dart = method.parameters.firstWhere((pp) => pp.name == p.name);
        return (dart.isNotOptional || nullptr == null)
            ? p
            : new c.Parameter(p.type, '${p.name} = $nullptr');
      });

      // Add signature
      c.CType returnType;

      try {
        returnType = _convertParameterType(method.returnType);
      } catch (_) {
        returnType = _dartHandle;
      }

      if (method.returnType.isVoid) returnType = c.CType.void$;

      var methodName = method.name;
      if (method.isOperator) methodName = 'operator${method.name}';
      if (methodName == 'operator[]=') {
        // C++ doesn't support this operator, so we patch in a fake "setAt"
        methodName = 'setAt';
      }

      if (const ['public', 'private', 'struct', 'typedef', 'union']
          .contains(methodName)) methodName += '\$';

      c.Code sig = new c.FunctionSignature(returnType, methodName)
        ..parameters.addAll(sigParams);

      if (method.typeParameters.isNotEmpty) {
        sig = new Template(sig)
          ..arguments.addAll(method.typeParameters
              .where(
                  (p) => !element.typeParameters.any((pp) => pp.name == p.name))
              .map((p) => new TemplateArgument.typename(p.name)));
      }

      _public.body.add(sig);

      // Next, generate a function.
      try {
        returnType = _convertParameterType(method.returnType, true);
      } catch (_) {
        returnType = _dartHandle;
      }

      if (method.returnType.isVoid) returnType = c.CType.void$;

      var m = new Method(namespace.name, _ctype, method.name,
          returnType: returnType)
        ..parameters.addAll(implParams);

      /*
      Something like:
      Dart_Handle args[totalCount];
      int argLen = <requiredCount>;

      foreach (p...) {
        args[i] = p;
      }

      return Dart_Invoke(handle, Dart_NewStringFromCString(""), args, argLen);
      */
      m.body.addAll([
        new c.Code('Dart_Handle arguments[${method.parameters.length}];'),
        new c.Code('int argLen = $requiredCount;'),
      ]);

      _readParameters(method.parameters, m.body);

      var invocation = new c.Expression(
          'Dart_Invoke(handle, Dart_NewStringFromCString("${method.name}"), argLen, arguments)');
      if (!method.returnType.isVoid) {
        var retVal = _readReturn(invocation, method.returnType, m.body);

        if (m.returnType.code.endsWith('&')) {
          var outType =
              new c.CType(m.returnType.code.replaceAll(new RegExp(r'&$'), ''));
          m.body
              .add(new c.Expression('${outType.code} retVal').invoke([retVal]));
          retVal = new c.Expression('std::move(retVal)');
        }

        m.body.add(retVal.asReturn());
      } else {
        m.body.add(new c.Expression('handleError').invoke([invocation]));
      }
      impl.body.add(m);
    }

    // Generate getters, setters for fields.
    for (var field in element.fields) {
      // TODO: String, int, bool, null, Lists, Maps

      var outType = _convertParameterType(
          field.type); //reference(new c.CType(field.type.name));
      var namespaced = _convertParameterType(
          field.type, true); //namespacedType(namespace, outType);
      var setterNamespaced = namespaced;

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

        var retVal = _readReturn(rawHandle, field.type, m.body);

        if (outType.code.endsWith('&')) {
          var outType =
              new c.CType(m.returnType.code.replaceAll(new RegExp(r'&$'), ''));
          m.body
              .add(new c.Expression('${outType.code} retVal').invoke([retVal]));
          retVal = new c.Expression('std::move(retVal)');
        }

        // Ultimately, return something..
        m.body.add(retVal.asReturn());

        impl.body.add(_maybeApplyTemplate(m));
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
        } else if (setterNamespaced.code == 'Dart_Handle') {
          setVal = new c.Expression('value');
        }

        impl.body.add(_maybeApplyTemplate(m
          ..body.add(new c.Code(
              'handleError(Dart_SetField(handle, Dart_NewStringFromCString("${field.name}"), ${setVal.code}));'))));
      }
    }
  }

  void _genConstructor() {
    impl.body.add(_maybeApplyTemplate(
        new Method(namespace.name, _ctype, _clazz.name)
          ..parameters.add(new c.Parameter(_dartHandle, 'handle'))
          ..body.add(new c.Code('this->handle = handle;'))));
  }

  void _genGetHandle() {
    // const Dart_Handle getHandle() const;
    var sig = new c.FunctionSignature(_dartHandle, 'getHandle');
    _public.body.add(new ConstSignature(sig));
    impl.body.add(_maybeApplyTemplate(new Method(
        namespace.name, _ctype, 'getHandle',
        isConst: true, returnType: _dartHandle)
      ..body.add(new c.Code('return handle;'))));
  }

  c.Code _maybeApplyTemplate(Method m) {
    if (_tmplArgs?.isNotEmpty != true && element.typeParameters.isEmpty) {
      return m;
    } else {
      if (element.typeParameters.isNotEmpty) {
        var tmpl = '<${element.typeParameters.map((p) => p.name).join(', ')}>';
        m.clazz = new c.CType('${m.clazz.code}$tmpl');
      }

      return new Template(m)..arguments.addAll(_tmplArgs);
    }
  }
}
