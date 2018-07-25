#ifndef DICE_GETNUMBEROPERATION_H
#define DICE_GETNUMBEROPERATION_H

#include "IOperation.hpp"

namespace DiceRoll {
/**
 * \brief Creates RollResult from singular value.
 */
class GetNumberOperation : public IOperation
{
    const int number_;		// stores number given by a constructor

public:
    /**
     * \brief Operation that creates singular value RollResult.
     * 
     * It's a primitive operation that should be a base for decorators.
     * 
     * \param number Integer value that we want to pass to other
     * operations.
     */
    explicit GetNumberOperation(int number);

    ~GetNumberOperation() { }

    /**
     * \brief Evaluates an operation.
     * 
     * \return Returns unique pointer to RollResult containing singular
     * value specified while calling constructor.
     */
    std::unique_ptr<RollResult> evaluate();
};
}

#endif //DICE_GETNUMBEROPERATION_H
