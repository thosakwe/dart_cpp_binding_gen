#include "delegate_test.h"
#include "foo.delegate.h"

void dart_cpp_binding_generator_extension_get_baz_from(Dart_NativeArguments arguments) {
    // First argument is a foo
    Dart_Handle foo = Dart_GetNativeArgument(arguments, 0);

    // Call the generated function to fetch `baz`.
    Dart_Handle baz = dart_cpp_binding_generator_foo_get_baz(foo);

    // Now, return that.
    Dart_SetReturnValue(arguments, baz);
}

void dart_cpp_binding_generator_extension_set_baz_to(Dart_NativeArguments arguments) {
    // First arg is Foo, second is int
    Dart_Handle foo = Dart_GetNativeArgument(arguments, 0), value = Dart_GetNativeArgument(arguments, 1);
    dart_cpp_binding_generator_foo_set_baz(foo, value);
}

void dart_cpp_binding_generator_extension_add_to_baz(Dart_NativeArguments arguments) {
    // First arg is Foo, second is int
    Dart_Handle foo = Dart_GetNativeArgument(arguments, 0), value = Dart_GetNativeArgument(arguments, 1);
    Dart_Handle result = dart_cpp_binding_generator_foo_invoke_add_to_bar(foo, value);
    Dart_SetReturnValue(arguments, result);
}
