#include "GetNumberOperation.hpp"
#include "gtest/gtest.h"

//TODO: Break into several tests
TEST(GetNumberOperation, InitializeWithIntegers)
{
    GetNumberOperation numOpPositive(10);
    GetNumberOperation numOpNegative(-10);
    GetNumberOperation numOpZero(0);
    GetNumberOperation numOpBigPositive(2147483647); //max for int32
    GetNumberOperation numOpBigNegative(-2147483648); //min for int32
    numOpPositive.evaluate();
    numOpNegative.evaluate();
    numOpZero.evaluate();
    numOpBigPositive.evaluate();
    numOpBigNegative.evaluate();

    ASSERT_EQ(numOpPositive.getCount(), 1);
    ASSERT_EQ(numOpNegative.getCount(), 1);
    ASSERT_EQ(numOpZero.getCount(), 1);
    ASSERT_EQ(numOpBigPositive.getCount(), 1);
    ASSERT_EQ(numOpBigNegative.getCount(), 1);

    ASSERT_EQ(numOpPositive.getElements()[0], 10);
    ASSERT_EQ(numOpNegative.getElements()[0], -10);
    ASSERT_EQ(numOpZero.getElements()[0], 0);
    ASSERT_EQ(numOpBigPositive.getElements()[0], 2147483647);
    ASSERT_EQ(numOpBigNegative.getElements()[0], -2147483648);
}
