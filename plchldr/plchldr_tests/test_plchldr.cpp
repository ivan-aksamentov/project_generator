#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <plchldr/plchldr.h>

TEST(Add, adds) {
  const auto actual = add(3, 2);
  const auto expected = 5;
  EXPECT_EQ(expected, actual);
}
