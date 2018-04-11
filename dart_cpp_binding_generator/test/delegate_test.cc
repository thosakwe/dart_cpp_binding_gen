#include "delegate_test.h"
 
Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool* auto_setup_scope) {
  if (!Dart_IsString(name)) return NULL;
  Dart_NativeFunction result = NULL;
  const char* cname;
  Dart_Handle stringHandle = (Dart_StringToCString(name, &cname));
  if (Dart_IsError(stringHandle)) Dart_PropagateError(stringHandle);
  if (strcmp("getBazFrom", cname) == 0) result = dart_cpp_binding_generator_extension_get_baz_from;
  if (strcmp("setBazTo", cname) == 0) result = dart_cpp_binding_generator_extension_set_baz_to;
  if (strcmp("addToBaz", cname) == 0) result = dart_cpp_binding_generator_extension_add_to_baz;
  return result;
}
 
DART_EXPORT Dart_Handle delegate_test_Init(Dart_Handle parent_library) {
  if (Dart_IsError(parent_library)) return parent_library;
  Dart_Handle result_code =
          Dart_SetNativeResolver(parent_library, ResolveName, NULL);
  if (Dart_IsError(result_code)) return result_code;
  return Dart_Null();
}
 