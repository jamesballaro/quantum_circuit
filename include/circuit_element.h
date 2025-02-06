#ifndef CIRCUIT_ELEMENT_H
#define CIRCUIT_ELEMENT_H

#include "component.h"
#include <memory>
#include <vector>
#include <stdexcept>
#include <iostream>

struct circuit_element {
    std::shared_ptr<component> gate;
    std::vector<int> bits;

    circuit_element(std::shared_ptr<component> g, std::vector<int> q): gate(std::move(g)), bits(std::move(q)){}

    bool ensure_valid() const{
        return !gate?  false : true;
    }
public:
    // All getters simply call ensure_gate() with no local try-catch
    std::string get_type() const {
        // if(ensure_valid()){
            return gate->get_type();
        // }
        // else{
            // return "";
        // }
    }

    matrix get_operator() const {
        if(ensure_valid()){
            return gate->get_operator();
        }
        else{
            return matrix().null();
        }
    }

    int get_range() const {
        if(ensure_valid()){
            return gate->get_range();
        }
        else{
            return 0;
        }
    }

    std::vector<int> get_bits() const {
         if(ensure_valid()){
            return bits;
        }
        else{
            return {};
        }
    }
};

#endif