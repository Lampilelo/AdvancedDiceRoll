#include "DiceRoll/Operations/ComplexOperation.hpp"

namespace DiceRoll {
ComplexOperation::ComplexOperation(IOperation* componentOp) :
    componentOp_(componentOp) { }
}
