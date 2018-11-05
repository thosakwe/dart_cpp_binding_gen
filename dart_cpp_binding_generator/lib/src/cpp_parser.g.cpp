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
 
template < typename E >
Dart_Handle cpp_binding_generator::List<E>::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template < typename E >
cpp_binding_generator::List<E>::List(Dart_Handle handle) {
  this->handle = handle;
}
 
template < typename E >
Dart_Handle cpp_binding_generator::List<E>::getHandle() const {
  return handle;
}
 
template < typename E >
cpp_binding_generator::List<E>::List(int64_t length) {
  Dart_Handle arguments[1];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("List"));
  if (length != 0) {
    argLen++;
    arguments[0] = Dart_NewInteger(length);
  }
  else {
    arguments[0] = Dart_Null();
  }
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::List cpp_binding_generator::List<E>::filled(int64_t length, E fill, bool growable) {
  Dart_Handle arguments[3];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("List"));
  arguments[0] = Dart_NewInteger(length);
  arguments[1] = fill.getHandle();
  if (growable) {
    argLen++;
    arguments[2] = Dart_NewBoolean(growable);
  }
  else {
    arguments[2] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("filled"), argLen, arguments);
}
 
template < typename E >
Dart_Handle cpp_binding_generator::Iterable<E>::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template < typename E >
cpp_binding_generator::Iterable<E>::Iterable(Dart_Handle handle) {
  this->handle = handle;
}
 
template < typename E >
Dart_Handle cpp_binding_generator::Iterable<E>::getHandle() const {
  return handle;
}
 
template < typename E >
cpp_binding_generator::Iterable<E>::Iterable() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterable"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::Iterable cpp_binding_generator::Iterable<E>::generate(int64_t count, Dart_Handle generator) {
  Dart_Handle arguments[2];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterable"));
  arguments[0] = Dart_NewInteger(count);
  if (!Dart_IdentityEquals(generator.getHandle(), Dart_Null())) {
    argLen++;
    arguments[1] = generator;
  }
  else {
    arguments[1] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("generate"), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::Iterable cpp_binding_generator::Iterable<E>::empty() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterable"));
  return Dart_New(clazz, Dart_NewStringFromCString("empty"), argLen, arguments);
}
 
