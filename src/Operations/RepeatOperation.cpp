#include "DiceRoll/Operations/RepeatOperation.h"

RepeatOperation::RepeatOperation(IOperation* componentOperation,
				 int count)
    : IOperation(componentOperation), _count(count)
{
}

std::unique_ptr<RollResult> RepeatOperation::execute()
{
    auto result = std::make_unique<RollResult>();
    std::string operationLog = "(";
    for (int i = 0; i < _count; ++i)
	{
	    auto componentResult = _componentOp->evaluate();
	    // make sequence of numbers divided by spaces
	    operationLog.append(componentResult->getOperationLog() + " ");
	    result->appendLastResult(componentResult->getLastResult());
	}
    operationLog[operationLog.length()-1] = ')'; // change last space to ')'
    result->setOperationLog(operationLog);
    
    return result;
}
