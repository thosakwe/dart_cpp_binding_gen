project(binding_test C CXX)
add_definitions(-DDART_SHARED_LIB=1)
add_library(delegate_test SHARED
        delegate_test.h delegate_test.cc
        delegate_test.impl.cc
        foo.delegate.h foo.delegate.cpp
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/test")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
install(TARGETS delegate_test DESTINATION "${CMAKE_CURRENT_LIST_DIR}")