cpp_binding_generator::Iterable< T >& cpp_binding_generator::Iterable::castFrom(cpp_binding_generator::Iterable< S >& source) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = source.getHandle();
  cpp_binding_generator::Iterable< T > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("castFrom"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< R >& cpp_binding_generator::Iterable::cast() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::Iterable< R > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("cast"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< E >& cpp_binding_generator::Iterable::followedBy(cpp_binding_generator::Iterable< E >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other.getHandle();
  cpp_binding_generator::Iterable< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("followedBy"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< T >& cpp_binding_generator::Iterable::map(Dart_Handle f) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = f;
  cpp_binding_generator::Iterable< T > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("map"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< E >& cpp_binding_generator::Iterable::where(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  cpp_binding_generator::Iterable< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("where"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< T >& cpp_binding_generator::Iterable::whereType() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::Iterable< T > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("whereType"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< T >& cpp_binding_generator::Iterable::expand(Dart_Handle f) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = f;
  cpp_binding_generator::Iterable< T > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("expand"), argLen, arguments));
  return std::move(retVal);
}
 
Dart_Handle cpp_binding_generator::Object::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Object::Object(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Object::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Object::Object() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Object"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
bool cpp_binding_generator::Object::==(Dart_Handle other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("=="), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
const std::string& cpp_binding_generator::Object::toString() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("toString"), argLen, arguments);
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  const std::string retVal(value);
  return std::move(retVal);
}
 
Dart_Handle cpp_binding_generator::Invocation::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Invocation::Invocation(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Invocation::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Invocation::Invocation() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
Dart_Handle cpp_binding_generator::Symbol::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Symbol::Symbol(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Symbol::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Symbol::Symbol(const std::string& name) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Symbol"));
  arguments[0] = Dart_NewStringFromCString(name.c_str());
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
bool cpp_binding_generator::Symbol::==(Dart_Handle other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("=="), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
cpp_binding_generator::Symbol& cpp_binding_generator::Symbol::getUnaryMinus() const {
  cpp_binding_generator::Symbol retVal(Dart_GetField(handle, Dart_NewStringFromCString("unaryMinus")));
  return std::move(retVal);
}
 
cpp_binding_generator::Symbol& cpp_binding_generator::Symbol::getEmpty() const {
  cpp_binding_generator::Symbol retVal(Dart_GetField(handle, Dart_NewStringFromCString("empty")));
  return std::move(retVal);
}
 
int64_t cpp_binding_generator::Symbol::getHashCode() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("hashCode"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template < typename K, typename V >
Dart_Handle cpp_binding_generator::Map<K, V>::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template < typename K, typename V >
cpp_binding_generator::Map<K, V>::Map(Dart_Handle handle) {
  this->handle = handle;
}
 
template < typename K, typename V >
Dart_Handle cpp_binding_generator::Map<K, V>::getHandle() const {
  return handle;
}
 
template < typename K, typename V >
cpp_binding_generator::Map<K, V>::Map() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template < typename K, typename V >
cpp_binding_generator::Map cpp_binding_generator::Map<K, V>::from(cpp_binding_generator::Map< Dart_Handle, Dart_Handle >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = other.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("from"), argLen, arguments);
}
 
template < typename K, typename V >
cpp_binding_generator::Map cpp_binding_generator::Map<K, V>::of(cpp_binding_generator::Map< K, V >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = other.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("of"), argLen, arguments);
}
 
template < typename K, typename V >
cpp_binding_generator::Map cpp_binding_generator::Map<K, V>::unmodifiable(cpp_binding_generator::Map< Dart_Handle, Dart_Handle >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = other.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("unmodifiable"), argLen, arguments);
}
 
template < typename K, typename V >
cpp_binding_generator::Map cpp_binding_generator::Map<K, V>::identity() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  return Dart_New(clazz, Dart_NewStringFromCString("identity"), argLen, arguments);
}
 
template < typename K, typename V >
cpp_binding_generator::Map cpp_binding_generator::Map<K, V>::fromIterable(cpp_binding_generator::Iterable< Dart_Handle >& iterable, Dart_Handle key, Dart_Handle value) {
  Dart_Handle arguments[3];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = iterable.getHandle();
  if (!Dart_IdentityEquals(key.getHandle(), Dart_Null())) {
    argLen++;
    arguments[1] = key;
  }
  else {
    arguments[1] = Dart_Null();
  }
  if (!Dart_IdentityEquals(value.getHandle(), Dart_Null())) {
    argLen++;
    arguments[2] = value;
  }
  else {
    arguments[2] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("fromIterable"), argLen, arguments);
}
 
template < typename K, typename V >
cpp_binding_generator::Map cpp_binding_generator::Map<K, V>::fromIterables(cpp_binding_generator::Iterable< K >& keys, cpp_binding_generator::Iterable< V >& values) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = keys.getHandle();
  arguments[1] = values.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("fromIterables"), argLen, arguments);
}
 
template < typename K, typename V >
Dart_Handle cpp_binding_generator::MapEntry<K, V>::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template < typename K, typename V >
cpp_binding_generator::MapEntry<K, V>::MapEntry(Dart_Handle handle) {
  this->handle = handle;
}
 
template < typename K, typename V >
Dart_Handle cpp_binding_generator::MapEntry<K, V>::getHandle() const {
  return handle;
}
 
template < typename K, typename V >
cpp_binding_generator::MapEntry<K, V>::MapEntry(K key, V value) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("MapEntry"));
  arguments[0] = key.getHandle();
  arguments[1] = value.getHandle();
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template < typename K, typename V >
cpp_binding_generator::MapEntry cpp_binding_generator::MapEntry<K, V>::_(K key, V value) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("MapEntry"));
  arguments[0] = key.getHandle();
  arguments[1] = value.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("_"), argLen, arguments);
}
 
const std::string& cpp_binding_generator::MapEntry::toString() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("toString"), argLen, arguments);
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  const std::string retVal(value);
  return std::move(retVal);
}
 
template < typename K, typename V >
K cpp_binding_generator::MapEntry<K, V>::getKey() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("key"));
}
 
template < typename K, typename V >
V cpp_binding_generator::MapEntry<K, V>::getValue() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("value"));
}
 
template < typename K, typename V >
cpp_binding_generator::Map cpp_binding_generator::Map<K, V>::fromEntries(cpp_binding_generator::Iterable< cpp_binding_generator::MapEntry< K, V >& >& entries) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = entries.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("fromEntries"), argLen, arguments);
}
 
cpp_binding_generator::Map< K2, V2 >& cpp_binding_generator::Map::castFrom(cpp_binding_generator::Map< K, V >& source) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = source.getHandle();
  cpp_binding_generator::Map< K2, V2 > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("castFrom"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Map< RK, RV >& cpp_binding_generator::Map::cast() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::Map< RK, RV > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("cast"), argLen, arguments));
  return std::move(retVal);
}
 
bool cpp_binding_generator::Map::containsValue(cpp_binding_generator::Object& value) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = value.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("containsValue"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool cpp_binding_generator::Map::containsKey(cpp_binding_generator::Object& key) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = key.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("containsKey"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
V cpp_binding_generator::Map::[](cpp_binding_generator::Object& key) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = key.getHandle();
  return Dart_Invoke(handle, Dart_NewStringFromCString("[]"), argLen, arguments);
}
 
void cpp_binding_generator::Map::[]=(K key, V value) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = key.getHandle();
  arguments[1] = value.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("[]="), argLen, arguments));
}
 
cpp_binding_generator::Map< K2, V2 >& cpp_binding_generator::Map::map(Dart_Handle f) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = f;
  cpp_binding_generator::Map< K2, V2 > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("map"), argLen, arguments));
  return std::move(retVal);
}
 
