#ifndef DICE_IOPERATION_H
#define DICE_IOPERATION_H

#include "DiceRoll/Operations/RollResult.h"

namespace DiceRoll {
//Base for a Decorator Pattern
/**
 * \brief An interface for the Operation classes.
 * 
 * It is a base for the Decorator Pattern.
 */
class IOperation
{
public:
  virtual ~IOperation() { }
    // Executes all operations.
    /**
     * \brief Is used to evaluate all suboperations and execute itself.
     *
     * \return Unique pointer to the result of executing current operation
     * and all of its suboperations.
     */
  virtual std::unique_ptr<RollResult> evaluate() = 0;
};
}

#endif //DICE_IOPERATION_H
