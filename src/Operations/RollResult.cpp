#include "DiceRoll/Operations/RollResult.h"

RollResult::RollResult()
{
    _hasErrors = false;
}

void RollResult::appendErrorLog(const std::string error)
{
    _errorLog.push_back(error);
    _hasErrors = true;
}

void RollResult::append(const RollResult *item)
{
    for(auto& error : item->getErrorLog())
	_errorLog.push_back(error);
}