void cpp_binding_generator::Map::addEntries(cpp_binding_generator::Iterable< cpp_binding_generator::MapEntry< K, V >& >& newEntries) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = newEntries.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("addEntries"), argLen, arguments));
}
 
V cpp_binding_generator::Map::update(K key, Dart_Handle update, Dart_Handle ifAbsent) {
  Dart_Handle arguments[3];
  int argLen = 2;
  arguments[0] = key.getHandle();
  arguments[1] = update;
  if (!Dart_IdentityEquals(ifAbsent.getHandle(), Dart_Null())) {
    argLen++;
    arguments[2] = ifAbsent;
  }
  else {
    arguments[2] = Dart_Null();
  }
  return Dart_Invoke(handle, Dart_NewStringFromCString("update"), argLen, arguments);
}
 
void cpp_binding_generator::Map::updateAll(Dart_Handle update) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = update;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("updateAll"), argLen, arguments));
}
 
void cpp_binding_generator::Map::removeWhere(Dart_Handle predicate) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = predicate;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("removeWhere"), argLen, arguments));
}
 
V cpp_binding_generator::Map::putIfAbsent(K key, Dart_Handle ifAbsent) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = key.getHandle();
  arguments[1] = ifAbsent;
  return Dart_Invoke(handle, Dart_NewStringFromCString("putIfAbsent"), argLen, arguments);
}
 
void cpp_binding_generator::Map::addAll(cpp_binding_generator::Map< K, V >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("addAll"), argLen, arguments));
}
 
V cpp_binding_generator::Map::remove(cpp_binding_generator::Object& key) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = key.getHandle();
  return Dart_Invoke(handle, Dart_NewStringFromCString("remove"), argLen, arguments);
}
 
void cpp_binding_generator::Map::clear() {
  Dart_Handle arguments[0];
  int argLen = 0;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("clear"), argLen, arguments));
}
 
void cpp_binding_generator::Map::forEach(Dart_Handle f) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = f;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("forEach"), argLen, arguments));
}
 
template < typename K, typename V >
cpp_binding_generator::Iterable< cpp_binding_generator::MapEntry< K, V >& >& cpp_binding_generator::Map<K, V>::getEntries() const {
  cpp_binding_generator::Iterable< cpp_binding_generator::MapEntry< K, V >& > retVal(Dart_GetField(handle, Dart_NewStringFromCString("entries")));
  return std::move(retVal);
}
 
template < typename K, typename V >
cpp_binding_generator::Iterable< K >& cpp_binding_generator::Map<K, V>::getKeys() const {
  cpp_binding_generator::Iterable< K > retVal(Dart_GetField(handle, Dart_NewStringFromCString("keys")));
  return std::move(retVal);
}
 
template < typename K, typename V >
cpp_binding_generator::Iterable< V >& cpp_binding_generator::Map<K, V>::getValues() const {
  cpp_binding_generator::Iterable< V > retVal(Dart_GetField(handle, Dart_NewStringFromCString("values")));
  return std::move(retVal);
}
 
template < typename K, typename V >
int64_t cpp_binding_generator::Map<K, V>::getLength() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("length"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template < typename K, typename V >
bool cpp_binding_generator::Map<K, V>::getIsEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
template < typename K, typename V >
bool cpp_binding_generator::Map<K, V>::getIsNotEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isNotEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
cpp_binding_generator::Invocation cpp_binding_generator::Invocation::method(cpp_binding_generator::Symbol& memberName, cpp_binding_generator::Iterable< cpp_binding_generator::Object& >& positionalArguments, cpp_binding_generator::Map< cpp_binding_generator::Symbol&, cpp_binding_generator::Object& >& namedArguments) {
  Dart_Handle arguments[3];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = memberName.getHandle();
  arguments[1] = positionalArguments.getHandle();
  if (!Dart_IdentityEquals(namedArguments.getHandle(), Dart_Null())) {
    argLen++;
    arguments[2] = namedArguments.getHandle();
  }
  else {
    arguments[2] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("method"), argLen, arguments);
}
 
Dart_Handle cpp_binding_generator::Type::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Type::Type(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Type::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Type::Type() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Type"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
cpp_binding_generator::Invocation cpp_binding_generator::Invocation::genericMethod(cpp_binding_generator::Symbol& memberName, cpp_binding_generator::Iterable< cpp_binding_generator::Type& >& typeArguments, cpp_binding_generator::Iterable< cpp_binding_generator::Object& >& positionalArguments, cpp_binding_generator::Map< cpp_binding_generator::Symbol&, cpp_binding_generator::Object& >& namedArguments) {
  Dart_Handle arguments[4];
  int argLen = 3;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = memberName.getHandle();
  arguments[1] = typeArguments.getHandle();
  arguments[2] = positionalArguments.getHandle();
  if (!Dart_IdentityEquals(namedArguments.getHandle(), Dart_Null())) {
    argLen++;
    arguments[3] = namedArguments.getHandle();
  }
  else {
    arguments[3] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("genericMethod"), argLen, arguments);
}
 
cpp_binding_generator::Invocation cpp_binding_generator::Invocation::getter(cpp_binding_generator::Symbol& name) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = name.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("getter"), argLen, arguments);
}
 
