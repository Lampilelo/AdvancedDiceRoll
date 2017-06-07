#include <memory>

#include "gtest/gtest.h"
#include "RandomOperation.hpp"

TEST(RandomOperationTest, InitializesWithOneIntPositive)
{
    std::unique_ptr<RandomOperation> op(new RandomOperation(5));
    
    op->changeSeed(123);
    op->evaluate();
    EXPECT_EQ(1, op->getElements()[0]);

    op.reset(new RandomOperation(10));
    op->changeSeed(123);
    op->evaluate();
    EXPECT_EQ(1, op->getElements()[0]);

    op.reset(new RandomOperation(2143214));
    op->changeSeed(123);
    op->evaluate();
    EXPECT_EQ(2066, op->getElements()[0]);
}
