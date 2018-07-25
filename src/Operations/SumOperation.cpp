#include "DiceRoll/Operations/SumOperation.hpp"

namespace DiceRoll {
SumOperation::SumOperation(IOperation* componentOp) :
    ComplexOperation(componentOp) { }

std::unique_ptr<RollResult> SumOperation::evaluate() {
  auto result = std::make_unique<RollResult>();
  auto componentResult = componentOp_->evaluate();

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
}
