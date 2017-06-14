#include "DiceRoll/Operations/GetNumberOperation.hpp"

GetNumberOperation::GetNumberOperation(int number)
    : IOperation(nullptr), _number(number)
{
    _count = 0;
}

std::unique_ptr<RollResult> GetNumberOperation::evaluate()
{
    return execute();
}

std::unique_ptr<RollResult> GetNumberOperation::execute() 
{ 
    _elements.push_back(_number);
    _count = 1;

    //For now, return dummy RollResult
    return std::make_unique<RollResult>();
}
