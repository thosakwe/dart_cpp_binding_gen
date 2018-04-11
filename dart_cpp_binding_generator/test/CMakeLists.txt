project(binding_test C CXX)
add_library(delegate_test
        delegate_test.h delegate_test.cc
        delegate_test.impl.cc
        foo.delegate.h foo.delegate.cpp
)