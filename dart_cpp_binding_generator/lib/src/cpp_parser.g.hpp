#include <dart_api.h>
 
#include <string>
 
#ifndef CPP_PARSER_BINDING_H
 
#define CPP_PARSER_BINDING_H
 
namespace dart_cpp_binding_generator {
  class Chat;
  class Message;
  template <typename E> class List;
  template <typename E> class Iterable;
  class Object;
  class Invocation;
  class Symbol;
  template <typename K, typename V> class Map;
  template <typename K, typename V> class MapEntry;
  class Type;
  template <typename E> class Set;
  template <typename E> class Iterator;
  class Random;
  class Chat {
    public:
      Chat(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Chat();
      Dart_Handle printInfo();
      List<Message&> getMessages() const;
      int64_t getMessageCount() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  template <typename E>
  class List {
    public:
      List(Dart_Handle handle);
      Dart_Handle getHandle() const;
      List(int64_t length = 0);
      static List filled(int64_t length, E fill, bool growable = false);
      static List from(Iterable<Dart_Handle> elements, bool growable = false);
      static List of(Iterable<E> elements, bool growable = false);
      static List generate(int64_t length, Dart_Handle generator, bool growable = false);
      static List unmodifiable(Iterable<Dart_Handle> elements);
      template <typename S, typename T>
      List<T> castFrom(List<S> source);
      template <typename T>
      Dart_Handle copyRange(List<T> target, int64_t at, List<T> source, int64_t start = 0, int64_t end = 0);
      template <typename T>
      Dart_Handle writeIterable(List<T> target, int64_t at, Iterable<T> source);
      template <typename R>
      List<R> cast();
      E operator[](int64_t index);
      Dart_Handle operator[]=(int64_t index, E value);
      Dart_Handle add(E value);
      Dart_Handle addAll(Iterable<E> iterable);
      Dart_Handle sort(Dart_Handle compare = nullptr);
      Dart_Handle shuffle(Random& random = nullptr);
      int64_t indexOf(E element, int64_t start = 0);
      int64_t indexWhere(Dart_Handle test, int64_t start = 0);
      int64_t lastIndexWhere(Dart_Handle test, int64_t start = 0);
      int64_t lastIndexOf(E element, int64_t start = 0);
      Dart_Handle clear();
      Dart_Handle insert(int64_t index, E element);
      Dart_Handle insertAll(int64_t index, Iterable<E> iterable);
      Dart_Handle setAll(int64_t index, Iterable<E> iterable);
      bool remove(Object& value);
      E removeAt(int64_t index);
      E removeLast();
      Dart_Handle removeWhere(Dart_Handle test);
      Dart_Handle retainWhere(Dart_Handle test);
      List<E> operator+(List<E> other);
      List<E> sublist(int64_t start, int64_t end = 0);
      Iterable<E> getRange(int64_t start, int64_t end);
      Dart_Handle setRange(int64_t start, int64_t end, Iterable<E> iterable, int64_t skipCount = 0);
      Dart_Handle removeRange(int64_t start, int64_t end);
      Dart_Handle fillRange(int64_t start, int64_t end, E fillValue = nullptr);
      Dart_Handle replaceRange(int64_t start, int64_t end, Iterable<E> replacement);
      Map<int64_t, E> asMap();
      void setFirst(E value);
      void setLast(E value);
      int64_t getLength() const;
      void setLength(int64_t value);
      Iterable<E> getReversed() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  template <typename E>
  class Iterable {
    public:
      Iterable(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Iterable();
      static Iterable generate(int64_t count, Dart_Handle generator = nullptr);
      static Iterable empty();
      template <typename S, typename T>
      Iterable<T> castFrom(Iterable<S> source);
      template <typename R>
      Iterable<R> cast();
      Iterable<E> followedBy(Iterable<E> other);
      template <typename T>
      Iterable<T> map(Dart_Handle f);
      Iterable<E> where(Dart_Handle test);
      template <typename T>
      Iterable<T> whereType();
      template <typename T>
      Iterable<T> expand(Dart_Handle f);
      bool contains(Object& element);
      Dart_Handle forEach(Dart_Handle f);
      E reduce(Dart_Handle combine);
      template <typename T>
      T fold(T initialValue, Dart_Handle combine);
      bool every(Dart_Handle test);
      const std::string& join(const std::string& separator = "");
      bool any(Dart_Handle test);
      List<E> toList(bool growable = false);
      Set<E> toSet();
      Iterable<E> take(int64_t count);
      Iterable<E> takeWhile(Dart_Handle test);
      Iterable<E> skip(int64_t count);
      Iterable<E> skipWhile(Dart_Handle test);
      E firstWhere(Dart_Handle test, Dart_Handle orElse = nullptr);
      E lastWhere(Dart_Handle test, Dart_Handle orElse = nullptr);
      E singleWhere(Dart_Handle test, Dart_Handle orElse = nullptr);
      E elementAt(int64_t index);
      const std::string& toString();
      Iterator<E> getIterator() const;
      int64_t getLength() const;
      bool getIsEmpty() const;
      bool getIsNotEmpty() const;
      E getFirst() const;
      E getLast() const;
      E getSingle() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  class Object {
    public:
      Object(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Object();
      bool operator==(Dart_Handle other);
      const std::string& toString();
      Dart_Handle noSuchMethod(Invocation& invocation);
      int64_t getHashCode() const;
      Type& getRuntimeType() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  class Invocation {
    public:
      Invocation(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Invocation();
      static Invocation method(Symbol& memberName, Iterable<Object&> positionalArguments, Map<Symbol&, Object&> namedArguments = nullptr);
      static Invocation genericMethod(Symbol& memberName, Iterable<Type&> typeArguments, Iterable<Object&> positionalArguments, Map<Symbol&, Object&> namedArguments = nullptr);
      static Invocation getter(Symbol& name);
      static Invocation setter(Symbol& memberName, Object& argument);
      Symbol& getMemberName() const;
      List<Type&> getTypeArguments() const;
      List<Dart_Handle> getPositionalArguments() const;
      Map<Symbol&, Dart_Handle> getNamedArguments() const;
      bool getIsMethod() const;
      bool getIsGetter() const;
      bool getIsSetter() const;
      bool getIsAccessor() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  class Symbol {
    public:
      Symbol(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Symbol(const std::string& name);
      bool operator==(Dart_Handle other);
      Symbol& getUnaryMinus() const;
      Symbol& getEmpty() const;
      int64_t getHashCode() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  template <typename K, typename V>
  class Map {
    public:
      Map(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Map();
      static Map from(Map<Dart_Handle, Dart_Handle> other);
      static Map of(Map<K, V> other);
      static Map unmodifiable(Map<Dart_Handle, Dart_Handle> other);
      static Map identity();
      static Map fromIterable(Iterable<Dart_Handle> iterable, Dart_Handle key = nullptr, Dart_Handle value = nullptr);
      static Map fromIterables(Iterable<K> keys, Iterable<V> values);
      static Map fromEntries(Iterable<MapEntry<K, V>> entries);
      template <typename K, typename V, typename K2, typename V2>
      Map<K2, V2> castFrom(Map<K, V> source);
      template <typename RK, typename RV>
      Map<RK, RV> cast();
      bool containsValue(Object& value);
      bool containsKey(Object& key);
      V operator[](Object& key);
      Dart_Handle operator[]=(K key, V value);
      template <typename K2, typename V2>
      Map<K2, V2> map(Dart_Handle f);
      Dart_Handle addEntries(Iterable<MapEntry<K, V>> newEntries);
      V update(K key, Dart_Handle update, Dart_Handle ifAbsent = nullptr);
      Dart_Handle updateAll(Dart_Handle update);
      Dart_Handle removeWhere(Dart_Handle predicate);
      V putIfAbsent(K key, Dart_Handle ifAbsent);
      Dart_Handle addAll(Map<K, V> other);
      V remove(Object& key);
      Dart_Handle clear();
      Dart_Handle forEach(Dart_Handle f);
      Iterable<MapEntry<K, V>> getEntries() const;
      Iterable<K> getKeys() const;
      Iterable<V> getValues() const;
      int64_t getLength() const;
      bool getIsEmpty() const;
      bool getIsNotEmpty() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  template <typename K, typename V>
  class MapEntry {
    public:
      MapEntry(Dart_Handle handle);
      Dart_Handle getHandle() const;
      MapEntry(K key, V value);
      static MapEntry _(K key, V value);
      const std::string& toString();
      K getKey() const;
      V getValue() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  class Type {
    public:
      Type(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Type();
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  template <typename E>
  class Set {
    public:
      Set(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Set();
      static Set identity();
      static Set from(Iterable<Dart_Handle> elements);
      static Set of(Iterable<E> elements);
      template <typename S, typename T>
      Set<T> castFrom(Set<S> source, Dart_Handle newSet = nullptr);
      template <typename R>
      Set<R> cast();
      bool contains(Object& value);
      bool add(E value);
      Dart_Handle addAll(Iterable<E> elements);
      bool remove(Object& value);
      E lookup(Object& object);
      Dart_Handle removeAll(Iterable<Object&> elements);
      Dart_Handle retainAll(Iterable<Object&> elements);
      Dart_Handle removeWhere(Dart_Handle test);
      Dart_Handle retainWhere(Dart_Handle test);
      bool containsAll(Iterable<Object&> other);
      Set<E> intersection(Set<Object&> other);
      Set<E> union(Set<E> other);
      Set<E> difference(Set<Object&> other);
      Dart_Handle clear();
      Set<E> toSet();
      Iterator<E> getIterator() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  template <typename E>
  class Iterator {
    public:
      Iterator(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Iterator();
      bool moveNext();
      E getCurrent() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  class Random {
    public:
      Random(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Random(int64_t seed = 0);
      static Random secure();
      int64_t nextInt(int64_t max);
      double nextDouble();
      bool nextBool();
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  class Message {
    public:
      Message(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Message(const std::string& text = "");
      std::string getText() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
}
 
#endif
 