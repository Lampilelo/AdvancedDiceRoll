#ifndef DICE_RANDOMOPERATION_H
#define DICE_RANDOMOPERATION_H

#include "../stdafx.h"

#include "IOperation.h"

class RandomOperation : public IOperation
{
    const int _lower, _upper;
public:
    RandomOperation(int upper);
    RandomOperation(int lower, int upper);

    void evaluate(); // Throws exception if lower >= upper
};

#endif // DICE_RANDOMOPERATION_H
