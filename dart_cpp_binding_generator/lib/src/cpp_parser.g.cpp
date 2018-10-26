#include "cpp_parser.g.hpp"
 
Dart_Handle dart_cpp_binding_generator::Chat::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Chat::Chat(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Chat::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Chat::Chat() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Chat"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::List::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::List::List(Dart_Handle handle) {
  this->handle = handle;
}
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::List::getHandle() const {
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::List::List(int64_t length) {
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
 
template <typename E>
dart_cpp_binding_generator::List dart_cpp_binding_generator::List::filled(int64_t length, E fill, bool growable) {
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
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::Iterable::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::Iterable::Iterable(Dart_Handle handle) {
  this->handle = handle;
}
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::Iterable::getHandle() const {
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::Iterable::Iterable() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterable"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template <typename E>
dart_cpp_binding_generator::Iterable dart_cpp_binding_generator::Iterable::generate(int64_t count, Dart_Handle generator) {
  Dart_Handle arguments[2];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterable"));
  arguments[0] = Dart_NewInteger(count);
  if (generator != nullptr) {
    argLen++;
    arguments[1] = generator;
  }
  else {
    arguments[1] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("generate"), argLen, arguments);
}
 
template <typename E>
dart_cpp_binding_generator::Iterable dart_cpp_binding_generator::Iterable::empty() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterable"));
  return Dart_New(clazz, Dart_NewStringFromCString("empty"), argLen, arguments);
}
 
Dart_Handle dart_cpp_binding_generator::Object::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Object::Object(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Object::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Object::Object() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Object"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
Dart_Handle dart_cpp_binding_generator::Invocation::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Invocation::Invocation(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Invocation::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Invocation::Invocation() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
Dart_Handle dart_cpp_binding_generator::Symbol::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Symbol::Symbol(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Symbol::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Symbol::Symbol(const std::string& name) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Symbol"));
  arguments[0] = Dart_NewStringFromCString(name.c_str());
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
dart_cpp_binding_generator::Symbol& dart_cpp_binding_generator::Symbol::getUnaryMinus() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("unaryMinus"));
}
 
dart_cpp_binding_generator::Symbol& dart_cpp_binding_generator::Symbol::getEmpty() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("empty"));
}
 
int64_t dart_cpp_binding_generator::Symbol::getHashCode() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("hashCode"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template <typename K, typename V>
Dart_Handle dart_cpp_binding_generator::Map::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map::Map(Dart_Handle handle) {
  this->handle = handle;
}
 
template <typename K, typename V>
Dart_Handle dart_cpp_binding_generator::Map::getHandle() const {
  return handle;
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map::Map() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map dart_cpp_binding_generator::Map::from(dart_cpp_binding_generator::Map<Dart_Handle, Dart_Handle> other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = other.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("from"), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map dart_cpp_binding_generator::Map::of(dart_cpp_binding_generator::Map<K, V> other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = other.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("of"), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map dart_cpp_binding_generator::Map::unmodifiable(dart_cpp_binding_generator::Map<Dart_Handle, Dart_Handle> other) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = other.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("unmodifiable"), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map dart_cpp_binding_generator::Map::identity() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  return Dart_New(clazz, Dart_NewStringFromCString("identity"), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map dart_cpp_binding_generator::Map::fromIterable(dart_cpp_binding_generator::Iterable<Dart_Handle> iterable, Dart_Handle key, Dart_Handle value) {
  Dart_Handle arguments[3];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = iterable.getHandle();
  if (key != nullptr) {
    argLen++;
    arguments[1] = key;
  }
  else {
    arguments[1] = Dart_Null();
  }
  if (value != nullptr) {
    argLen++;
    arguments[2] = value;
  }
  else {
    arguments[2] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("fromIterable"), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map dart_cpp_binding_generator::Map::fromIterables(dart_cpp_binding_generator::Iterable<K> keys, dart_cpp_binding_generator::Iterable<V> values) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = keys.getHandle();
  arguments[1] = values.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("fromIterables"), argLen, arguments);
}
 
template <typename K, typename V>
Dart_Handle dart_cpp_binding_generator::MapEntry::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template <typename K, typename V>
dart_cpp_binding_generator::MapEntry::MapEntry(Dart_Handle handle) {
  this->handle = handle;
}
 
template <typename K, typename V>
Dart_Handle dart_cpp_binding_generator::MapEntry::getHandle() const {
  return handle;
}
 
template <typename K, typename V>
dart_cpp_binding_generator::MapEntry::MapEntry(K key, V value) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("MapEntry"));
  arguments[0] = key.getHandle();
  arguments[1] = value.getHandle();
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::MapEntry dart_cpp_binding_generator::MapEntry::_(K key, V value) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("MapEntry"));
  arguments[0] = key.getHandle();
  arguments[1] = value.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("_"), argLen, arguments);
}
 
template <typename K, typename V>
K dart_cpp_binding_generator::MapEntry::getKey() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("key"));
}
 
template <typename K, typename V>
V dart_cpp_binding_generator::MapEntry::getValue() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("value"));
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Map dart_cpp_binding_generator::Map::fromEntries(dart_cpp_binding_generator::Iterable<dart_cpp_binding_generator::MapEntry<K, V>> entries) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Map"));
  arguments[0] = entries.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("fromEntries"), argLen, arguments);
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Iterable<dart_cpp_binding_generator::MapEntry<K, V>> dart_cpp_binding_generator::Map::getEntries() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("entries"));
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Iterable<K> dart_cpp_binding_generator::Map::getKeys() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("keys"));
}
 
