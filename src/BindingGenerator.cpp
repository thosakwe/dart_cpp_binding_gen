//
// Created by Tobe on 4/10/18.
//

#include "BindingGenerator.h"

void BindingGenerator::doIt() {
    cppast::libclang_compile_config config;
    cppast::diagnostic_logger logger;
    cppast::cpp_entity_index index;
    cppast::libclang_parser parser(logger);
}
