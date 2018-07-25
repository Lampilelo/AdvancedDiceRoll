#ifndef DICE_RANDOMOPERATION_H
#define DICE_RANDOMOPERATION_H

#include "../stdafx.hpp"

#include "IOperation.hpp"

namespace DiceRoll {
/**
 * \brief Randoms a number from a given range.
 */
class RandomOperation : public IOperation
{
    // Upper and lower limits in range for generating number. These values
    // are inclusive.
    const int lower_, upper_;
    // Seed for random number generator that is used in execute().
    unsigned int seed_;
    // It is true if seed has been set, and false if not.
    bool fixedSeed_;

public:
    // If seed is not given, it will randomize using time
    /**
     * Defines range for RandomOperation. Lower limit is 1, and upper is defined (both are inclusive).
     * by the user.
     *
     * \param upper [in] Upper limit (inclusive) in random range.
     * Have to be greater than 0.
     */
    RandomOperation(int upper);
    /**
     * Defines range for RandomOperation. User can specify lower and upper limit (both inclusive).
     * for randomizing a number.
     * 
     * \param lower Lower limit (inclusive) in random range.
     * Have to be lower than upper.
     * \param upper Upper limit (inclusive) in random range.
     * Have to be greater than lower.
     */
    RandomOperation(int lower, int upper);

    // Throws exception if lower >= upper
    /**
     * \brief Generates one random number from range specified in the
     * constructor.
     * 
     * \return Unique pointer to RollResult storing one random number
     * from range specified by the constructor.
     */
    std::unique_ptr<RollResult> evaluate();
    /**
     * \brief Sets seed for randomizing a number.
     *
     * If seed is not set, it defaults to timestamp so operation generates
     * random number.\n
     * If it is set, evaluating the operation will return the same result
     * every time.
     * 
     * \param newSeed Seed for random operation.
     */
    void changeSeed(unsigned newSeed);
};
}

#endif // DICE_RANDOMOPERATION_H
