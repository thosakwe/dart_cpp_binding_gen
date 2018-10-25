import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';

@binding
class Chat {
  final messages = <Message>[];

  int get messageCount => messages.length;

  void printInfo() {
    print('message(s): $messageCount');
  }
}

@binding
class Message {
  final String text;

  Message({this.text});
}
