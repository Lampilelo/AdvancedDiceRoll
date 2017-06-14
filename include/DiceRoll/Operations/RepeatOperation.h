#ifndef REPEATOPERATION_H
#define REPEATOPERATION_H

#include "DiceRoll/stdafx.hpp"
#include "DiceRoll/Operations/IOperation.hpp"

class RepeatOperation : public IOperation
{
    const int _count;

    std::unique_ptr<RollResult> execute();
    
public:
    // componnetOperation - operation that needs to be repeated
    // count - how many times should it be repeated
    explicit RepeatOperation(IOperation* componentOperation,
			     int count);
};

#endif /* REPEATOPERATION_H */
