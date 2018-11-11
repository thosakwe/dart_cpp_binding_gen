#include <dart_api.h>
 
#include <string>
 
#ifndef USER_BINDING_H
 
#define USER_BINDING_H
 
namespace cpp_binding_generator {
  class User;
  class Status;
  class User {
    public:
      User(Dart_Handle handle);
      Dart_Handle getHandle() const;
      User(Status& status);
      Status& fakeStatus(int64_t n);
      int64_t multiply(int64_t x, int64_t loop = 0);
      void sayHi();
      Status& getStatus() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
  class Status {
    public:
      Status(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Status(const std::string& text);
      std::string getText() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      Dart_Handle handle;
  };
}
 
#endif
 