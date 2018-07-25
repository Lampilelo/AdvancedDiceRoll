#include "DiceRoll/Operations/GetNumberOperation.hpp"

namespace DiceRoll {
GetNumberOperation::GetNumberOperation(int number) : number_(number)
{ }

std::unique_ptr<RollResult> GetNumberOperation::evaluate()
{
    auto result = std::make_unique<RollResult>();
    result->appendShortResult(number_);
    result->setFullResult(std::to_string(number_));
    return result;
}
}
