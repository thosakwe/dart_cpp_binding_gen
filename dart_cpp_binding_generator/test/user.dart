import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';

@binding
class User {
  final Status status;

  User(this.status);
}

@binding
class Status {
  final String text;

  Status(this.text);
}