#include <dart_api.h>
 
#include <string>
 
#ifndef CPP_PARSER_BINDING_H
 
#define CPP_PARSER_BINDING_H
 
namespace dart_cpp_binding_generator {
  class Chat;
  class Message;
  class Chat {
    public:
      Chat(Dart_Handle handle);
      Dart_Handle getHandle() const;
      Chat();
      MessageList getMessages() const;
      int64_t getMessageCount() const;
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
 