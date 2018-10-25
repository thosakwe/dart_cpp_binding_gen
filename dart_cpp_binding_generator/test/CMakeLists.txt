project(binding_test C CXX)
add_definitions(-DDART_SHARED_LIB=1)
add_library(delegate_test SHARED
        ../lib/src/cpp_parser.g.cpp
        ../lib/src/cpp_parser.g.hpp
        foo.g.cpp foo.g.hpp
        user.g.cpp user.g.hpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/test")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
install(TARGETS delegate_test DESTINATION "${CMAKE_CURRENT_LIST_DIR}")