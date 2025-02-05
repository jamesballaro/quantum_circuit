#ifndef GATE_TYPE_H
#define GATE_TYPE_H

#include <unordered_map>
#include <string>
// #include "single_bit_gates.h"
// #include "multi_bit_gates.h"
// #include "component.h"
#include <memory>

class gate_type {
public:
    enum class id {
        Identity, 
        PauliX, 
        PauliY, 
        PauliZ, 
        Hadamard,
        Phase,
        CNOT, 
        CZ, 
        Swap, 
        Toffoli,
        Unknown
    };
private:
    id type;

public:
    explicit gate_type(id gateType) : type(gateType) {}

};

#endif;