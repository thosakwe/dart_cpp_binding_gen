@extension
library delegate_test;

import 'dart-ext:delegate_test';
import 'package:dart_cpp_binding_annotation/dart_cpp_binding_annotation.dart';
import 'package:test/test.dart';
import 'foo.dart';

main() {
  test('getter method', () {
    var foo = new Foo()..baz = 24;
    expect(getBazFrom(foo), foo.baz);
  });

  test('setter method', () {
    var foo = new Foo();
    setBazTo(foo, 46);
    expect(foo.baz, 46);
  });

  test('invoke method', () {
    var foo = new Foo()..baz = 34;
    expect(addToBaz(foo, 12), foo.addToBar(12));
  });
}

int getBazFrom(Foo foo) native "getBazFrom";

void setBazTo(Foo foo, int value) native "setBazTo";

int addToBaz(Foo foo, int value) native "addToBaz";
