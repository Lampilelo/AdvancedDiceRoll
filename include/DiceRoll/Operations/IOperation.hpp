#ifndef DICE_IOPERATION_H
#define DICE_IOPERATION_H

#include "../stdafx.hpp"
#include "DiceRoll/Operations/RollResult.h"

//Base for a Decorator Pattern
class IOperation
{
    IOperation * const _componentOp;

    // Execute operation. All heavy lifting for object.
    virtual std::unique_ptr<RollResult> execute() = 0;

public:
    IOperation(IOperation* op) : _componentOp(op) {}
    
    // Executes all operations.
    // By default, merges _componentOp's RollResult with its.
    virtual inline std::unique_ptr<RollResult> evaluate()
    {
	std::unique_ptr<RollResult> result = _componentOp->evaluate();
	result->append(execute().get());
	return result;
    }
};

#endif //DICE_IOPERATION_H
