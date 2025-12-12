#include <gtest/gtest.h>

double half(double x)
{
  return x / 2;
}

TEST(DoulbeHalf, MyTest)
{
  double x = half(10.0);
  EXPECT_NEAR(x, 5.0, 1e-6);
}

