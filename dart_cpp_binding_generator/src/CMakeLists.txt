cmake_minimum_required(VERSION 3.3)
include(ExternalProject)

add_library(dart_cpp_binding_gen SHARED
        BindingGenerator.h BindingGenerator.cpp
        sample_extension.cc
)

target_link_libraries(dart_cpp_binding_gen PUBLIC cppast)
install(TARGETS dart_cpp_binding_gen DESTINATION lib)