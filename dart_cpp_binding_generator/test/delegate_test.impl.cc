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