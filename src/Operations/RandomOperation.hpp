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
    std::shared_ptr<RollResult> execute();
    
public:
    // If seed is not given, it will randomize using time
    RandomOperation(int upper);
    RandomOperation(int lower, int upper);

    // Throws exception if lower >= upper
    std::shared_ptr<RollResult> evaluate(); 
    void changeSeed(unsigned newSeed);
};

#endif // DICE_RANDOMOPERATION_H