template <typename K, typename V>
dart_cpp_binding_generator::Iterable<V> dart_cpp_binding_generator::Map::getValues() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("values"));
}
 
template <typename K, typename V>
int64_t dart_cpp_binding_generator::Map::getLength() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("length"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template <typename K, typename V>
bool dart_cpp_binding_generator::Map::getIsEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
template <typename K, typename V>
bool dart_cpp_binding_generator::Map::getIsNotEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isNotEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
dart_cpp_binding_generator::Invocation dart_cpp_binding_generator::Invocation::method(dart_cpp_binding_generator::Symbol& memberName, dart_cpp_binding_generator::Iterable<dart_cpp_binding_generator::Object&> positionalArguments, dart_cpp_binding_generator::Map<dart_cpp_binding_generator::Symbol&, dart_cpp_binding_generator::Object&> namedArguments) {
  Dart_Handle arguments[3];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = memberName.getHandle();
  arguments[1] = positionalArguments.getHandle();
  if (namedArguments != nullptr) {
    argLen++;
    arguments[2] = namedArguments.getHandle();
  }
  else {
    arguments[2] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("method"), argLen, arguments);
}
 
Dart_Handle dart_cpp_binding_generator::Type::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Type::Type(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Type::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Type::Type() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Type"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
dart_cpp_binding_generator::Invocation dart_cpp_binding_generator::Invocation::genericMethod(dart_cpp_binding_generator::Symbol& memberName, dart_cpp_binding_generator::Iterable<dart_cpp_binding_generator::Type&> typeArguments, dart_cpp_binding_generator::Iterable<dart_cpp_binding_generator::Object&> positionalArguments, dart_cpp_binding_generator::Map<dart_cpp_binding_generator::Symbol&, dart_cpp_binding_generator::Object&> namedArguments) {
  Dart_Handle arguments[4];
  int argLen = 3;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = memberName.getHandle();
  arguments[1] = typeArguments.getHandle();
  arguments[2] = positionalArguments.getHandle();
  if (namedArguments != nullptr) {
    argLen++;
    arguments[3] = namedArguments.getHandle();
  }
  else {
    arguments[3] = Dart_Null();
  }
  return Dart_New(clazz, Dart_NewStringFromCString("genericMethod"), argLen, arguments);
}
 
dart_cpp_binding_generator::Invocation dart_cpp_binding_generator::Invocation::getter(dart_cpp_binding_generator::Symbol& name) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = name.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("getter"), argLen, arguments);
}
 
