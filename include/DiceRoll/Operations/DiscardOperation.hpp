#ifndef DICEROLL_DISCARDOPERATION_H
#define DICEROLL_DISCARDOPERATION_H

#include "DiceRoll/Operations/ComplexOperation.hpp"
#include "DiceRoll/RollCompare/IRollCompare.hpp"

namespace DiceRoll {
class DiscardOperation : public ComplexOperation {
  const int leave_amount_;
  DiceRoll::IRollCompare* comparator_;

  std::unique_ptr<RollResult> execute(
      std::unique_ptr<RollResult> component_result);

 public:
  DiscardOperation(IOperation* componentOp,
                   int leave_amount,
                   DiceRoll::IRollCompare* comparator);
  ~DiscardOperation() { }

  // Syntax for RollResult:
  // (dis[<leave_amount>, <comparer_symbol>]: <resulting numbers> :<rest>)
  // e.g. (dis[2, >]: 5 4 :(1 2 3 4 5))
  inline std::unique_ptr<RollResult> evaluate() {
    return execute(componentOp_->evaluate());
  }
};
}

#endif // DICEROLL_DISCARDOPERATION_H
