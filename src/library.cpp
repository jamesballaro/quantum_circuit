#include "library.h"
#include "toolbox.h"

//Initializing variables for each
namespace library{
	factory gates;
    factory bits;
}

void library::library_creator() {
    gates = {
        {"Identity",std::make_shared<identity>()}, 
        {"PauliX",  std::make_shared<pauli_X>() },
        {"PauliY",  std::make_shared<pauli_Y>() },
        {"PauliZ",  std::make_shared<pauli_Z>() },
        {"Hadamard",std::make_shared<hadamard>()}, 
        {"Phase",   std::make_shared<phase>()   }, 
        {"CNOT",    std::make_shared<cnot>()    },
        {"CZ",      std::make_shared<cz>()      }, 
        {"Swap",    std::make_shared<swap>()    },
        {"Toffoli", std::make_shared<ccx>()     }                 
    };

    bits = {
        {"Qubit",           std::make_shared<qubit>()},
        {"ClassicalBit",    std::make_shared<cbit>()},
        // {"TargetCNOT",      std::make_shared<target_cnot>()},
        // {"TargetFlipCNOT",  std::make_shared<target_flip_cnot>()},
        // {"ControlCNOT",     std::make_shared<control_cnot>()},
        // {"TargetCZ",        std::make_shared<target_cz>()},
        // {"ControlCZ",       std::make_shared<control_cz>()},
        // {"TargetSwap",      std::make_shared<target_swap>()},
        // {"ControlSwap",     std::make_shared<control_swap>()},
        // {"TargetCCX",       std::make_shared<target_ccx>()},
        // {"TargetFlipCCX",   std::make_shared<target_flip_ccx>()},
        // {"ControlCCX",      std::make_shared<control_ccx>()}
    };
}

std::shared_ptr<component> library::string_to_ptr(std::string component)
{
    auto it = gates.find(component);
    if(it!=gates.end()){  
        return it->second;
    }
    else{
        auto it = bits.find(component);
        if(it!=bits.end()){  
            return it->second;
        }
    }
    return nullptr;
}

