#include "gtest/gtest.h"
#include "DiceRoll/Operations/RollResult.h"

TEST(RollResultTest, InitWithEmptyErrorLog)
{
    RollResult rr;
    EXPECT_FALSE(rr.hasErrors());
}

TEST(RollResultTest, CanAppendErrorLog)
{
    RollResult rr;
    for (int i = 0; i < 10; i++)
	rr.appendErrorLog("Error " + std::to_string(i));
    
    for (int i = 0; i < 10; i++)
	EXPECT_EQ("Error " + std::to_string(i), rr.getError(i));
}

TEST(RollResultTest, HasErrorsAfterAppendingErrorLog)
{
    RollResult rr;
    rr.appendErrorLog("Error");

    EXPECT_TRUE(rr.hasErrors());
}

TEST(RollResultTest, GetErrorLogIsWorking)
{
    RollResult rr;
    EXPECT_TRUE(rr.getErrorLog().empty());
}

TEST(RollResultTest, AppendsErrorsWithAnotherRollResult)
{
    RollResult rr_one;
    rr_one.appendErrorLog("Error 0");
    RollResult rr_two;
    rr_two.appendErrorLog("Error 1");
    rr_two.appendErrorLog("Error 2");
    rr_one.append(&rr_two);

    for (int i = 0; i < 3; i++)
	EXPECT_EQ("Error " + std::to_string(i), rr_one.getError(i));
}
