#include <memory>

#include "gtest/gtest.h"

#include "DiceRoll/Operations/RandomOperation.hpp"
#include "DiceRoll/Operations/RepeatOperation.h"

TEST(MultiOperationTest, DISABLED_PassingRollResultGenericEvaluate)
{
    RandomOperation rand(6);
    rand.changeSeed(2134);
    RepeatOperation repeat(&rand, 4);

    std::unique_ptr<RollResult> result = repeat.evaluate();
    EXPECT_EQ("RandomOperation: 1", result->getErrorLog()[0]);
    EXPECT_EQ("RepeatOperation", result->getErrorLog()[1]);

    // Fail because it's a temporary test.
    FAIL();
}
