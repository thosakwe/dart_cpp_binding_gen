#ifndef DART_CPP_BINDING_GENERATOR_FOO_DART_H
 
#define DART_CPP_BINDING_GENERATOR_FOO_DART_H
 
#include <dart_api.h>
 
/*
 * Creates a new instance of `Foo.`
 * @return A handle to the created instance.
 */
Dart_Handle dart_cpp_binding_generator_new_foo();
 
/*
 * Named constructor!!!
 * @param abc Required.
 * @return A handle to the created instance.
 */
Dart_Handle dart_cpp_binding_generator_new_foo_bar(Dart_Handle abc);
 
// Gets the `baz` property of an instance of `Foo`.
Dart_Handle dart_cpp_binding_generator_foo_get_baz(Dart_Handle instance);
 
// Sets the `baz` property of an instance of `Foo`.
void dart_cpp_binding_generator_foo_set_baz(Dart_Handle instance, Dart_Handle value);
 
/*
 * Invokes the `quux` method of an instance of `Foo`.
 * @return The result of calling the function.
 */
Dart_Handle dart_cpp_binding_generator_foo_invoke_quux(Dart_Handle instance);
 
/*
 * Invokes the `addToQuux` method of an instance of `Foo`.
 * @param x Required.
 * @return The result of calling the function.
 */
Dart_Handle dart_cpp_binding_generator_foo_invoke_add_to_quux(Dart_Handle instance, Dart_Handle x);
 
#endif
 