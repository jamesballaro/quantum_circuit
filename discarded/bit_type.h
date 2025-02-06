#ifndef BIT_TYPE_H
#define BIT_TYPE_H

#include "type.h"

class bit_type : public type {
public:
    enum class id{
        TargetCNOT,
        TargetFlipCNOT,
        ControlCNOT,
        TargetCZ,
        ControlCZ,
        TargetSwap,
        ControlSwap,
        TargetCCX,
        TargetFlipCCX,
        ControlCCX,
        Qubit,
        Cbit,
        Unknown
    };

private:
    id type;

public:
    explicit bit_type(id bit_type) : type(bit_type) {}
};

#endif // BIT_TYPE_H