import 'package:c_builder/c_builder.dart';
import 'package:code_buffer/code_buffer.dart';

class Namespace implements Code {
  final List<Code> body = [];

  final String name;

  Namespace(this.name);

  @override
  String get code {
    var b = new CodeBuffer();
    generate(b);
    return b.toString();
  }

  @override
  void generate(CodeBuffer buffer) {
    buffer
      ..writeln('namespace $name {')
      ..indent();
    body.forEach((c) => c.generate(buffer));
    buffer
      ..outdent()
      ..writeln('}');
  }
}

class Class implements Code {
  final List<Code> body = [];

  final String name;

  Class(this.name);

  @override
  String get code {
    var b = new CodeBuffer();
    generate(b);
    return b.toString();
  }

  @override
  void generate(CodeBuffer buffer) {
    buffer
      ..writeln('class $name {')
      ..indent();
    body.forEach((c) => c.generate(buffer));
    buffer
      ..outdent()
      ..writeln('};');
  }
}

class MemberSection implements Code {
  final String access;
  final List<Code> body = [];

  MemberSection(this.access);

  @override
  String get code {
    var b = new CodeBuffer();
    generate(b);
    return b.toString();
  }

  @override
  void generate(CodeBuffer buffer) {
    buffer
      ..writeln('$access:')
      ..indent();
    body.forEach((c) => c.generate(buffer));
    buffer.outdent();
  }
}

CType reference(CType other) =>
    other.code.trim().endsWith('&') ? other : new CType('${other.code}&');

CType namespacedType(Namespace namespace, CType other) =>
    new CType('${namespace.name}::${other.code}');

class Method implements Code {
  final String namespace;
  final CType clazz;
  final String name;
  final bool isConst;
  final List<Parameter> parameters = [];
  final List<Code> body = [];
  final CType returnType;

  Method(this.namespace, this.clazz, this.name,
      {this.isConst: false, this.returnType});

  @override
  String get code {
    var b = new CodeBuffer();
    generate(b);
    return b.toString();
  }

  @override
  void generate(CodeBuffer buffer) {
    if (returnType != null) buffer.write('${returnType.code} ');
    buffer..write('$namespace::${clazz.code.trim()}::$name');
    buffer.write('(');

    for (int i = 0; i < parameters.length; i++) {
      if (i > 0) buffer.write(', ');
      buffer.write(parameters[i]);
    }

    buffer.write(')');
    
    if (isConst) buffer.write(' const');
    buffer
      ..writeln(' {')
      ..indent();
    body.forEach((c) => c.generate(buffer));
    buffer
      ..outdent()
      ..writeln('}');
  }
}

class ConstSignature implements Code {
  final FunctionSignature sig;

  ConstSignature(this.sig);

  @override
  String get code {
    var b = new CodeBuffer();
    generate(b);
    return b.toString();
  }

  @override
  void generate(CodeBuffer buffer) {
    buffer.writeln('${sig.signature} const;');
  }
}
