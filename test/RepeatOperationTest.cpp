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
	    result->setFullResult(std::to_string(++count));
	    result->setShortResult(count);
	    return result;
	}
};
int MockOperation::count = 0;
MockOperation baseOp;

// Test to check if repeating even works (without the same result).
TEST(RepeatOperationTest, EvaluateWithPositiveCount)
{
    MockOperation::count = 0;
    RepeatOperation repeatOp(&baseOp , 3);
    
    auto result = repeatOp.evaluate();
    EXPECT_EQ("(1 2 3)", result->getFullResult());
    
    EXPECT_EQ(std::vector<int>({1, 2, 3}), result->getShortResult());
    EXPECT_FALSE(result->hasErrors());
}

TEST(RepeatOperationTest, CantInitializeWithCountLowerThan2)
{
  MockOperation::count = 0;

  ASSERT_ANY_THROW(RepeatOperation(&baseOp, 1));
  ASSERT_ANY_THROW(RepeatOperation(&baseOp, -1));
}

TEST(RepeatOperationTest, RepeatRandomOperation)
{
    RandomOperation op(10);
    RepeatOperation repeatOp(&op, 100);
    auto result = repeatOp.evaluate();

    ASSERT_EQ(100, result->getShortResultSize());
    for(auto item: result->getShortResult()) {
	EXPECT_GE(item, 1);
	EXPECT_LE(item, 10);
    }
}

//TODO: Add test that makes sure that RepeatOperation won't work on
//      multiple value operation, just singular value.

