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

  GPIO g = 2;

  EXPECT_EQ(g.getPin(), 8);

  EXPECT_TRUE(Display::factory(Display::Type::LCD1602, {GPIO(2), GPIO(3), GPIO(4), GPIO(7), GPIO(8), GPIO(12)}));

  EXPECT_TRUE(Display::factory(Display::Type::LCD1602, vector<GPIO>{2, 3, 4, 7, 8, 12}));
}
