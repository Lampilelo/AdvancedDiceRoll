#include "DiceRoll/Operations/ComplexOperation.hpp"

namespace DiceRoll {
ComplexOperation::ComplexOperation(IOperation* componentOp) :
    componentOp_(componentOp) {
  if (nullptr == componentOp)
    throw std::invalid_argument(
        "In ComplexOperation constructor: passed nullptr as componentOp.");
}
}
