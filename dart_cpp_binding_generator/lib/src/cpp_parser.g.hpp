#include <dart_api.h>
 
#include <string>
 
#ifndef CPP_PARSER_BINDING_H
 
#define CPP_PARSER_BINDING_H
 
namespace dart_cpp_binding_generator {
  class CppParser;
  class CppFunction;
  class CppArgument;
  class CppParser {
    public:
      CppParser(const Dart_Handle handle);
      Dart_Handle getHandle() const;
      CppParser();
      List& getFunctions() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      const Dart_Handle handle;
  };
  class CppFunction {
    public:
      CppFunction(const Dart_Handle handle);
      Dart_Handle getHandle() const;
      CppFunction(const std::string& name);
      std::string getName() const;
      List& getArguments() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      const Dart_Handle handle;
  };
  class CppArgument {
    public:
      CppArgument(const Dart_Handle handle);
      Dart_Handle getHandle() const;
      CppArgument(const std::string& name, const std::string& type);
      std::string getName() const;
      std::string getType() const;
    private:
      static Dart_Handle handleError(Dart_Handle handle);
      const Dart_Handle handle;
  };
}
 
#endif
 