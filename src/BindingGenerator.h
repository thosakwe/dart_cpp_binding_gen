//
// Created by Tobe on 4/10/18.
//

#ifndef BINDING_GEN_BINDINGGENERATOR_H
#define BINDING_GEN_BINDINGGENERATOR_H
#include <cppast/libclang_parser.hpp> // for libclang_parser, libclang_compile_config, cpp_entity,...
#include <cppast/visitor.hpp>         // for visit()
#include <cppast/code_generator.hpp>  // for generate_code()
#include <cppast/cpp_entity_kind.hpp>        // for the cpp_entity_kind definition
#include <cppast/cpp_forward_declarable.hpp> // for is_definition()
#include <cppast/cpp_namespace.hpp>          // for cpp_namespace

class BindingGenerator
{
private:
    void doIt();
};


#endif //BINDING_GEN_BINDINGGENERATOR_H
