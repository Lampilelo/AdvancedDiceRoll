#ifndef DICE_IOPERATION_H
#define DICE_IOPERATION_H

#include "../stdafx.hpp"
#include "DiceRoll/Operations/RollResult.h"

//Base for a Decorator Pattern
/**
 * \brief An interface for the Operation classes.
 * 
 * It is a base for the Decorator Pattern.
 */
class IOperation
{
    IOperation * const _componentOp;
    
    /**
     * \brief Executes current operation.
     * 
     * This is a method that does all the heavy lifting for an operation.
     *
     * \return 
     * Returns unique pointer to RollResult which stores current operation result.
     * Don't mistake it with evaluate()!
     */
    virtual std::unique_ptr<RollResult> execute() = 0;

public:
    IOperation(IOperation* op) : _componentOp(op) {}
    
    // Executes all operations.
    // By default, merges _componentOp's RollResult with its.
    /**
     * \brief Evaluates all suboperations and executes itself.
     *
     * By default it calls evaluate() on it's suboperation (_componentOp)
     * and then merges the result with its own.
     * 
     * \return Unique pointer to the result of executing current operation
     * and all suboperations.
     */
    virtual inline std::unique_ptr<RollResult> evaluate()
    {
	std::unique_ptr<RollResult> result = _componentOp->evaluate();
	result->append(execute().get());
	return result;
    }
};

#endif //DICE_IOPERATION_H
