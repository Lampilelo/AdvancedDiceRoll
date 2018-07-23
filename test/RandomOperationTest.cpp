#include <iostream>
#include <memory>

#include "gtest/gtest.h"
#include "DiceRoll/Operations/RandomOperation.hpp"

TEST(RandomOperationTest, ResultsAreInBounds)
{
    auto op = std::make_unique<RandomOperation>(50);
    for (int i = 0; i < 1000; i++)
    {
    	auto result = op->evaluate();
    	EXPECT_GE(50, result->getShortResult()[0]) <<
    	    "Value should be less or equal to 50";
    	EXPECT_LE(1, result->getShortResult()[0]) <<
    	    "Value should be greater or equal to 1";
    }

    op = std::make_unique<RandomOperation>(50, 100);
    for (int i = 0; i < 1000; i++)
    {
    	auto result = op->evaluate();
    	EXPECT_GE(100, result->getShortResult()[0]) <<
    	    "Value should be less or equal to 100";
    	EXPECT_LE(50, result->getShortResult()[0]) <<
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
	EXPECT_EQ(29, result->getShortResult()[0]);
    }

    op.changeSeed(234124);

    for (int i = 0; i < 5; i++)
    {
	auto result = op.evaluate();
	EXPECT_EQ(34, result->getShortResult()[0]);
    }
}

TEST(RandomOperationTest, EvaluateReturnsCorrectRollResult)
{
    RandomOperation op(40);
    op.changeSeed(111111);
    auto result = op.evaluate();
    auto lastResult = result->getShortResult();

    EXPECT_EQ((size_t)1, lastResult.capacity());
    EXPECT_EQ((size_t)1, lastResult.size());
    EXPECT_EQ(35, lastResult[0]);

    EXPECT_EQ("35", result->getFullResult());
    EXPECT_TRUE(result->getErrorLog().empty());
}
