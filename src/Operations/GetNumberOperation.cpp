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
    // DELETE THIS
    _elements.push_back(_number);
    _count = 1;
    // END OF DELETE

    //For now, return dummy RollResult
    auto result = std::make_unique<RollResult>();
    result->appendLastResult(_number);
    result->setOperationLog(std::to_string(_number));
    return result;
}
