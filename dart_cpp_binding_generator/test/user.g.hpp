#include <dart_api.h>
 
#include <string>
 
#ifndef USER_BINDING_H
 
#define USER_BINDING_H
 
namespace dart_cpp_binding_generator {
  class User;
  class Status;
  class User {
    public:
      User(Dart_Handle handle);
      Dart_Handle getHandle() const;
      User(const Status& status);
      const Status& getStatus() const;
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
 