cpp_binding_generator::Invocation cpp_binding_generator::Invocation::setter(cpp_binding_generator::Symbol& memberName, cpp_binding_generator::Object& argument) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = memberName.getHandle();
  arguments[1] = argument.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("setter"), argLen, arguments);
}
 
cpp_binding_generator::Symbol& cpp_binding_generator::Invocation::getMemberName() const {
  cpp_binding_generator::Symbol retVal(Dart_GetField(handle, Dart_NewStringFromCString("memberName")));
  return std::move(retVal);
}
 
cpp_binding_generator::List< cpp_binding_generator::Type& >& cpp_binding_generator::Invocation::getTypeArguments() const {
  cpp_binding_generator::List< cpp_binding_generator::Type& > retVal(Dart_GetField(handle, Dart_NewStringFromCString("typeArguments")));
  return std::move(retVal);
}
 
cpp_binding_generator::List< Dart_Handle >& cpp_binding_generator::Invocation::getPositionalArguments() const {
  cpp_binding_generator::List< Dart_Handle > retVal(Dart_GetField(handle, Dart_NewStringFromCString("positionalArguments")));
  return std::move(retVal);
}
 
cpp_binding_generator::Map< cpp_binding_generator::Symbol&, Dart_Handle >& cpp_binding_generator::Invocation::getNamedArguments() const {
  cpp_binding_generator::Map< cpp_binding_generator::Symbol&, Dart_Handle > retVal(Dart_GetField(handle, Dart_NewStringFromCString("namedArguments")));
  return std::move(retVal);
}
 
bool cpp_binding_generator::Invocation::getIsMethod() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isMethod"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool cpp_binding_generator::Invocation::getIsGetter() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isGetter"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool cpp_binding_generator::Invocation::getIsSetter() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isSetter"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool cpp_binding_generator::Invocation::getIsAccessor() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isAccessor"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
Dart_Handle cpp_binding_generator::Object::noSuchMethod(cpp_binding_generator::Invocation& invocation) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = invocation.getHandle();
  return Dart_Invoke(handle, Dart_NewStringFromCString("noSuchMethod"), argLen, arguments);
}
 
int64_t cpp_binding_generator::Object::getHashCode() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("hashCode"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
cpp_binding_generator::Type& cpp_binding_generator::Object::getRuntimeType() const {
  cpp_binding_generator::Type retVal(Dart_GetField(handle, Dart_NewStringFromCString("runtimeType")));
  return std::move(retVal);
}
 
bool cpp_binding_generator::Iterable::contains(cpp_binding_generator::Object& element) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = element.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("contains"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
void cpp_binding_generator::Iterable::forEach(Dart_Handle f) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = f;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("forEach"), argLen, arguments));
}
 
E cpp_binding_generator::Iterable::reduce(Dart_Handle combine) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = combine;
  return Dart_Invoke(handle, Dart_NewStringFromCString("reduce"), argLen, arguments);
}
 
T cpp_binding_generator::Iterable::fold(T initialValue, Dart_Handle combine) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = initialValue.getHandle();
  arguments[1] = combine;
  return Dart_Invoke(handle, Dart_NewStringFromCString("fold"), argLen, arguments);
}
 
bool cpp_binding_generator::Iterable::every(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("every"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
const std::string& cpp_binding_generator::Iterable::join(const std::string& separator) {
  Dart_Handle arguments[1];
  int argLen = 0;
  if (separator != "") {
    argLen++;
    arguments[0] = Dart_NewStringFromCString(separator.c_str());
  }
  else {
    arguments[0] = Dart_Null();
  }
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("join"), argLen, arguments);
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  const std::string retVal(value);
  return std::move(retVal);
}
 
bool cpp_binding_generator::Iterable::any(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("any"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
cpp_binding_generator::List< E >& cpp_binding_generator::Iterable::toList(bool growable) {
  Dart_Handle arguments[1];
  int argLen = 0;
  if (growable) {
    argLen++;
    arguments[0] = Dart_NewBoolean(growable);
  }
  else {
    arguments[0] = Dart_Null();
  }
  cpp_binding_generator::List< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("toList"), argLen, arguments));
  return std::move(retVal);
}
 
template < typename E >
Dart_Handle cpp_binding_generator::Set<E>::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template < typename E >
cpp_binding_generator::Set<E>::Set(Dart_Handle handle) {
  this->handle = handle;
}
 
template < typename E >
Dart_Handle cpp_binding_generator::Set<E>::getHandle() const {
  return handle;
}
 
template < typename E >
cpp_binding_generator::Set<E>::Set() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::Set cpp_binding_generator::Set<E>::identity() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  return Dart_New(clazz, Dart_NewStringFromCString("identity"), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::Set cpp_binding_generator::Set<E>::from(cpp_binding_generator::Iterable< Dart_Handle >& elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  arguments[0] = elements.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("from"), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::Set cpp_binding_generator::Set<E>::of(cpp_binding_generator::Iterable< E >& elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  arguments[0] = elements.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("of"), argLen, arguments);
}
 
cpp_binding_generator::Set< T >& cpp_binding_generator::Set::castFrom(cpp_binding_generator::Set< S >& source, Dart_Handle newSet) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = source.getHandle();
  if (!Dart_IdentityEquals(newSet.getHandle(), Dart_Null())) {
    argLen++;
    arguments[1] = newSet;
  }
  else {
    arguments[1] = Dart_Null();
  }
  cpp_binding_generator::Set< T > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("castFrom"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Set< R >& cpp_binding_generator::Set::cast() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::Set< R > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("cast"), argLen, arguments));
  return std::move(retVal);
}
 
