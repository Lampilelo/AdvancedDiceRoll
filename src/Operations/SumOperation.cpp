#include "DiceRoll/Operations/SumOperation.hpp"

std::unique_ptr<RollResult> SumOperation::execute() {
  auto result = std::make_unique<RollResult>();
  auto componentResult = _componentOp->evaluate();

  if (1 == componentResult->getShortResultSize())
    return componentResult;

  std::string operationLog = "(+ " + componentResult->getFullResult() + ')';
  // auto compFullResult = componentResult->getFullResult();
  // compFullResult.insert(compFullResult.find(""))

  int sum = 0;
  for (auto&& item : componentResult->getShortResult()) {
    sum += item;
  }
  result->setFullResult('(' + std::to_string(sum) + ' ' + operationLog + ')');
  result->appendShortResult(sum);

  return result;
}

