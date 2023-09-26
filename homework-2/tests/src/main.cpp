#include "exampleLib/example_lib.hpp"
#include "test1.hpp"
#include "gtest/gtest.h"
#include <cstdlib>
#include <gmock/gmock.h>

using namespace std;

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(TestGroupName, Subtest_1)
{
    ASSERT_TRUE(1 == 1);
}
TEST(test_comparision, test1)
{
    // equals -> false
    const auto str1{"111.111.111.111"s};
    const auto str2{"111.111.111.111"s};
    ASSERT_FALSE(compare_strings(str1, str2));
}
TEST(test_comparision, test2)
{
    // second is greater -> true
    const auto str1{"111.111.111.111"s};
    const auto str2{"111.111.111.112"s};
    ASSERT_TRUE(compare_strings(str1, str2));
}
TEST(test_comparision, test3)
{
    // first is greater -> false
    const auto str1{"211.111.111.111"s};
    const auto str2{"111.111.111.111"s};
    ASSERT_FALSE(compare_strings(str1, str2));
}
