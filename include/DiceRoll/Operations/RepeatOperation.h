#ifndef REPEATOPERATION_H
#define REPEATOPERATION_H

#include "DiceRoll/stdafx.hpp"
#include "DiceRoll/Operations/ComplexOperation.hpp"

namespace DiceRoll {
/**
 * \brief Operation that repeats other operation multiple times.
 *
 * Give it operation that you want to repeat and how many times in the
 * constructor.\n
 * Method evaluate() will return multiple valued RollResult that 
 * stores results of repeated operation, so if you want to get 
 * result from 4d10 dice roll you would repeat RandomOperation(10)
 * 4 times.
 */
class RepeatOperation : public ComplexOperation
{
    const int count_; // how many times should it repeat.

public:
    /**
     * \brief RepeatOperation
     * Multiple value operation.
     *
     * \param componentOperation Operation that needs to be repeated.
     * \param count
     * \parblock
     * How many times should it be repeated.
     * Can't be lower than 1. If 1, it would not repeat.
     * \endparblock
     */
    explicit RepeatOperation(IOperation* componentOperation,
			     int count);

    ~RepeatOperation() { }

    std::unique_ptr<RollResult> evaluate();
};
}

#endif /* REPEATOPERATION_H */
