#include <gtest/gtest.h>
#include <picommons/constants.h>
#include <picommons/pinhelper.h>

// Demonstrate some basic assertions.
TEST(PinHelperTest, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(picommons::VERSION_MINOR, 1);
}