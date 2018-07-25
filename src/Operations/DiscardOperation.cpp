#include "DiceRoll/Operations/DiscardOperation.hpp"
#include "DiceRoll/stdafx.hpp"

std::unique_ptr<RollResult> DiscardOperation::execute() {
  auto result = _componentOp->evaluate();
  if (result->getShortResultSize() < 2)
    return result;

  // sort according to comparator_ and leave only values that fulfull req
  auto shortResult = result->getShortResult();
  std::sort(shortResult.begin(), shortResult.end(), comparator_->compare());
  shortResult.resize(leave_amount_);
  result->setShortResult(shortResult);

  // create new FullResult
  std::string newFullResult = "(dis[" + std::to_string(leave_amount_) +
      ", " + comparator_->symbol() + "]: ";
  for(auto value : shortResult) {
    newFullResult += std::to_string(value) + " ";
  }
  newFullResult.append(':' + result->getFullResult() + ')');
  result->setFullResult(newFullResult);

  return result;
}

DiscardOperation::DiscardOperation(IOperation* componentOp,
                                   int leave_amount,
                                   DiceRoll::IRollCompare* comparator) :
    IOperation(componentOp),
    leave_amount_(leave_amount),
    comparator_(comparator) {
  if (leave_amount_ < 1)
    throw std::invalid_argument("In DiscardOperation: leave_amount(" +
                                std::to_string(leave_amount_) +
                                ") is lower than 1");
}
