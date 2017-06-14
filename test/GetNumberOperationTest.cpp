#include "gtest/gtest.h"

#include "DiceRoll/Operations/RollResult.h"
#include "DiceRoll/Operations/GetNumberOperation.hpp"

TEST(GetNumberOperationTest, InitializeWithIntPositive)
{
    GetNumberOperation numOpPositive(10);
    numOpPositive.evaluate();
    ASSERT_EQ(numOpPositive.getCount(), 1);
    ASSERT_EQ(numOpPositive.getElements()[0], 10);
}

TEST(GetNumberOperationTest, InitializeWithIntNegative)
{
    GetNumberOperation numOpNegative(-10);
    numOpNegative.evaluate();
    ASSERT_EQ(numOpNegative.getCount(), 1);
    ASSERT_EQ(numOpNegative.getElements()[0], -10);
}

TEST(GetNumberOperationTest, InitializeWithZero)
{
    GetNumberOperation numOpZero(0);
    numOpZero.evaluate();
    ASSERT_EQ(numOpZero.getCount(), 1);
    ASSERT_EQ(numOpZero.getElements()[0], 0);
}

TEST(GetNumberOperationTest, InitializeWithMaxInt32)
{
    GetNumberOperation numOpBigPositive(2147483647); //max for int32
    numOpBigPositive.evaluate();
    ASSERT_EQ(numOpBigPositive.getCount(), 1);
    ASSERT_EQ(numOpBigPositive.getElements()[0], 2147483647);
}

TEST(GetNumberOperationTest, InitializeWithMinInt32)
{
    GetNumberOperation numOpBigNegative(-2147483648); //min for int32
    numOpBigNegative.evaluate();
    ASSERT_EQ(numOpBigNegative.getCount(), 1);
    ASSERT_EQ(numOpBigNegative.getElements()[0], -2147483648);
}

TEST(GetNumberOperationTest, ShouldntInitWithFloatingPoint)
{
    float number = 32.2f;
    GetNumberOperation numOpFloat(number);
    std::unique_ptr<RollResult> result = numOpFloat.evaluate();
    EXPECT_TRUE(result->hasErrors());
    // EXPECT_EQ(translate("Entered floating point variable"), result.getErrorLog()[0];
}

TEST(GetNumberOperationTest, EvaluateReturnsCorrectRollResult)
{
    GetNumberOperation numOp(5);
    std::unique_ptr<RollResult> result = numOp.evaluate();
    FAIL();
}
