#include "gtest/gtest.h"

#include "DiceRoll/Operations/RollResult.h"
#include "DiceRoll/Operations/RepeatOperation.h"

class MockOperation : public IOperation
{
    static int count;

    std::unique_ptr<RollResult> execute()
	{ return std::make_unique<RollResult>(); }

public:
    MockOperation(): IOperation(nullptr){};
    
    std::unique_ptr<RollResult> evaluate()
	{
	    auto result = std::make_unique<RollResult>();
	    result->setOperationLog(std::to_string(count));
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
