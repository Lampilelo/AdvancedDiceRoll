#include "gtest/gtest.h"

#include "DiceRoll/Operations/RollResult.h"
#include "DiceRoll/Operations/GetNumberOperation.hpp"

TEST(GetNumberOperationTest, InitializeWithIntPositive)
{
    GetNumberOperation numOpPositive(10);
    auto result = numOpPositive.evaluate();
    EXPECT_EQ((size_t)1, result->getLastResult().size());
    EXPECT_EQ(10, result->getLastResult()[0]);
}

TEST(GetNumberOperationTest, InitializeWithIntNegative)
{
    GetNumberOperation numOpNegative(-10);
    auto result = numOpNegative.evaluate();
    EXPECT_EQ((size_t)1, result->getLastResult().size());
    EXPECT_EQ(-10, result->getLastResult()[0]);
}

TEST(GetNumberOperationTest, InitializeWithZero)
{
    GetNumberOperation numOpZero(0);
    auto result = numOpZero.evaluate();
    EXPECT_EQ((size_t)1, result->getLastResult().size());
    EXPECT_EQ(0, result->getLastResult()[0]);
}

TEST(GetNumberOperationTest, InitializeWithMaxInt32)
{
    GetNumberOperation numOpBigPositive(2147483647); //max for int32
    auto result = numOpBigPositive.evaluate();
    EXPECT_EQ((size_t)1, result->getLastResult().size());
    EXPECT_EQ(2147483647, result->getLastResult()[0]);
}

TEST(GetNumberOperationTest, InitializeWithMinInt32)
{
    GetNumberOperation numOpBigNegative(-2147483648); //min for int32
    auto result = numOpBigNegative.evaluate();
    EXPECT_EQ((size_t)1, result->getLastResult().size());
    EXPECT_EQ(-2147483648, result->getLastResult()[0]);
}

TEST(GetNumberOperationTest, EvaluateReturnsCorrectRollResult)
{
    GetNumberOperation numOp(5);
    auto result = numOp.evaluate();

    auto& lastResult = result->getLastResult();
    
    // Should make RollResult with one capacity, because this
    // operation generates only one number
    EXPECT_EQ((size_t)1, lastResult.capacity());
    EXPECT_EQ((size_t)1, lastResult.size());
    EXPECT_EQ(5, lastResult[0]);

    EXPECT_EQ("5", result->getOperationLog());
    EXPECT_TRUE(result->getErrorLog().empty());
}

