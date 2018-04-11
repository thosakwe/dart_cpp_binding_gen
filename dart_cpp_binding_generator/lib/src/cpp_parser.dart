import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';

@binding
class CppParser {
  final List<CppFunction> functions = [];
}

@binding
class CppFunction {
  final String name;
  final List<CppArgument> arguments = [];

  CppFunction(this.name);
}

@binding
class CppArgument {
  final String name;
  final String type;

  CppArgument(this.name, this.type);
}
