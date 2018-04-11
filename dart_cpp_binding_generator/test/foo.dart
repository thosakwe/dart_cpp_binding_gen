import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';

@binding
class Foo {
  Foo();

  /// Named constructor!!!
  Foo.bar(this.baz);

  int baz;

  void quux() {
    print('Current baz: $baz');
  }

  /// Add [x] to `baz`.
  int addToBar(int x) {
    print('baz + x = ${baz + x}');
    return baz + x;
  }
}
