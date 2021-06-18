#include <gtest/gtest.h>
#include <picommons/display.h>
using namespace picommons;

#include <wiringPi.h>

class DisplayTest : public ::testing::Test
{
  virtual void SetUp()
  {
    wiringPiSetupGpio();
  }
};

// Demonstrate some basic assertions.
TEST_F(DisplayTest, BasicAssertions)
{
  EXPECT_TRUE(Display::factory(Display::Type::LCD1602, vector<int>{1, 2, 3, 4, 5, 6}));
}
