#include "DiceRoll/Operations/GetNumberOperation.hpp"

GetNumberOperation::GetNumberOperation(int number) : _number(number)
{
    _count = 0;
    _componentOp = nullptr;
}

std::shared_ptr<RollResult> GetNumberOperation::evaluate()
{
    return execute();
}

std::shared_ptr<RollResult> GetNumberOperation::execute() 
{ 
    _elements.push_back(_number);
    _count = 1;

    //For now, return dummy RollResult
    return std::make_shared<RollResult>();
}
