#include "user.g.hpp"
 
Dart_Handle cpp_binding_generator::User::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::User::User(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::User::getHandle() const {
  return handle;
}
 
cpp_binding_generator::User::User(cpp_binding_generator::Status& status) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:cpp_binding_generator/test/user.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("User"));
  arguments[0] = status.getHandle();
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
cpp_binding_generator::Status& cpp_binding_generator::User::fakeStatus(int64_t n) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(n);
  cpp_binding_generator::Status retVal(Dart_Invoke(handle, Dart_NewStringFromCString("fakeStatus"), argLen, arguments));
  return std::move(retVal);
}
 
int64_t cpp_binding_generator::User::multiply(int64_t x, int64_t loop) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(x);
  if (loop != 0) {
    argLen++;
    arguments[1] = Dart_NewInteger(loop);
  }
  else {
    arguments[1] = Dart_Null();
  }
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("multiply"), argLen, arguments);
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
void cpp_binding_generator::User::sayHi() {
  Dart_Handle arguments[0];
  int argLen = 0;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("sayHi"), argLen, arguments));
}
 
cpp_binding_generator::Status& cpp_binding_generator::User::getStatus() const {
  cpp_binding_generator::Status retVal(Dart_GetField(handle, Dart_NewStringFromCString("status")));
  return std::move(retVal);
}
 
Dart_Handle cpp_binding_generator::Status::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Status::Status(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Status::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Status::Status(const std::string& text) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:cpp_binding_generator/test/user.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Status"));
  arguments[0] = Dart_NewStringFromCString(text.c_str());
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
std::string cpp_binding_generator::Status::getText() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("text"));
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  return value;
}
 