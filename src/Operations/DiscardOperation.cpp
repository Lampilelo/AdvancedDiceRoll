#include "DiceRoll/Operations/DiscardOperation.hpp"
#include "DiceRoll/stdafx.hpp"

namespace DiceRoll {
std::unique_ptr<RollResult> DiscardOperation::execute(
    std::unique_ptr<RollResult> component_result) {
  if (component_result->getShortResultSize() < 2 ||
      (size_t)leave_amount_ >= component_result->getShortResultSize())
    return component_result;

  // sort according to comparator_ and leave only values that fulfull req
  auto shortResult = component_result->getShortResult();
  std::sort(shortResult.begin(), shortResult.end(), comparator_->compare());
  shortResult.resize(leave_amount_);
  component_result->setShortResult(shortResult);

  // create new FullResult
  std::string newFullResult = "(";
  for(auto value : shortResult) {
    newFullResult += std::to_string(value) + " ";
  }
  newFullResult += ": dis[" + std::to_string(leave_amount_) +
      ", " + comparator_->symbol() + "]";

  newFullResult.append(component_result->getFullResult() + ')');
  component_result->setFullResult(newFullResult);

  return component_result;
}

DiscardOperation::DiscardOperation(IOperation* componentOp,
                                   int leave_amount,
                                   DiceRoll::IRollCompare* comparator) :
    ComplexOperation(componentOp),
    leave_amount_(leave_amount),
    comparator_(comparator) {
  if (leave_amount_ < 1)
    throw std::invalid_argument("In DiscardOperation: leave_amount(" +
                                std::to_string(leave_amount_) +
                                ") is lower than 1");
}
}
