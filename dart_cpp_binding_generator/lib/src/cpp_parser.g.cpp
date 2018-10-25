#include "cpp_parser.g.hpp"
 
dart_cpp_binding_generator::CppParser::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::CppParser::CppParser(const Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::CppParser::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::CppParser::CppParser() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("CppParser"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
dart_cpp_binding_generator::List& dart_cpp_binding_generator::CppParser::getFunctions() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("functions"));
}
 
dart_cpp_binding_generator::CppFunction::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::CppFunction::CppFunction(const Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::CppFunction::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::CppFunction::CppFunction(const std::string& name) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("CppFunction"));
  arguments[0] = Dart_NewStringFromCString(name.c_str());
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
std::string dart_cpp_binding_generator::CppFunction::getName() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("name"));
  const char *value;
  handleError(Dart_String_ToCString(rawHandle, &value))
  return value;
}
 
dart_cpp_binding_generator::List& dart_cpp_binding_generator::CppFunction::getArguments() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("arguments"));
}
 
dart_cpp_binding_generator::CppArgument::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::CppArgument::CppArgument(const Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::CppArgument::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::CppArgument::CppArgument(const std::string& name, const std::string& type) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("CppArgument"));
  arguments[0] = Dart_NewStringFromCString(name.c_str());
  arguments[1] = Dart_NewStringFromCString(type.c_str());
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
std::string dart_cpp_binding_generator::CppArgument::getName() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("name"));
  const char *value;
  handleError(Dart_String_ToCString(rawHandle, &value))
  return value;
}
 
std::string dart_cpp_binding_generator::CppArgument::getType() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("type"));
  const char *value;
  handleError(Dart_String_ToCString(rawHandle, &value))
  return value;
}
 