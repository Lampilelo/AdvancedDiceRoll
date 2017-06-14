#ifndef ROLLRESULT_H
#define ROLLRESULT_H

#include <vector>
#include <string>
#include <memory>

class RollResult
{
    bool _hasErrors;
    std::vector<std::string> _errorLog;
    /* std::string _rawResult; */

public:
    RollResult();

    const std::vector<std::string>& getErrorLog() const;
    void appendErrorLog(const std::string error);
    bool hasErrors() const;
    void append(const RollResult* item);
    /* void appendRawResult(std::string ) */
};


#endif // ROLLRESULT_H
