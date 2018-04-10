cmake_minimum_required(VERSION 3.3)
include(ExternalProject)
set(DART_SDK $ENV{DART_SDK})

if (NOT DART_SDK)
    message(FATAL_ERROR "Environment variable DART_SDK not set.")
else()
    message("Found Dart SDK: ${DART_SDK}")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -undefined dynamic_lookup")
include_directories("${DART_SDK}/include")
add_definitions(-DDART_SHARED_LIB=1)

add_library(dart_cpp_binding_gen SHARED
    BindingGenerator.h  BindingGenerator.cpp
)

target_link_libraries(dart_cpp_binding_gen PUBLIC cppast)
install(TARGETS dart_cpp_binding_gen DESTINATION lib)