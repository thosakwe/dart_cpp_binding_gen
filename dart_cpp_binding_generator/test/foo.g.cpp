#include "foo.g.hpp"
 
Dart_Handle dart_cpp_binding_generator::Foo::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Foo::Foo(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Foo::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Foo::Foo() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/test/foo.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
dart_cpp_binding_generator::Foo dart_cpp_binding_generator::Foo::bar(int64_t baz) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/test/foo.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
  arguments[0] = Dart_NewInteger(baz);
  return Dart_New(clazz, Dart_NewStringFromCString("bar"), argLen, arguments);
}
 
int64_t dart_cpp_binding_generator::Foo::getBaz() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("baz"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
void dart_cpp_binding_generator::Foo::setBaz(int64_t value) {
  Dart_SetField(handle, Dart_NewStringFromCString("baz"), Dart_NewInteger(value));
}
 