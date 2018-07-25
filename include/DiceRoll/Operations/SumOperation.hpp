#ifndef DICEROLL_SUMOPERATION_H
#define DICEROLL_SUMOPERATION_H

#include "DiceRoll/stdafx.hpp"
#include "DiceRoll/Operations/ComplexOperation.hpp"

namespace DiceRoll {
/**
 * \brief Operation that sums the results of another operation.
 *
 * Method evaluate() will return one valued RollResult that stores the sum
 * of other operation's results.
*/
class SumOperation : public ComplexOperation {
 public:
  /**
   * \brief SumOperation
   * Multiple value operation.
   *
   * \param componentOperation Operation that needs to be summed up.
   */
  explicit SumOperation(IOperation* componentOp);

  /**
   * \brief Sums component operation's RollResult values.
   * Evaluates component operation and sums its result.
   *
   * Syntax for FullResult in RollResult is (<sum> (+ <compOp FullResult>)).
   * If summing just one value, RollResult of component operation is
   * forwarded.
   * \return Unique pointer to single valued RollResult.
   */
  virtual std::unique_ptr<RollResult> evaluate();
};
}

#endif // DICEROLL_SUMOPERATION_H
