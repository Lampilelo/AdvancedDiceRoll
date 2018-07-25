#ifndef DICEROLL_COMPLEXOPERATION_H
#define DICEROLL_COMPLEXOPERATION_H

#include "DiceRoll/Operations/IOperation.hpp"

namespace DiceRoll {
/**
 * \brief An abstract class for Operation classes that take an IOperation
 * argument in its constructor.
 *
 * ComplexOperation is designed to be used for Operation classes that contain
 * IOperation data member. Evaluating an object inheriting ComplexOperation
 * also evaluates an operation given to it as a constructor argument.
 */
class ComplexOperation : public IOperation {
 protected:
  /**
   * An operation that should be evaluated when evaluate() is called.
   */
  IOperation* const componentOp_;
  
  ComplexOperation(IOperation* componentOp);
 public:
  virtual ~ComplexOperation() { }

  /**
   * \brief Evaluates componentOp and then itself.
   *
   * \return Unique pointer to RollResult containing information about this
   * and past operations.
   */
  virtual std::unique_ptr<RollResult> evaluate() = 0;
};
}

#endif // DICEROLL_COMPLEXOPERATION_H
