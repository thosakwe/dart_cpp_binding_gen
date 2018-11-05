#include "foo.g.hpp"
 
Dart_Handle cpp_binding_generator::Foo::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Foo::Foo(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Foo::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Foo::Foo() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:cpp_binding_generator/test/foo.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
cpp_binding_generator::Foo cpp_binding_generator::Foo::bar(int64_t baz) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:cpp_binding_generator/test/foo.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
  arguments[0] = Dart_NewInteger(baz);
  return Dart_New(clazz, Dart_NewStringFromCString("bar"), argLen, arguments);
}
 
void cpp_binding_generator::Foo::quux() {
  Dart_Handle arguments[0];
  int argLen = 0;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("quux"), argLen, arguments));
}
 
int64_t cpp_binding_generator::Foo::addToBar(int64_t x) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(x);
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("addToBar"), argLen, arguments);
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
int64_t cpp_binding_generator::Foo::getBaz() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("baz"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
void cpp_binding_generator::Foo::setBaz(int64_t value) {
  handleError(Dart_SetField(handle, Dart_NewStringFromCString("baz"), Dart_NewInteger(value)));
}
 