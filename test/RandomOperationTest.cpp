#include <iostream>
#include <memory>

#include "gtest/gtest.h"
#include "DiceRoll/Operations/RandomOperation.hpp"

TEST(RandomOperationTest, ResultsAreInBounds)
{
    auto op = std::make_unique<RandomOperation>(50);
    for (int i = 0; i < 1000; i++)
    {
    	op->evaluate();
    	EXPECT_GE(50, op->getElements()[i]) <<
    	    "Value should be less or equal to 50";
    	EXPECT_LE(1, op->getElements()[i]) <<
    	    "Value should be greater or equal to 1";
    }

    op = std::make_unique<RandomOperation>(50, 100);
    for (int i = 0; i < 1000; i++)
    {
    	op->evaluate();
    	EXPECT_GE(100, op->getElements()[i]) <<
    	    "Value should be less or equal to 100";
    	EXPECT_LE(50, op->getElements()[i]) <<
    	    "Value should be greater or equal to 50";
    }
}

TEST(RandomOperationTest, ChangeSeedWorks)
{
    RandomOperation op(40);
    op.changeSeed(345235);

    for (int i = 0; i < 5; i++)
    {
	auto result = op.evaluate();
	EXPECT_EQ(29, result->getLastResult()[0]);
    }

    op.changeSeed(234124);

    for (int i = 0; i < 5; i++)
    {
	auto result = op.evaluate();
	EXPECT_EQ(34, result->getLastResult()[0]);
    }
}

TEST(RandomOperationTest, EvaluateReturnsCorrectRollResult)
{
    RandomOperation op(40);
    op.changeSeed(111111);
    auto result = op.evaluate();
    auto lastResult = result->getLastResult();

    EXPECT_EQ((size_t)1, lastResult.capacity());
    EXPECT_EQ((size_t)1, lastResult.size());
    EXPECT_EQ(35, lastResult[0]);

    EXPECT_EQ("35", result->getOperationLog());
    EXPECT_TRUE(result->getErrorLog().empty());
}
