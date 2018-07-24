#include "gtest/gtest.h"

#include "DiceRoll/RollCompare/Comparators.hpp"
#include <vector>
#include <algorithm>

using namespace DiceRoll;

TEST(RollCompareTest_PrioritizeLower, GetSymbol)
{
  PrioritizeLower comp;
  EXPECT_EQ(comp.symbol(), '<');
}

TEST(RollCompareTest_PrioritizeHigher, GetSymbol)
{
  PrioritizeHigher comp;
  EXPECT_EQ(comp.symbol(), '>');
}

TEST(RollCompareTest, SortVector)
{
  PrioritizeLower lower;
  PrioritizeHigher higher;

  std::vector<int> vect({2, 4, 1, 3});

  std::sort(vect.begin(), vect.end(), lower.compare());
  EXPECT_EQ(vect, std::vector<int>({1, 2, 3, 4}));

  std::sort(vect.begin(), vect.end(), higher.compare());
  EXPECT_EQ(vect, std::vector<int>({4, 3, 2, 1}));
}
