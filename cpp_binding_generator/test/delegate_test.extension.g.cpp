#include "delegate_test.extension.g.hpp"
 
Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool* auto_setup_scope) {
  if (!Dart_IsString(name)) return NULL;
  Dart_NativeFunction result = NULL;
  const char* cname;
  Dart_Handle stringHandle = (Dart_StringToCString(name, &cname));
  if (Dart_IsError(stringHandle)) Dart_PropagateError(stringHandle);
  if (strcmp("newFooWithX", cname) == 0) result = cpp_binding_generator_extension_newFooWithX;
  if (strcmp("getBazFrom", cname) == 0) result = cpp_binding_generator_extension_getBazFrom;
  if (strcmp("setBazTo", cname) == 0) result = cpp_binding_generator_extension_setBazTo;
  if (strcmp("addToBaz", cname) == 0) result = cpp_binding_generator_extension_addToBaz;
  return result;
}
 
DART_EXPORT Dart_Handle delegate_test_Init(Dart_Handle parent_library) {
  if (Dart_IsError(parent_library)) return parent_library;
  Dart_Handle result_code =
          Dart_SetNativeResolver(parent_library, ResolveName, NULL);
  if (Dart_IsError(result_code)) return result_code;
  return Dart_Null();
}
 