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
    // place equals sign between _fullResult and _shortResult
    std::string fullResult_;
    
    // every operation should store its result in that variable
    std::vector<int> shortResult_;

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
     * \brief Accessor to an full result.
     * 
     * \return All operations log in string form.
     */
    inline const std::string& getFullResult() const
    { return fullResult_; }

    /**
     * \brief Replaces full result with one passed by an argument.
     * 
     * \param newOpLog New full result.
     */
    inline void setFullResult(const std::string& newOpLog)
    { fullResult_ = newOpLog; }

    /**
     * \brief Replaces full result with one passed by an argument.
     *
     * Rvalue version.
     *
     * \param newOpLog New full result in form of an rvalue.
     */
    inline void setFullResult(std::string&& newOpLog)
    { fullResult_ = std::move(newOpLog); }

    /**
     * \brief Accessor to the short result vector.
     * 
     * Some operations return singular value (i.e. RandomOperation) so
     * short result will be vector of 1 length containing that number.
     * Other operations (like RepeatOperation) return multiple integers.
     *
     * \return Vector of ints that contains short operation results.
     */
    inline const std::vector<int>& getShortResult() const
    { return shortResult_; }

    /**
     * \brief Size of the short result vector.
     */
    inline size_t getShortResultSize() const
    { return shortResult_.size(); }

    /**
     * \brief Method for appending short short vector.
     * 
     * \param number Integer value to append to the short result vector.
     */
    inline void appendShortResult(int number)
    { shortResult_.push_back(number); }

    /**
     * \brief Method for appending short result vector.
     *
     * \param vector Vector to be inserted at the end of short result vector.
     */
    inline void appendShortResult(const std::vector<int> &vector)
    { shortResult_.insert(shortResult_.end(), vector.begin(), vector.end()); }
    
    /**
     * \brief Setter for the short result.
     */
    inline void setShortResult(std::vector<int> &newResult)
    { shortResult_ = newResult; }

    /**
     * \brief Setter for the short result.
     *
     * Sets short result vector to be one length with given value at index 0.
     */
    inline void setShortResult(int newResult)
    {
	shortResult_.clear();
	shortResult_.push_back(newResult);
    }

    /**
     * \brief Setter for the short result.
     * 
     * Rvalue version.
     */
    inline void setShortResult(std::vector<int>&& newResult)
    { shortResult_ = std::move(newResult); }
};


#endif // ROLLRESULT_H
