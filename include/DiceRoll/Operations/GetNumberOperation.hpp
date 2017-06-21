#ifndef DICE_GETNUMBEROPERATION_H
#define DICE_GETNUMBEROPERATION_H

#include "IOperation.hpp"

/**
 * \brief Creates RollResult from singular value.
 */
class GetNumberOperation : public IOperation
{
    const int _number;		// stores number given by a constructor

    // It's called directly by evaluate, so check its doc.
    std::unique_ptr<RollResult> execute();
    
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

    /**
     * \brief Evaluates an operation.
     * 
     * \return Returns unique pointer to RollResult containing singular
     * value specified while calling constructor.
     */
    std::unique_ptr<RollResult> evaluate();
};

#endif //DICE_GETNUMBEROPERATION_H
