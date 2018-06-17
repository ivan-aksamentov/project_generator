#include <tuple>
#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <plchldr/plchldr.h>


// Plain test
TEST(Add, adds) {
  const auto actual = add(3, 2);
  const auto expected = 5;
  EXPECT_EQ(expected, actual);
}

// Parametrized test
class AddWithParams :
    public testing::TestWithParam<std::tuple<int, int, int>> {};

TEST_P(AddWithParams, adds) {
  int x, y, sum;
  std::tie(x, y, sum) = GetParam();
  EXPECT_EQ(sum, add(x, y));
}

INSTANTIATE_TEST_CASE_P(
    Add,
    AddWithParams,
    ::testing::Values(
        // first arg, second arg, result
        std::make_tuple(0, 0, 0),
        std::make_tuple(2, 3, 5),
        std::make_tuple(2, -3, -1)
    ));
