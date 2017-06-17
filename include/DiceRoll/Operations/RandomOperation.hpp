#ifndef DICE_RANDOMOPERATION_H
#define DICE_RANDOMOPERATION_H

#include "../stdafx.hpp"

#include "IOperation.hpp"

class RandomOperation : public IOperation
{
    const int _lower, _upper;
    unsigned int _seed;
    bool _fixedSeed;

protected:
    /**
     * \brief Generates one random number from range specified in the
     * constructor.
     * 
     * \return Unique pointer to RollResult storing one random number.
     *
     * \exception std::invalid_argument If constructor got bad arguments.
     * (Lower is less than 1 or/and less than upper)
     */
    std::unique_ptr<RollResult> execute();
    
public:
    // If seed is not given, it will randomize using time
    /**
     * Defines range for RandomOperation. Lower limit is 1, and upper is defined (both are inclusive).
     * by the user.
     *
     * \param upper [in] Upper limit (inclusive) in random range.
     */
    RandomOperation(int upper);
    /**
     * Defines range for RandomOperation. User can specify lower and upper limit (both inclusive).
     * for randomizing a number.
     * 
     * \param lower Lower limit (inclusive) in random range.
     * \param upper Upper limit (inclusive) in random range.
     */
    RandomOperation(int lower, int upper);

    // Throws exception if lower >= upper
    /**
     * \brief Calls execute() and does nothing else.
     * 
     * \return Returns unique pointer to the RollResult containing one random
     * number from range specified by the constructor.
     */
    std::unique_ptr<RollResult> evaluate(); 
    void changeSeed(unsigned newSeed);
};

#endif // DICE_RANDOMOPERATION_H
