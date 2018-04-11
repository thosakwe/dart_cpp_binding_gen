#ifndef DART_CPP_BINDING_GENERATOR_DELEGATE_TEST_DART_EXTENSION_H
 
#define DART_CPP_BINDING_GENERATOR_DELEGATE_TEST_DART_EXTENSION_H
 
#include <string.h>
 
#include <dart_api.h>
 
Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool* auto_setup_scope);
 
DART_EXPORT Dart_Handle delegate_test_Init(Dart_Handle parent_library);
 
void dart_cpp_binding_generator_extension_get_baz_from(Dart_NativeArguments arguments);
 
#endif
 