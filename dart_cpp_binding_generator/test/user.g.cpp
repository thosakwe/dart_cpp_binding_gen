#include "user.g.hpp"
 
Dart_Handle dart_cpp_binding_generator::User::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::User::User(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::User::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::User::User(dart_cpp_binding_generator::Status& status) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/test/user.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("User"));
  arguments[0] = status.getHandle();
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
dart_cpp_binding_generator::Status& dart_cpp_binding_generator::User::getStatus() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("status"));
}
 
Dart_Handle dart_cpp_binding_generator::Status::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Status::Status(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Status::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Status::Status(const std::string& text) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/test/user.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Status"));
  arguments[0] = Dart_NewStringFromCString(text.c_str());
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
std::string dart_cpp_binding_generator::Status::getText() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("text"));
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  return value;
}
 