#include "foo.delegate.h"
 
Dart_Handle dart_cpp_binding_generator_new_foo() {
  Dart_Handle lib = Dart_RootLibrary();
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
  Dart_Handle arguments[0];
  return Dart_New(clazz, Dart_NewStringFromCString(""), 0, arguments);
}
 
Dart_Handle dart_cpp_binding_generator_new_foo_bar(Dart_Handle abc) {
  Dart_Handle lib = Dart_RootLibrary();
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
  Dart_Handle arguments[1];
  arguments[0] = abc;
  return Dart_New(clazz, Dart_NewStringFromCString("bar"), 1, arguments);
}
 
Dart_Handle dart_cpp_binding_generator_foo_get_baz(Dart_Handle instance) {
  return Dart_GetField(instance, Dart_NewStringFromCString("baz"));
}
 
void dart_cpp_binding_generator_foo_set_baz(Dart_Handle instance, Dart_Handle value) {
  Dart_SetField(instance, Dart_NewStringFromCString("baz"), value);
}
 
Dart_Handle dart_cpp_binding_generator_foo_invoke_quux(Dart_Handle instance) {
  Dart_Handle arguments[0];
  return Dart_Invoke(instance, Dart_NewStringFromCString("quux"), 0, arguments);
}
 
Dart_Handle dart_cpp_binding_generator_foo_invoke_add_to_quux(Dart_Handle instance, Dart_Handle x) {
  Dart_Handle arguments[1];
  arguments[0] = x;
  return Dart_Invoke(instance, Dart_NewStringFromCString("addToQuux"), 1, arguments);
}
 