bool cpp_binding_generator::Set::contains(cpp_binding_generator::Object& value) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = value.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("contains"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool cpp_binding_generator::Set::add(E value) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = value.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("add"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
void cpp_binding_generator::Set::addAll(cpp_binding_generator::Iterable< E >& elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = elements.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("addAll"), argLen, arguments));
}
 
bool cpp_binding_generator::Set::remove(cpp_binding_generator::Object& value) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = value.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("remove"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
E cpp_binding_generator::Set::lookup(cpp_binding_generator::Object& object) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = object.getHandle();
  return Dart_Invoke(handle, Dart_NewStringFromCString("lookup"), argLen, arguments);
}
 
void cpp_binding_generator::Set::removeAll(cpp_binding_generator::Iterable< cpp_binding_generator::Object& >& elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = elements.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("removeAll"), argLen, arguments));
}
 
void cpp_binding_generator::Set::retainAll(cpp_binding_generator::Iterable< cpp_binding_generator::Object& >& elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = elements.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("retainAll"), argLen, arguments));
}
 
void cpp_binding_generator::Set::removeWhere(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("removeWhere"), argLen, arguments));
}
 
void cpp_binding_generator::Set::retainWhere(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("retainWhere"), argLen, arguments));
}
 
bool cpp_binding_generator::Set::containsAll(cpp_binding_generator::Iterable< cpp_binding_generator::Object& >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("containsAll"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
cpp_binding_generator::Set< E >& cpp_binding_generator::Set::intersection(cpp_binding_generator::Set< cpp_binding_generator::Object& >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other.getHandle();
  cpp_binding_generator::Set< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("intersection"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Set< E >& cpp_binding_generator::Set::union(cpp_binding_generator::Set< E >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other.getHandle();
  cpp_binding_generator::Set< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("union"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Set< E >& cpp_binding_generator::Set::difference(cpp_binding_generator::Set< cpp_binding_generator::Object& >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other.getHandle();
  cpp_binding_generator::Set< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("difference"), argLen, arguments));
  return std::move(retVal);
}
 
void cpp_binding_generator::Set::clear() {
  Dart_Handle arguments[0];
  int argLen = 0;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("clear"), argLen, arguments));
}
 
cpp_binding_generator::Set< E >& cpp_binding_generator::Set::toSet() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::Set< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("toSet"), argLen, arguments));
  return std::move(retVal);
}
 
template < typename E >
Dart_Handle cpp_binding_generator::Iterator<E>::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template < typename E >
cpp_binding_generator::Iterator<E>::Iterator(Dart_Handle handle) {
  this->handle = handle;
}
 
template < typename E >
Dart_Handle cpp_binding_generator::Iterator<E>::getHandle() const {
  return handle;
}
 
template < typename E >
cpp_binding_generator::Iterator<E>::Iterator() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterator"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
bool cpp_binding_generator::Iterator::moveNext() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("moveNext"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
template < typename E >
E cpp_binding_generator::Iterator<E>::getCurrent() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("current"));
}
 
template < typename E >
cpp_binding_generator::Iterator< E >& cpp_binding_generator::Set<E>::getIterator() const {
  cpp_binding_generator::Iterator< E > retVal(Dart_GetField(handle, Dart_NewStringFromCString("iterator")));
  return std::move(retVal);
}
 
cpp_binding_generator::Set< E >& cpp_binding_generator::Iterable::toSet() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::Set< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("toSet"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< E >& cpp_binding_generator::Iterable::take(int64_t count) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(count);
  cpp_binding_generator::Iterable< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("take"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< E >& cpp_binding_generator::Iterable::takeWhile(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  cpp_binding_generator::Iterable< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("takeWhile"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< E >& cpp_binding_generator::Iterable::skip(int64_t count) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(count);
  cpp_binding_generator::Iterable< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("skip"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< E >& cpp_binding_generator::Iterable::skipWhile(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  cpp_binding_generator::Iterable< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("skipWhile"), argLen, arguments));
  return std::move(retVal);
}
 
E cpp_binding_generator::Iterable::firstWhere(Dart_Handle test, Dart_Handle orElse) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = test;
  if (!Dart_IdentityEquals(orElse.getHandle(), Dart_Null())) {
    argLen++;
    arguments[1] = orElse;
  }
  else {
    arguments[1] = Dart_Null();
  }
  return Dart_Invoke(handle, Dart_NewStringFromCString("firstWhere"), argLen, arguments);
}
 
E cpp_binding_generator::Iterable::lastWhere(Dart_Handle test, Dart_Handle orElse) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = test;
  if (!Dart_IdentityEquals(orElse.getHandle(), Dart_Null())) {
    argLen++;
    arguments[1] = orElse;
  }
  else {
    arguments[1] = Dart_Null();
  }
  return Dart_Invoke(handle, Dart_NewStringFromCString("lastWhere"), argLen, arguments);
}
 
E cpp_binding_generator::Iterable::singleWhere(Dart_Handle test, Dart_Handle orElse) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = test;
  if (!Dart_IdentityEquals(orElse.getHandle(), Dart_Null())) {
    argLen++;
    arguments[1] = orElse;
  }
  else {
    arguments[1] = Dart_Null();
  }
  return Dart_Invoke(handle, Dart_NewStringFromCString("singleWhere"), argLen, arguments);
}
 
