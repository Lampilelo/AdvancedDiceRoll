#ifndef DICE_GETNUMBEROPERATION_H
#define DICE_GETNUMBEROPERATION_H

#include "IOperation.h"

class GetNumberOperation : public IOperation
{
    const int _number;
public:
    GetNumberOperation(int);

    void evaluate();
};

#endif //DICE_GETNUMBEROPERATION_H
