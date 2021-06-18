#include <gtest/gtest.h>
#include <picommons/convenience.h>
using namespace picommons;

#include <iostream>

// Demonstrate some basic assertions.
TEST(ConvenienceTest, BasicAssertions)
{

    int temp = getCPUTemperature();

    std::cout << temp << std::endl;

    EXPECT_GT(temp, 0);
}