E cpp_binding_generator::Iterable::elementAt(int64_t index) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(index);
  return Dart_Invoke(handle, Dart_NewStringFromCString("elementAt"), argLen, arguments);
}
 
const std::string& cpp_binding_generator::Iterable::toString() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("toString"), argLen, arguments);
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  const std::string retVal(value);
  return std::move(retVal);
}
 
template < typename E >
cpp_binding_generator::Iterator< E >& cpp_binding_generator::Iterable<E>::getIterator() const {
  cpp_binding_generator::Iterator< E > retVal(Dart_GetField(handle, Dart_NewStringFromCString("iterator")));
  return std::move(retVal);
}
 
template < typename E >
int64_t cpp_binding_generator::Iterable<E>::getLength() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("length"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template < typename E >
bool cpp_binding_generator::Iterable<E>::getIsEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
template < typename E >
bool cpp_binding_generator::Iterable<E>::getIsNotEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isNotEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
template < typename E >
E cpp_binding_generator::Iterable<E>::getFirst() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("first"));
}
 
template < typename E >
E cpp_binding_generator::Iterable<E>::getLast() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("last"));
}
 
template < typename E >
E cpp_binding_generator::Iterable<E>::getSingle() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("single"));
}
 
template < typename E >
cpp_binding_generator::List cpp_binding_generator::List<E>::from(cpp_binding_generator::Iterable< Dart_Handle >& elements, bool growable) {
  Dart_Handle arguments[2];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("List"));
  arguments[0] = elements.getHandle();
  if (growable) {
    argLen++;
    arguments[1] = Dart_NewBoolean(growable);
  }
  else {
    arguments[1] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("from"), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::List cpp_binding_generator::List<E>::of(cpp_binding_generator::Iterable< E >& elements, bool growable) {
  Dart_Handle arguments[2];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("List"));
  arguments[0] = elements.getHandle();
  if (growable) {
    argLen++;
    arguments[1] = Dart_NewBoolean(growable);
  }
  else {
    arguments[1] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("of"), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::List cpp_binding_generator::List<E>::generate(int64_t length, Dart_Handle generator, bool growable) {
  Dart_Handle arguments[3];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("List"));
  arguments[0] = Dart_NewInteger(length);
  arguments[1] = generator;
  if (growable) {
    argLen++;
    arguments[2] = Dart_NewBoolean(growable);
  }
  else {
    arguments[2] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("generate"), argLen, arguments);
}
 
template < typename E >
cpp_binding_generator::List cpp_binding_generator::List<E>::unmodifiable(cpp_binding_generator::Iterable< Dart_Handle >& elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("List"));
  arguments[0] = elements.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("unmodifiable"), argLen, arguments);
}
 
cpp_binding_generator::List< T >& cpp_binding_generator::List::castFrom(cpp_binding_generator::List< S >& source) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = source.getHandle();
  cpp_binding_generator::List< T > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("castFrom"), argLen, arguments));
  return std::move(retVal);
}
 
void cpp_binding_generator::List::copyRange(cpp_binding_generator::List< T >& target, int64_t at, cpp_binding_generator::List< T >& source, int64_t start, int64_t end) {
  Dart_Handle arguments[5];
  int argLen = 3;
  arguments[0] = target.getHandle();
  arguments[1] = Dart_NewInteger(at);
  arguments[2] = source.getHandle();
  if (start != 0) {
    argLen++;
    arguments[3] = Dart_NewInteger(start);
  }
  else {
    arguments[3] = Dart_Null();
  }
  if (end != 0) {
    argLen++;
    arguments[4] = Dart_NewInteger(end);
  }
  else {
    arguments[4] = Dart_Null();
  }
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("copyRange"), argLen, arguments));
}
 
void cpp_binding_generator::List::writeIterable(cpp_binding_generator::List< T >& target, int64_t at, cpp_binding_generator::Iterable< T >& source) {
  Dart_Handle arguments[3];
  int argLen = 3;
  arguments[0] = target.getHandle();
  arguments[1] = Dart_NewInteger(at);
  arguments[2] = source.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("writeIterable"), argLen, arguments));
}
 
