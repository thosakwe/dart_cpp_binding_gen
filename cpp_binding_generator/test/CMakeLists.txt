project(binding_test C CXX)
add_definitions(-DDART_SHARED_LIB=1)
add_library(delegate_test SHARED
        ../lib/src/cpp_parser.g.cpp
        ../lib/src/cpp_parser.g.hpp
        delegate_test.extension.g.cpp
        delegate_test.extension.g.hpp
        delegate_test.impl.cc
        foo.g.cpp foo.g.hpp
        user.g.cpp user.g.hpp)

set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_ROOT})
install(TARGETS delegate_test DESTINATION ${PROJECT_ROOT})