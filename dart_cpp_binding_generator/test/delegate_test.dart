@extension
library delegate_test;

import 'dart-ext:delegate_test';
import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';
import 'package:test/test.dart';
import 'foo.dart';

main() {
  test('invoke method', () {
    var foo = new Foo()
      ..baz = 24;
    expect(getBazFrom(foo), foo.baz);
  });
}

int getBazFrom(Foo foo) native "getBazFrom";