cpp_binding_generator::List< R >& cpp_binding_generator::List::cast() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::List< R > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("cast"), argLen, arguments));
  return std::move(retVal);
}
 
E cpp_binding_generator::List::[](int64_t index) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(index);
  return Dart_Invoke(handle, Dart_NewStringFromCString("[]"), argLen, arguments);
}
 
void cpp_binding_generator::List::[]=(int64_t index, E value) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = Dart_NewInteger(index);
  arguments[1] = value.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("[]="), argLen, arguments));
}
 
void cpp_binding_generator::List::add(E value) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = value.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("add"), argLen, arguments));
}
 
void cpp_binding_generator::List::addAll(cpp_binding_generator::Iterable< E >& iterable) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = iterable.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("addAll"), argLen, arguments));
}
 
void cpp_binding_generator::List::sort(Dart_Handle compare) {
  Dart_Handle arguments[1];
  int argLen = 0;
  if (!Dart_IdentityEquals(compare.getHandle(), Dart_Null())) {
    argLen++;
    arguments[0] = compare;
  }
  else {
    arguments[0] = Dart_Null();
  }
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("sort"), argLen, arguments));
}
 
Dart_Handle cpp_binding_generator::Random::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
cpp_binding_generator::Random::Random(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle cpp_binding_generator::Random::getHandle() const {
  return handle;
}
 
cpp_binding_generator::Random::Random(int64_t seed) {
  Dart_Handle arguments[1];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:math"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Random"));
  if (seed != 0) {
    argLen++;
    arguments[0] = Dart_NewInteger(seed);
  }
  else {
    arguments[0] = Dart_Null();
  }
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
cpp_binding_generator::Random cpp_binding_generator::Random::secure() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:math"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Random"));
  return Dart_New(clazz, Dart_NewStringFromCString("secure"), argLen, arguments);
}
 
int64_t cpp_binding_generator::Random::nextInt(int64_t max) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(max);
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("nextInt"), argLen, arguments);
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
double cpp_binding_generator::Random::nextDouble() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("nextDouble"), argLen, arguments);
  double value;
  handleError(Dart_DoubleValue(rawHandle, &value));
  return value;
}
 
bool cpp_binding_generator::Random::nextBool() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("nextBool"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
void cpp_binding_generator::List::shuffle(cpp_binding_generator::Random& random) {
  Dart_Handle arguments[1];
  int argLen = 0;
  if (!Dart_IdentityEquals(random.getHandle(), Dart_Null())) {
    argLen++;
    arguments[0] = random.getHandle();
  }
  else {
    arguments[0] = Dart_Null();
  }
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("shuffle"), argLen, arguments));
}
 
int64_t cpp_binding_generator::List::indexOf(E element, int64_t start) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = element.getHandle();
  if (start != 0) {
    argLen++;
    arguments[1] = Dart_NewInteger(start);
  }
  else {
    arguments[1] = Dart_Null();
  }
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("indexOf"), argLen, arguments);
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
int64_t cpp_binding_generator::List::indexWhere(Dart_Handle test, int64_t start) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = test;
  if (start != 0) {
    argLen++;
    arguments[1] = Dart_NewInteger(start);
  }
  else {
    arguments[1] = Dart_Null();
  }
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("indexWhere"), argLen, arguments);
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
int64_t cpp_binding_generator::List::lastIndexWhere(Dart_Handle test, int64_t start) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = test;
  if (start != 0) {
    argLen++;
    arguments[1] = Dart_NewInteger(start);
  }
  else {
    arguments[1] = Dart_Null();
  }
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("lastIndexWhere"), argLen, arguments);
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
int64_t cpp_binding_generator::List::lastIndexOf(E element, int64_t start) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = element.getHandle();
  if (start != 0) {
    argLen++;
    arguments[1] = Dart_NewInteger(start);
  }
  else {
    arguments[1] = Dart_Null();
  }
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("lastIndexOf"), argLen, arguments);
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
void cpp_binding_generator::List::clear() {
  Dart_Handle arguments[0];
  int argLen = 0;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("clear"), argLen, arguments));
}
 
void cpp_binding_generator::List::insert(int64_t index, E element) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = Dart_NewInteger(index);
  arguments[1] = element.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("insert"), argLen, arguments));
}
 
void cpp_binding_generator::List::insertAll(int64_t index, cpp_binding_generator::Iterable< E >& iterable) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = Dart_NewInteger(index);
  arguments[1] = iterable.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("insertAll"), argLen, arguments));
}
 
void cpp_binding_generator::List::setAll(int64_t index, cpp_binding_generator::Iterable< E >& iterable) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = Dart_NewInteger(index);
  arguments[1] = iterable.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("setAll"), argLen, arguments));
}
 
bool cpp_binding_generator::List::remove(cpp_binding_generator::Object& value) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = value.getHandle();
  Dart_Handle rawHandle = Dart_Invoke(handle, Dart_NewStringFromCString("remove"), argLen, arguments);
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
E cpp_binding_generator::List::removeAt(int64_t index) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(index);
  return Dart_Invoke(handle, Dart_NewStringFromCString("removeAt"), argLen, arguments);
}
 
