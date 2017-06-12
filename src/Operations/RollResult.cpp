#include "DiceRoll/Operations/RollResult.h"

RollResult::RollResult()
{
    _hasErrors = false;
}

void RollResult::appendErrorLog(const std::string error)
{
    _errorLog.push_back(error);
}

bool RollResult::hasErrors() const
{
    return !_hasErrors;
}
