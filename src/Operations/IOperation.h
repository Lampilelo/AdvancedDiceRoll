#ifndef DICE_IOPERATION_H
#define DICE_IOPERATION_H

#include "stdafx.h"

//Base for a Decorator Pattern
class IOperation
{
protected:
    std::vector<int> _elements;
    int _count;
    IOperation *_componentOp;

public:
    virtual void evaluate() = 0;
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
