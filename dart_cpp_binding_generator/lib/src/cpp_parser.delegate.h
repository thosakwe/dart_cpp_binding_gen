#ifndef DART_CPP_BINDING_GENERATOR_CPP_PARSER_DART_H
 
#define DART_CPP_BINDING_GENERATOR_CPP_PARSER_DART_H
 
#include <dart_api.h>
 
/*
 * Creates a new instance of `CppParser`.
 * @return A handle to the created instance.
 */
Dart_Handle dart_cpp_binding_generator_new_cpp_parser();
 
// Gets the `functions` property of an instance of `CppParser`.
Dart_Handle dart_cpp_binding_generator_cpp_parser_get_functions(Dart_Handle instance);
 
/*
 * Creates a new instance of `CppFunction`.
 * @param name Required.
 * @return A handle to the created instance.
 */
Dart_Handle dart_cpp_binding_generator_new_cpp_function(Dart_Handle name);
 
// Gets the `name` property of an instance of `CppFunction`.
Dart_Handle dart_cpp_binding_generator_cpp_function_get_name(Dart_Handle instance);
 
// Gets the `arguments` property of an instance of `CppFunction`.
Dart_Handle dart_cpp_binding_generator_cpp_function_get_arguments(Dart_Handle instance);
 
/*
 * Creates a new instance of `CppArgument`.
 * @param name Required.
 * @param type Required.
 * @return A handle to the created instance.
 */
Dart_Handle dart_cpp_binding_generator_new_cpp_argument(Dart_Handle name, Dart_Handle type);
 
// Gets the `name` property of an instance of `CppArgument`.
Dart_Handle dart_cpp_binding_generator_cpp_argument_get_name(Dart_Handle instance);
 
// Gets the `type` property of an instance of `CppArgument`.
Dart_Handle dart_cpp_binding_generator_cpp_argument_get_type(Dart_Handle instance);
 
#endif
 