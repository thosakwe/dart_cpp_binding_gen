#include <dart_api.h>
 
#include <string>
 
#ifndef FOO_BINDING_H
 
#define FOO_BINDING_H
 
namespace dart_cpp_binding_generator {
  class Foo;
  class Foo {
    public:
      Foo(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Foo();
      static Foo bar(int64_t baz);
      int64_t getBaz() const;
      void setBaz(int64_t value);
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
}
 
#endif
 