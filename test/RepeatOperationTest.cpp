#include "gtest/gtest.h"

#include "DiceRoll/Operations/RollResult.h"
#include "DiceRoll/Operations/RepeatOperation.h"

class MockOperation : public IOperation
{
    std::unique_ptr<RollResult> execute()
	{ return std::make_unique<RollResult>(); }

public:
    static int count;

    MockOperation(): IOperation(nullptr){};

    // For each evaluate() static int count is incrementing.
    std::unique_ptr<RollResult> evaluate()
	{
	    auto result = std::make_unique<RollResult>();
	    result->setOperationLog(std::to_string(++count));
	    result->setLastResult(count);
	    return result;
	}
};
int MockOperation::count = 0;

TEST(RepeatOperationTest, EvaluateWithPositiveCount)
{
    MockOperation baseOp;
    RepeatOperation repeatOp(&baseOp , 3);
    repeatOp.evaluate();

    FAIL() << "Not implemented";
}
