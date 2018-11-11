#ifndef CPP_BINDING_GENERATOR_DELEGATE_TEST_DART_EXTENSION_H
 
#define CPP_BINDING_GENERATOR_DELEGATE_TEST_DART_EXTENSION_H
 
#include <string>
 
#include <dart_api.h>
 
Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool* auto_setup_scope);
 
DART_EXPORT Dart_Handle delegate_test_Init(Dart_Handle parent_library);
 
void cpp_binding_generator_extension_newFooWithX(Dart_NativeArguments arguments);
 
void cpp_binding_generator_extension_getBazFrom(Dart_NativeArguments arguments);
 
void cpp_binding_generator_extension_setBazTo(Dart_NativeArguments arguments);
 
void cpp_binding_generator_extension_addToBaz(Dart_NativeArguments arguments);
 
#endif
 