dart_cpp_binding_generator::Invocation dart_cpp_binding_generator::Invocation::setter(dart_cpp_binding_generator::Symbol& memberName, dart_cpp_binding_generator::Object& argument) {
  Dart_Handle arguments[2];
  int argLen = 2;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Invocation"));
  arguments[0] = memberName.getHandle();
  arguments[1] = argument.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("setter"), argLen, arguments);
}
 
dart_cpp_binding_generator::Symbol& dart_cpp_binding_generator::Invocation::getMemberName() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("memberName"));
}
 
dart_cpp_binding_generator::List<dart_cpp_binding_generator::Type&> dart_cpp_binding_generator::Invocation::getTypeArguments() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("typeArguments"));
}
 
dart_cpp_binding_generator::List<Dart_Handle> dart_cpp_binding_generator::Invocation::getPositionalArguments() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("positionalArguments"));
}
 
dart_cpp_binding_generator::Map<dart_cpp_binding_generator::Symbol&, Dart_Handle> dart_cpp_binding_generator::Invocation::getNamedArguments() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("namedArguments"));
}
 
bool dart_cpp_binding_generator::Invocation::getIsMethod() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isMethod"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool dart_cpp_binding_generator::Invocation::getIsGetter() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isGetter"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool dart_cpp_binding_generator::Invocation::getIsSetter() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isSetter"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
bool dart_cpp_binding_generator::Invocation::getIsAccessor() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isAccessor"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
int64_t dart_cpp_binding_generator::Object::getHashCode() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("hashCode"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
dart_cpp_binding_generator::Type& dart_cpp_binding_generator::Object::getRuntimeType() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("runtimeType"));
}
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::Set::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::Set::Set(Dart_Handle handle) {
  this->handle = handle;
}
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::Set::getHandle() const {
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::Set::Set() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template <typename E>
dart_cpp_binding_generator::Set dart_cpp_binding_generator::Set::identity() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  return Dart_New(clazz, Dart_NewStringFromCString("identity"), argLen, arguments);
}
 
template <typename E>
dart_cpp_binding_generator::Set dart_cpp_binding_generator::Set::from(dart_cpp_binding_generator::Iterable<Dart_Handle> elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  arguments[0] = elements.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("from"), argLen, arguments);
}
 
template <typename E>
dart_cpp_binding_generator::Set dart_cpp_binding_generator::Set::of(dart_cpp_binding_generator::Iterable<E> elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Set"));
  arguments[0] = elements.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("of"), argLen, arguments);
}
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::Iterator::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::Iterator::Iterator(Dart_Handle handle) {
  this->handle = handle;
}
 
template <typename E>
Dart_Handle dart_cpp_binding_generator::Iterator::getHandle() const {
  return handle;
}
 
template <typename E>
dart_cpp_binding_generator::Iterator::Iterator() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Iterator"));
  this->handle = Dart_New(clazz, Dart_NewStringFromCString(""), argLen, arguments);
}
 
template <typename E>
E dart_cpp_binding_generator::Iterator::getCurrent() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("current"));
}
 
template <typename E>
dart_cpp_binding_generator::Iterator<E> dart_cpp_binding_generator::Set::getIterator() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("iterator"));
}
 
template <typename E>
dart_cpp_binding_generator::Iterator<E> dart_cpp_binding_generator::Iterable::getIterator() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("iterator"));
}
 
template <typename E>
int64_t dart_cpp_binding_generator::Iterable::getLength() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("length"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template <typename E>
bool dart_cpp_binding_generator::Iterable::getIsEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
template <typename E>
bool dart_cpp_binding_generator::Iterable::getIsNotEmpty() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("isNotEmpty"));
  bool value;
  handleError(Dart_BooleanValue(rawHandle, &value));
  return value;
}
 
