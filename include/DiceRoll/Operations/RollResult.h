#ifndef ROLLRESULT_H
#define ROLLRESULT_H

#include <vector>
#include <string>
#include <memory>

/**
 * \brief Stores results from evaluating Operations.
 */
class RollResult
{
    bool _hasErrors;
    
    // Store all errors that IOperation::evaluate() caught here.
    std::vector<std::string> _errorLog; 

    // string record for all operations that have been evaluated
    // it should be readable to the user and you should be able to
    // place equals sign between _operationLog and _lastResult
    std::string _operationLog;
    
    // every operation should store its result in that variable
    std::vector<int> _lastResult;

public:
    RollResult();

    /**
     * \brief Appends error log with given string
     * 
     * \param error Error in form of a string.
     */
    void appendErrorLog(const std::string& error);
    /**
     * \brief Merges this with another RollResult
     * 
     * \param item RollResult that will be appended to this one.
     */
    void append(const RollResult* item);

    /**
     * \brief Checks if there are errors in error log.
     * 
     * \return True if there are errors in an error log, false otherwise
     */
    inline bool hasErrors() const { return _hasErrors; }

    /**
     * \brief Accessor to an error log.
     * 
     * \return Vector of strings that contains all errors collected
     * during evaluating operations.
     */
    inline const std::vector<std::string>& getErrorLog() const
    { return _errorLog; }

    /**
     * \brief Accessor to an operation log.
     * 
     * \return All operations log in string form.
     */
    inline const std::string& getOperationLog() const
    { return _operationLog; }

    /**
     * \brief Replaces operation log with one passed by an argument.
     * 
     * \param newOpLog New operation log.
     */
    inline void setOperationLog(const std::string& newOpLog)
    { _operationLog = newOpLog; }

    /**
     * \brief Replaces operation log with one passed by an argument.
     *
     * Rvalue version.
     *
     * \param newOpLog New operation log in form of an rvalue.
     */
    inline void setOperationLog(std::string&& newOpLog)
    { _operationLog = std::move(newOpLog); }

    /**
     * \brief Accessor to the last result vector.
     * 
     * Some operations return singular value (i.e. RandomOperation) so
     * last result will be vector of 1 length containing that number.
     * Other operations (like RepeatOperation) return multiple integers.
     *
     * \return Vector of ints that contains last operation results.
     */
    inline const std::vector<int>& getLastResult() const
    { return _lastResult; }

    /**
     * \brief Method for appending last result vector.
     * 
     * \param number Integer value to append to the last result vector.
     */
    inline void appendLastResult(int number)
    { _lastResult.push_back(number); }

    /**
     * \brief Method for appending last result vector.
     *
     * \param vector Vector to be inserted at the end of last result vector.
     */
    inline void appendLastResult(const std::vector<int> &vector)
    { _lastResult.insert(_lastResult.end(), vector.begin(), vector.end()); }
    
    /**
     * \brief Setter for the last result.
     */
    inline void setLastResult(std::vector<int> &newResult)
    { _lastResult = newResult; }

    /**
     * \brief Setter for the last result.
     * 
     * Rvalue version.
     */
    inline void setLastResult(std::vector<int>&& newResult)
    { _lastResult = std::move(newResult); }
};


#endif // ROLLRESULT_H
