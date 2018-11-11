#include "cpp_parser.g.hpp"
 
Dart_Handle cpp_binding_generator::Chat::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Chat::Chat(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Chat::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Chat::Chat() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Chat"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
void cpp_binding_generator::Chat::printInfo() {
  Dart_Handle arguments[0];
  int argLen = 0;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("printInfo"), argLen, arguments));
}
 
Dart_Handle cpp_binding_generator::Chat::getMessages() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("messages"));
}
 
int64_t cpp_binding_generator::Chat::getMessageCount() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("messageCount"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
Dart_Handle cpp_binding_generator::Message::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Message::Message(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Message::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Message::Message(const std::string& text) {
  Dart_Handle arguments[1];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Message"));
  if (text != "") {
    argLen++;
    arguments[0] = Dart_NewStringFromCString(text.c_str());
  }
  else {
    arguments[0] = Dart_Null();
  }
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
std::string cpp_binding_generator::Message::getText() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("text"));
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  return value;
}
 