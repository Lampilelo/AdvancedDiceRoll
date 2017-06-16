#ifndef ROLLRESULT_H
#define ROLLRESULT_H

#include <vector>
#include <string>
#include <memory>

class RollResult
{
    bool _hasErrors;
    std::vector<std::string> _errorLog;

    std::string _operationLog;
    // every operation should store its result in that variable
    std::vector<int> _lastResult;

public:
    RollResult();

    void appendErrorLog(const std::string& error);
    void append(const RollResult* item);

    inline bool hasErrors() const { return _hasErrors; }

    inline const std::vector<std::string>& getErrorLog() const
    { return _errorLog; }

    inline const std::string& getOperationLog() const
    { return _operationLog; }

    inline void setOperationLog(const std::string& newOpLog)
    { _operationLog = newOpLog; }

    inline const std::vector<int>& getLastResult() const
    { return _lastResult; }

    inline void setLastResult(std::vector<int> &newResult)
    { _lastResult = newResult; }
};


#endif // ROLLRESULT_H
