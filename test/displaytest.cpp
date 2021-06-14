#include <gtest/gtest.h>
#include <picommons/display.h>

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
  EXPECT_TRUE(picommons::Display::factory(picommons::Display::Type::LCD1602, {1, 2, 3, 4, 5, 6}));
}
