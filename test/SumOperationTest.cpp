#include "gtest/gtest.h"

#include "DiceRoll/Operations/RollResult.h"
#include "DiceRoll/Operations/SumOperation.hpp"
#include "DiceRoll/Operations/GetNumberOperation.hpp"
#include "DiceRoll/Operations/RepeatOperation.h"

TEST(SumOperationTest, ThrowInitializeWithNullptr)
{
  EXPECT_ANY_THROW(SumOperation(nullptr));
}

TEST(SumOperationTest, SumOneNumber)
{
  auto numOp = GetNumberOperation(5);
  auto sumOp = SumOperation(&numOp);
  auto result = sumOp.evaluate();

  EXPECT_EQ(result->getShortResult(), std::vector<int>({5}));
  EXPECT_EQ(result->getFullResult(), "5");
}

TEST(SumOperationTest, SumRepeatOperation)
{
  auto numOp = GetNumberOperation(5);
  auto repOp = RepeatOperation(&numOp, 3);
  auto sumOp = SumOperation(&repOp);
  auto result = sumOp.evaluate();

  EXPECT_EQ(result->getShortResult(), std::vector<int>({15}));
  EXPECT_EQ(result->getFullResult(), "(15 (+ (5 5 5)))");
}

TEST(SumOperationTest, RepeatSumOperation)
{
  auto numOp = GetNumberOperation(6);
  auto repOp = RepeatOperation(&numOp, 2);
  auto sumOp = SumOperation(&repOp);
  auto repOpFinal = RepeatOperation(&sumOp, 3);
  auto sumOpFinal = SumOperation(&repOpFinal);
  auto repResult = repOpFinal.evaluate();
  auto sumResult = sumOpFinal.evaluate();

  EXPECT_EQ(repResult->getShortResult(), std::vector<int>(3, 12));
  EXPECT_EQ(repResult->getFullResult(),
            "((12 (+ (6 6))) (12 (+ (6 6))) (12 (+ (6 6))))");

  EXPECT_EQ(sumResult->getShortResult(), std::vector<int>({36}));
  EXPECT_EQ(sumResult->getFullResult(),
            "(36 (+ ((12 (+ (6 6))) (12 (+ (6 6))) (12 (+ (6 6))))))");
}
