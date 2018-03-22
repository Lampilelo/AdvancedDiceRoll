#include "gtest/gtest.h"

#include "DiceRoll/Operations/RollResult.h"
#include "DiceRoll/Operations/RepeatOperation.h"
#include "DiceRoll/Operations/RandomOperation.hpp"

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

// Test to check if repeating even works (without the same result).
TEST(RepeatOperationTest, EvaluateWithPositiveCount)
{
    MockOperation::count = 0;
    MockOperation baseOp;
    RepeatOperation repeatOp(&baseOp , 3);
    
    auto result = repeatOp.evaluate();
    EXPECT_EQ("(1 2 3)", result->getOperationLog());
    
    std::vector<int> expectedLastResult{1, 2, 3};
    EXPECT_EQ(expectedLastResult, result->getLastResult());
    EXPECT_FALSE(result->hasErrors());
}

TEST(RepeatOperationTest, RepeatRandomOperation)
{
    RandomOperation op(10);
    RepeatOperation repeatOp(&op, 5);
    auto result = repeatOp.evaluate();
    // std::cout << result->getOperationLog();

    ASSERT_EQ(5, result->getLastResultSize());
    for(auto item: result->getLastResult()) {
	EXPECT_GE(item, 1);
	EXPECT_LE(item, 10);
    }
}

//TODO: Add test that makes sure that RepeatOperation won't work on
//      multiple value operation, just singular value.

