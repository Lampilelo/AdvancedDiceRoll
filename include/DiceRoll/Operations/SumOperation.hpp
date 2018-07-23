#ifndef DICEROLL_SUMOPERATION_H
#define DICEROLL_SUMOPERATION_H

#include "DiceRoll/stdafx.hpp"
#include "DiceRoll/Operations/IOperation.hpp"

/**
 * \brief Operation that sums the results of another operation.
 *
 * Method evaluate() will return one valued RollResult that stores the sum
 * of other operation's results.
*/
class SumOperation : public IOperation {
  // Sums componentOp's RollResult;
  std::unique_ptr<RollResult> execute();

 public:
  /**
   * \brief SumOperation
   * Multiple value operation.
   *
   * \param componentOperation Operation that needs to be summed up.
   */
  using IOperation::IOperation;

  /**
   * \brief Sums component operation's RollResult values.
   * Evaluates component operation and sums its result.
   *
   * Syntax for FullResult in RollResult is (<sum> (+ <compOp FullResult>)).
   * If summing just one value, RollResult of component operation is
   * forwarded.
   * \return Unique pointer to single valued RollResult.
   */
  inline std::unique_ptr<RollResult> evaluate() {
    return execute();
  }
};

#endif // DICEROLL_SUMOPERATION_H
