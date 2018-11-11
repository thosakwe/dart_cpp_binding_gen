#include "cpp_parser.delegate.h"
 
Dart_Handle dart_cpp_binding_generator_new_cpp_parser() {
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("CppParser"));
  Dart_Handle arguments[0];
  return Dart_New(clazz, Dart_NewStringFromCString(""), 0, arguments);
}
 
Dart_Handle dart_cpp_binding_generator_cpp_parser_get_functions(Dart_Handle instance) {
  return Dart_GetField(instance, Dart_NewStringFromCString("functions"));
}
 
Dart_Handle dart_cpp_binding_generator_new_cpp_function(Dart_Handle name) {
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("CppFunction"));
  Dart_Handle arguments[1];
  arguments[0] = name;
  return Dart_New(clazz, Dart_NewStringFromCString(""), 1, arguments);
}
 
Dart_Handle dart_cpp_binding_generator_cpp_function_get_name(Dart_Handle instance) {
  return Dart_GetField(instance, Dart_NewStringFromCString("name"));
}
 
Dart_Handle dart_cpp_binding_generator_cpp_function_get_arguments(Dart_Handle instance) {
  return Dart_GetField(instance, Dart_NewStringFromCString("arguments"));
}
 
Dart_Handle dart_cpp_binding_generator_new_cpp_argument(Dart_Handle name, Dart_Handle type) {
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("CppArgument"));
  Dart_Handle arguments[2];
  arguments[0] = name;
  arguments[1] = type;
  return Dart_New(clazz, Dart_NewStringFromCString(""), 2, arguments);
}
 
Dart_Handle dart_cpp_binding_generator_cpp_argument_get_name(Dart_Handle instance) {
  return Dart_GetField(instance, Dart_NewStringFromCString("name"));
}
 
Dart_Handle dart_cpp_binding_generator_cpp_argument_get_type(Dart_Handle instance) {
  return Dart_GetField(instance, Dart_NewStringFromCString("type"));
}
 