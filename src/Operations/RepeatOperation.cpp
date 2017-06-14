#include "DiceRoll/Operations/RepeatOperation.h"

RepeatOperation::RepeatOperation(IOperation* componentOperation,
				 int count)
    : IOperation(componentOperation), _count(count)
{
}

std::unique_ptr<RollResult> RepeatOperation::execute()
{
    auto result = std::make_unique<RollResult>();
    result->appendErrorLog("RepeatOperation");
    return result;
}
