#include "DiceRoll/Operations/GetNumberOperation.hpp"

GetNumberOperation::GetNumberOperation(int number)
    : IOperation(nullptr), _number(number)
{ }

std::unique_ptr<RollResult> GetNumberOperation::evaluate()
{
    return execute();
}

std::unique_ptr<RollResult> GetNumberOperation::execute() 
{
    auto result = std::make_unique<RollResult>();
    result->appendLastResult(_number);
    result->setOperationLog(std::to_string(_number));
    return result;
}
