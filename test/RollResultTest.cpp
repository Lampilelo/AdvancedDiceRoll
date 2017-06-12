#include "gtest/gtest.h"
#include "DiceRoll/Operations/RollResult.h"

TEST(RollResultTest, InitWithEmptyErrorLog)
{
    RollResult rr;
    EXPECT_FALSE(rr.hasErrors());
}