template <typename E>
E dart_cpp_binding_generator::Iterable::getFirst() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("first"));
}
 
template <typename E>
E dart_cpp_binding_generator::Iterable::getLast() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("last"));
}
 
template <typename E>
E dart_cpp_binding_generator::Iterable::getSingle() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("single"));
}
 
template <typename E>
dart_cpp_binding_generator::List dart_cpp_binding_generator::List::from(dart_cpp_binding_generator::Iterable<Dart_Handle> elements, bool growable) {
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
 
template <typename E>
dart_cpp_binding_generator::List dart_cpp_binding_generator::List::of(dart_cpp_binding_generator::Iterable<E> elements, bool growable) {
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
 
template <typename E>
dart_cpp_binding_generator::List dart_cpp_binding_generator::List::generate(int64_t length, Dart_Handle generator, bool growable) {
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
 
template <typename E>
dart_cpp_binding_generator::List dart_cpp_binding_generator::List::unmodifiable(dart_cpp_binding_generator::Iterable<Dart_Handle> elements) {
  Dart_Handle arguments[1];
  int argLen = 1;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:core"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("List"));
  arguments[0] = elements.getHandle();
  return Dart_New(clazz, Dart_NewStringFromCString("unmodifiable"), argLen, arguments);
}
 
Dart_Handle dart_cpp_binding_generator::Random::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Random::Random(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Random::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Random::Random(int64_t seed) {
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
 
dart_cpp_binding_generator::Random dart_cpp_binding_generator::Random::secure() {
  Dart_Handle arguments[0];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("dart:math"));
  Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Random"));
  return Dart_New(clazz, Dart_NewStringFromCString("secure"), argLen, arguments);
}
 
template <typename E>
void dart_cpp_binding_generator::List::setFirst(const E value) {
  Dart_SetField(handle, Dart_NewStringFromCString("first"), value.getHandle());
}
 
template <typename E>
void dart_cpp_binding_generator::List::setLast(const E value) {
  Dart_SetField(handle, Dart_NewStringFromCString("last"), value.getHandle());
}
 
template <typename E>
int64_t dart_cpp_binding_generator::List::getLength() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("length"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
template <typename E>
void dart_cpp_binding_generator::List::setLength(int64_t value) {
  Dart_SetField(handle, Dart_NewStringFromCString("length"), Dart_NewInteger(value));
}
 
template <typename E>
dart_cpp_binding_generator::Iterable<E> dart_cpp_binding_generator::List::getReversed() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("reversed"));
}
 
dart_cpp_binding_generator::List<dart_cpp_binding_generator::Message&> dart_cpp_binding_generator::Chat::getMessages() const {
  return Dart_GetField(handle, Dart_NewStringFromCString("messages"));
}
 
int64_t dart_cpp_binding_generator::Chat::getMessageCount() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("messageCount"));
  int64_t value;
  handleError(Dart_IntegerToInt64(rawHandle, &value));
  return value;
}
 
Dart_Handle dart_cpp_binding_generator::Message::handleError(Dart_Handle handle) {
  if (Dart_IsError(handle)) Dart_PropagateError(handle);
  return handle;
}
 
dart_cpp_binding_generator::Message::Message(Dart_Handle handle) {
  this->handle = handle;
}
 
Dart_Handle dart_cpp_binding_generator::Message::getHandle() const {
  return handle;
}
 
dart_cpp_binding_generator::Message::Message(const std::string& text) {
  Dart_Handle arguments[1];
  int argLen = 0;
  Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/lib/src/cpp_parser.dart"));
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
 
std::string dart_cpp_binding_generator::Message::getText() const {
  Dart_Handle rawHandle = Dart_GetField(handle, Dart_NewStringFromCString("text"));
  const char *value;
  handleError(Dart_StringToCString(rawHandle, &value));
  return value;
}
 