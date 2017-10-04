#include "gtest/gtest.h"
#include "DiceRoll/Operations/RollResult.h"

TEST(RollResultTest, InitWithEmptyErrorLog)
{
    RollResult rr;
    EXPECT_FALSE(rr.hasErrors());
}

TEST(RollResultTest, InitWithEmptyOperationLog)
{
    RollResult rr;
    EXPECT_EQ("", rr.getOperationLog());
}

TEST(RollResultTest, CanAppendErrorLog)
{
    RollResult rr;
    for (int i = 0; i < 10; i++)
	rr.appendErrorLog("Error " + std::to_string(i));

    for (int i = 0; i < 10; i++)
	EXPECT_EQ("Error " + std::to_string(i), rr.getErrorLog()[i]);
}

TEST(RollResultTest, HasErrorsAfterAppendingErrorLog)
{
    RollResult rr;
    rr.appendErrorLog("Error");

    EXPECT_TRUE(rr.hasErrors());
}

TEST(RollResultTest, GetErrorLogInitEmpty)
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
	EXPECT_EQ("Error " + std::to_string(i), rr_one.getErrorLog()[i]);
}

TEST(RollResultTest, CanSetAndGetOperationLog)
{
    RollResult rr;
    rr.setOperationLog("Lorem ipsum");

    EXPECT_EQ("Lorem ipsum", rr.getOperationLog());
}

TEST(RollResultTest, CanAppendLastResult)
{
    RollResult rr;
    rr.appendLastResult(3);
    rr.appendLastResult(2);
    rr.appendLastResult(1);

    auto& lastResult = rr.getLastResult();
    EXPECT_EQ(3, lastResult[0]);
    EXPECT_EQ(2, lastResult[1]);
    EXPECT_EQ(1, lastResult[2]);
}

TEST(RollResultTest, GanSetAndGetLastResult)
{
    RollResult rr;
    std::vector<int> vect = {1, 2};
    rr.setLastResult(vect);

    EXPECT_EQ(1, rr.getLastResult()[0]);
    EXPECT_EQ(2, rr.getLastResult()[1]);
}

TEST(RollResultTest, SetLastResultWithInt)
{
    RollResult rr;
    rr.setLastResult(5);

    EXPECT_EQ(5, rr.getLastResult()[0]);
}

TEST(RollResultTest, AppendLastResultWithVector)
{
    RollResult rr;
    std::vector<int> vect{1, 2, 3};

    rr.appendLastResult(vect);
    ASSERT_EQ(vect, rr.getLastResult());

    rr.appendLastResult(vect);
    vect = rr.getLastResult();
    ASSERT_EQ(1, vect[3]);
    ASSERT_EQ(2, vect[4]);
    ASSERT_EQ(3, vect[5]);
}
