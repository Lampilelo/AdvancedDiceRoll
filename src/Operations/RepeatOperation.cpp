#include "DiceRoll/Operations/RepeatOperation.h"
#include <string>

namespace DiceRoll {
RepeatOperation::RepeatOperation(IOperation* componentOperation,
				 int count)
    : ComplexOperation(componentOperation), count_(count)
{
  if (count_ < 2)
    throw std::invalid_argument("In RepeatOperation: count(" +
                                std::to_string(count_) +
                                ") is lower than 2.");
}

std::unique_ptr<RollResult> RepeatOperation::evaluate()
{
    auto result = std::make_unique<RollResult>();
    std::string operationLog = "(";
    for (int i = 0; i < count_; ++i)
	{
	    auto componentResult = componentOp_->evaluate();
	    // make sequence of numbers divided by spaces
	    operationLog.append(componentResult->getFullResult() + " ");
	    result->appendShortResult(componentResult->getShortResult());
	}
    operationLog[operationLog.length()-1] = ')'; // change last space to ')'
    result->setFullResult(operationLog);
    
    return result;
}
}
