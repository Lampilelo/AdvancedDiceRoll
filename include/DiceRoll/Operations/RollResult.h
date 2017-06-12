#include <vector>
#include <string>

class RollResult
{
    bool _hasErrors;
    std::vector<std::string> _errorLog;
    /* std::string _rawResult; */

public:
    RollResult();

    const std::string& getError(int index) const;
    void appendErrorLog(std::string error);
    bool hasErrors() const;
    void append(const RollResult& item);
    /* void appendRawResult(std::string ) */
};
