#include "DiceRoll/Operations/RepeatOperation.h"
#include <string>

RepeatOperation::RepeatOperation(IOperation* componentOperation,
				 int count)
    : IOperation(componentOperation), _count(count)
{
  if (_count < 2)
    throw std::invalid_argument("In RepeatOperation: count(" +
                                std::to_string(_count) +
                                ") is lower than 2.");
}

std::unique_ptr<RollResult> RepeatOperation::execute()
{
    auto result = std::make_unique<RollResult>();
    std::string operationLog = "(";
    for (int i = 0; i < _count; ++i)
	{
	    auto componentResult = _componentOp->evaluate();
	    // make sequence of numbers divided by spaces
	    operationLog.append(componentResult->getFullResult() + " ");
	    result->appendShortResult(componentResult->getShortResult());
	}
    operationLog[operationLog.length()-1] = ')'; // change last space to ')'
    result->setFullResult(operationLog);
    
    return result;
}
