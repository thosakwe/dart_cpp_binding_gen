#include <iostream>
#include "foo.delegate.h"

Dart_Handle dart_cpp_binding_generator_new_foo() {
    Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/test/foo.dart"));
    Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
    Dart_Handle arguments[0];
    return Dart_New(clazz, Dart_NewStringFromCString(""), 0, arguments);
}

Dart_Handle dart_cpp_binding_generator_new_foo_bar(Dart_Handle baz) {
    Dart_Handle libs = Dart_GetLoadedLibraries();
    intptr_t length;
    Dart_Handle handle = Dart_ListLength(libs, &length);

    if (Dart_IsError(handle))
        return Dart_PropagateError(handle);

    for (intptr_t i = 0; i < length; i++) {
        handle = Dart_ListGetAt(libs, i);

        if (Dart_IsError(handle))
            return Dart_PropagateError(handle);

        handle = Dart_LibraryUrl(handle);

        if (Dart_IsError(handle))
            return Dart_PropagateError(handle);

        const char *libPath;
        handle = Dart_StringToCString(handle, &libPath);

        if (Dart_IsError(handle))
            Dart_PropagateError(handle);
        else
            std::cout << "Lib #" << i << ": " << libPath << std::endl;
    }

    Dart_Handle lib = Dart_LookupLibrary(Dart_NewStringFromCString("package:dart_cpp_binding_generator/test/foo.dart"));
    Dart_Handle clazz = Dart_GetClass(lib, Dart_NewStringFromCString("Foo"));
    Dart_Handle arguments[1];
    arguments[0] = baz;
    return Dart_New(clazz, Dart_NewStringFromCString("bar"), 1, arguments);
}

Dart_Handle dart_cpp_binding_generator_foo_get_baz(Dart_Handle instance) {
    return Dart_GetField(instance, Dart_NewStringFromCString("baz"));
}

void dart_cpp_binding_generator_foo_set_baz(Dart_Handle instance, Dart_Handle value) {
    Dart_SetField(instance, Dart_NewStringFromCString("baz"), value);
}

Dart_Handle dart_cpp_binding_generator_foo_invoke_quux(Dart_Handle instance) {
    Dart_Handle arguments[0];
    return Dart_Invoke(instance, Dart_NewStringFromCString("quux"), 0, arguments);
}

Dart_Handle dart_cpp_binding_generator_foo_invoke_add_to_bar(Dart_Handle instance, Dart_Handle x) {
    Dart_Handle arguments[1];
    arguments[0] = x;
    return Dart_Invoke(instance, Dart_NewStringFromCString("addToBar"), 1, arguments);
}
 