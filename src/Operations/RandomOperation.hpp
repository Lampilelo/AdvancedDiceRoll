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
    void execute();
    
public:
    // If seed is not given, it will randomize using time
    RandomOperation(int upper);
    RandomOperation(int lower, int upper);

    void evaluate(); // Throws exception if lower >= upper
    void changeSeed(unsigned newSeed);
};

#endif // DICE_RANDOMOPERATION_H
