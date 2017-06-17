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
    virtual inline std::unique_ptr<RollResult> evaluate()
    {
	std::unique_ptr<RollResult> result = _componentOp->evaluate();
	result->append(execute().get());
	return result;
    }
    virtual std::string toString() const 
    { 
        std::string result = "";
        for (auto& element : _elements)
            result += std::to_string(element) + " ";
        return result;
    }
    inline int getCount() const { return _count; }
    inline const std::vector<int> &getElements() const { return _elements; }
};

#endif //DICE_IOPERATION_H
