#ifndef DICE_GETNUMBEROPERATION_H
#define DICE_GETNUMBEROPERATION_H

#include "IOperation.hpp"

class GetNumberOperation : public IOperation
{
    const int _number;

protected:
    std::shared_ptr<RollResult> execute();
    
public:
    GetNumberOperation(int);

    std::shared_ptr<RollResult> evaluate();
};

#endif //DICE_GETNUMBEROPERATION_H