E cpp_binding_generator::List::removeLast() {
  Dart_Handle arguments[0];
  int argLen = 0;
  return Dart_Invoke(handle, Dart_NewStringFromCString("removeLast"), argLen, arguments);
}
 
void cpp_binding_generator::List::removeWhere(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("removeWhere"), argLen, arguments));
}
 
void cpp_binding_generator::List::retainWhere(Dart_Handle test) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = test;
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("retainWhere"), argLen, arguments));
}
 
cpp_binding_generator::List< E >& cpp_binding_generator::List::+(cpp_binding_generator::List< E >& other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  arguments[0] = other.getHandle();
  cpp_binding_generator::List< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("+"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::List< E >& cpp_binding_generator::List::sublist(int64_t start, int64_t end) {
  Dart_Handle arguments[2];
  int argLen = 1;
  arguments[0] = Dart_NewInteger(start);
  if (end != 0) {
    argLen++;
    arguments[1] = Dart_NewInteger(end);
  }
  else {
    arguments[1] = Dart_Null();
  }
  cpp_binding_generator::List< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("sublist"), argLen, arguments));
  return std::move(retVal);
}
 
cpp_binding_generator::Iterable< E >& cpp_binding_generator::List::getRange(int64_t start, int64_t end) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = Dart_NewInteger(start);
  arguments[1] = Dart_NewInteger(end);
  cpp_binding_generator::Iterable< E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("getRange"), argLen, arguments));
  return std::move(retVal);
}
 
void cpp_binding_generator::List::setRange(int64_t start, int64_t end, cpp_binding_generator::Iterable< E >& iterable, int64_t skipCount) {
  Dart_Handle arguments[4];
  int argLen = 3;
  arguments[0] = Dart_NewInteger(start);
  arguments[1] = Dart_NewInteger(end);
  arguments[2] = iterable.getHandle();
  if (skipCount != 0) {
    argLen++;
    arguments[3] = Dart_NewInteger(skipCount);
  }
  else {
    arguments[3] = Dart_Null();
  }
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("setRange"), argLen, arguments));
}
 
void cpp_binding_generator::List::removeRange(int64_t start, int64_t end) {
  Dart_Handle arguments[2];
  int argLen = 2;
  arguments[0] = Dart_NewInteger(start);
  arguments[1] = Dart_NewInteger(end);
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("removeRange"), argLen, arguments));
}
 
void cpp_binding_generator::List::fillRange(int64_t start, int64_t end, E fillValue) {
  Dart_Handle arguments[3];
  int argLen = 2;
  arguments[0] = Dart_NewInteger(start);
  arguments[1] = Dart_NewInteger(end);
  if (!Dart_IdentityEquals(fillValue.getHandle(), Dart_Null())) {
    argLen++;
    arguments[2] = fillValue.getHandle();
  }
  else {
    arguments[2] = Dart_Null();
  }
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("fillRange"), argLen, arguments));
}
 
void cpp_binding_generator::List::replaceRange(int64_t start, int64_t end, cpp_binding_generator::Iterable< E >& replacement) {
  Dart_Handle arguments[3];
  int argLen = 3;
  arguments[0] = Dart_NewInteger(start);
  arguments[1] = Dart_NewInteger(end);
  arguments[2] = replacement.getHandle();
  handleError(Dart_Invoke(handle, Dart_NewStringFromCString("replaceRange"), argLen, arguments));
}
 
cpp_binding_generator::Map< int64_t, E >& cpp_binding_generator::List::asMap() {
  Dart_Handle arguments[0];
  int argLen = 0;
  cpp_binding_generator::Map< int64_t, E > retVal(Dart_Invoke(handle, Dart_NewStringFromCString("asMap"), argLen, arguments));
  return std::move(retVal);
}
 
template < typename E >
void cpp_binding_generator::List<E>::setFirst(const E value) {
  handleError(Dart_SetField(handle, Dart_NewStringFromCString("first"), value.getHandle()));
}
 
template < typename E >
void cpp_binding_generator::List<E>::setLast(const E value) {
  handleError(Dart_SetField(handle, Dart_NewStringFromCString("last"), value.getHandle()));
}
 
template < typename E >
int64_t cpp_binding_generator::List<E>::getLength() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("length"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template < typename E >
void cpp_binding_generator::List<E>::setLength(int64_t value) {
  handleError(Dart_SetField(handle, Dart_NewStringFromCString("length"), Dart_NewInteger(value)));
}
 
template < typename E >
cpp_binding_generator::Iterable< E >& cpp_binding_generator::List<E>::getReversed() const {
  cpp_binding_generator::Iterable< E > retVal(Dart_GetField(handle, Dart_NewStringFromCString("reversed")));
  return std::move(retVal);
}
 
cpp_binding_generator::List< cpp_binding_generator::Message& >& cpp_binding_generator::Chat::getMessages() const {
  cpp_binding_generator::List< cpp_binding_generator::Message& > retVal(Dart_GetField(handle, Dart_NewStringFromCString("messages")));
  return std::move(retVal);
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
 