#include "random.hpp"
#include <gtest/gtest.h>

TEST(random, randint)
{
    auto i = randint<int>(1, 2);
    ASSERT_GE(i, 1);
    ASSERT_LE(i, 2);
}

TEST(random, randfloat)
{
    auto f = randfloat<double>(0.0, 1.0);
    ASSERT_GE(f, 0.0);
    ASSERT_LE(f, 1.0);
}
