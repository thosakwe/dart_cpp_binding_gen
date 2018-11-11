#include "delegate_test.extension.g.hpp"
#include "foo.g.hpp"

using namespace cpp_binding_generator;

void cpp_binding_generator_extension_getBazFrom(Dart_NativeArguments arguments) {
    // First argument is a foo
    Foo foo = Dart_GetNativeArgument(arguments, 0);

    // Call the generated function to fetch `baz`.
    auto baz = foo.getBaz();

    // Now, return that.
    Dart_SetReturnValue(arguments, Dart_NewInteger(baz));
}

void cpp_binding_generator_extension_setBazTo(Dart_NativeArguments arguments) {
    // First arg is Foo, second is int
    Foo foo = Dart_GetNativeArgument(arguments, 0);
    Dart_Handle value = Dart_GetNativeArgument(arguments, 1);
    int64_t v;
    Dart_IntegerToInt64(value, &v);
    foo.setBaz(v);
}

void cpp_binding_generator_extension_addToBaz(Dart_NativeArguments arguments) {
    // First arg is Foo, second is int
    Foo foo = Dart_GetNativeArgument(arguments, 0);
    Dart_Handle value = Dart_GetNativeArgument(arguments, 1);
    int64_t v;
    Dart_IntegerToInt64(value, &v);
    auto result = foo.addToBar(v);
    Dart_SetReturnValue(arguments, Dart_NewInteger(result));
}

void cpp_binding_generator_extension_newFooWithX(Dart_NativeArguments arguments) {
    // First arg is int
    Dart_Handle value = Dart_GetNativeArgument(arguments, 0);
    int64_t v;
    Dart_IntegerToInt64(value, &v);

    // Create an instance of `Foo.bar`
    auto foo = Foo::bar(v);

    // Return it
    Dart_SetReturnValue(arguments, foo.getHandle());
}
