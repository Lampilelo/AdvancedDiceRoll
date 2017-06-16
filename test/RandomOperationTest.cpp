#include <iostream>
#include <memory>

#include "gtest/gtest.h"
#include "DiceRoll/Operations/RandomOperation.hpp"

TEST(RandomOperationTest, InitializesWithOneIntPositive)
{
    std::unique_ptr<RandomOperation> op(new RandomOperation(5));
    
    op->changeSeed(123);
    op->evaluate();
    EXPECT_EQ(1, op->getElements()[0]);

    op.reset(new RandomOperation(10));
    op->changeSeed(123);
    op->evaluate();
    EXPECT_EQ(1, op->getElements()[0]);

    op.reset(new RandomOperation(2143214));
    op->changeSeed(123);
    op->evaluate();
    EXPECT_EQ(2066, op->getElements()[0]);

    op.reset(new RandomOperation(50));
    for (int i = 0; i < 1000; i++)
    {
    	op->evaluate();
    	EXPECT_GE(50, op->getElements()[i]) <<
    	    "Value should be less or equal to 50";
    	EXPECT_LE(1, op->getElements()[i]) <<
    	    "Value should be greater or equal to 1";
    }
}

TEST(RandomOperationTest, ChangeSeedWorks)
{
    RandomOperation op(40);
    op.changeSeed(345235);

    for (int i = 0; i < 5; i++)
    {
	auto result = op.evaluate();
	EXPECT_EQ(18, result->getLastResult()[0]);
    }

    op.changeSeed(234124);

    for (int i = 0; i < 5; i++)
    {
	auto result = op.evaluate();
	EXPECT_EQ(7, result->getLastResult()[0]);
    }
}
