#include "gtest/gtest.h"
#include "DiceRoll/Operations/RollResult.h"

TEST(RollResultTest, InitWithEmptyErrorLog)
{
    RollResult rr;
    EXPECT_FALSE(rr.hasErrors());
}

TEST(RollResultTest, InitWithEmptyFullResult)
{
    RollResult rr;
    EXPECT_EQ("", rr.getFullResult());
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

TEST(RollResultTest, CanSetAndGetFullResult)
{
    RollResult rr;
    rr.setFullResult("Lorem ipsum");

    EXPECT_EQ("Lorem ipsum", rr.getFullResult());
}

TEST(RollResultTest, CanAppendShortResult)
{
    RollResult rr;
    rr.appendShortResult(3);
    rr.appendShortResult(2);
    rr.appendShortResult(1);

    auto& lastResult = rr.getShortResult();
    EXPECT_EQ(3, lastResult[0]);
    EXPECT_EQ(2, lastResult[1]);
    EXPECT_EQ(1, lastResult[2]);
}

TEST(RollResultTest, GanSetAndGetShortResult)
{
    RollResult rr;
    std::vector<int> vect = {1, 2};
    rr.setShortResult(vect);

    EXPECT_EQ(1, rr.getShortResult()[0]);
    EXPECT_EQ(2, rr.getShortResult()[1]);
}

TEST(RollResultTest, SetShortResultWithInt)
{
    RollResult rr;
    rr.setShortResult(5);

    EXPECT_EQ(5, rr.getShortResult()[0]);
}

TEST(RollResultTest, AppendShortResultWithVector)
{
    RollResult rr;
    std::vector<int> vect{1, 2, 3};

    rr.appendShortResult(vect);
    ASSERT_EQ(vect, rr.getShortResult());

    rr.appendShortResult(vect);
    vect = rr.getShortResult();
    ASSERT_EQ(1, vect[3]);
    ASSERT_EQ(2, vect[4]);
    ASSERT_EQ(3, vect[5]);
}
