#ifndef DICE_IOPERATION_H
#define DICE_IOPERATION_H

#include "../stdafx.hpp"
#include "DiceRoll/Operations/RollResult.h"

//Base for a Decorator Pattern
class IOperation
{
protected:
    // DELETE THIS
    std::vector<int> _elements;
    int _count;
    //END OF DELETE
    /**
     * \brief Suboperation that will be evaluated before current.
     * 
     * Stores an object that is a child of IOperation interface.
     * By default, _componentOp.evaluate() is called before
     * this->execute() and results are merged together.
     */
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
    //DELETE THIS
    virtual std::string toString() const 
    { 
        std::string result = "";
        for (auto& element : _elements)
            result += std::to_string(element) + " ";
        return result;
    }
    inline int getCount() const { return _count; }
    inline const std::vector<int> &getElements() const { return _elements; }
    //END OF DELETE
};

#endif //DICE_IOPERATION_H
