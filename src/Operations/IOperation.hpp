#ifndef DICE_IOPERATION_H
#define DICE_IOPERATION_H

#include "../stdafx.hpp"

//Base for a Decorator Pattern
class IOperation
{
protected:
    std::vector<int> _elements;
    int _count;
    IOperation *_componentOp;

    // Execute operation. All heavy lifting for object.
    virtual void execute() = 0;

public:
    // Executes all operations.
    virtual inline void evaluate()
    {
	_componentOp->evaluate();
	execute();
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
