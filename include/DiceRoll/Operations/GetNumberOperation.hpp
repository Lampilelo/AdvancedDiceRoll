#ifndef DICE_GETNUMBEROPERATION_H
#define DICE_GETNUMBEROPERATION_H

#include "IOperation.hpp"

class GetNumberOperation : public IOperation
{
    const int _number;
    
protected:
    std::unique_ptr<RollResult> execute();
    
public:
    explicit GetNumberOperation(int);

    std::unique_ptr<RollResult> evaluate();
};

#endif //DICE_GETNUMBEROPERATION_H
