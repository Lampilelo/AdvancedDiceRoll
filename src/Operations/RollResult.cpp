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

bool RollResult::hasErrors() const
{
    return _hasErrors;
}

const std::string& RollResult::getError(int index) const
{
    //TODO: We should check bounds.
    return _errorLog[index];
}

const std::vector<std::string>& RollResult::getErrorLog() const
{
    return _errorLog;
}

void RollResult::append(const RollResult *item)
{
    for(auto& error : item->getErrorLog())
	_errorLog.push_back(error);
}
