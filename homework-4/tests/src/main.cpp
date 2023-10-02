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
TEST(test_comparision, test2)
{
    // second is greater -> true
    const auto str1{"111.111.111.111"s};
    const auto str2{"111.111.111.112"s};
    ASSERT_TRUE(compare_strings(str1, str2));
}

TEST(test_comparision, test1)
{
    // equals -> false
    const auto str1{"111.111.111.111"s};
    const auto str2{"111.111.111.111"s};
    ASSERT_FALSE(compare_strings(str1, str2));
}

TEST(test_comparision, test3)
{
    // first is greater -> false
    const auto str1{"211.111.111.111"s};
    const auto str2{"111.111.111.111"s};
    ASSERT_FALSE(compare_strings(str1, str2));
}
TEST(test_comparision, test4)
{
    // first is greater -> false
    const auto str1{"186.204.34.46"s};
    const auto str2{"186.46.222.194"s};
    ASSERT_FALSE(compare_strings(str1, str2));
}
TEST(test_comparision, test5)
{
    // second is greater -> true
    const auto str1{"220.42.146.225"s};
    const auto str2{"220.189.194.162"s};
    ASSERT_TRUE(compare_strings(str1, str2));
}
TEST(test_comparision, test6)
{
    // second is greater -> true
    const auto str1{"255.255.255.255"};
    uint32_t rezult = convert(str1);
    ASSERT_EQ(4294967295, rezult);
}
TEST(test_comparision, test7)
{
    // second is greater -> true
    const auto str1{"93.179.90.82"};
    //   5D-B3-5A-52//
    uint32_t anws{0x5DB35A52};
    uint32_t rezult = convert(str1);
    ASSERT_EQ(anws, rezult);
}
TEST(test_comparision, test9)
{
    // second is greater -> true
    const auto str1{"93.179.90.83"};
    //   5D-B3-5A-52//
    uint32_t anws{0x5DB35A53};
    uint32_t rezult = convert(str1);
    ASSERT_EQ(anws, rezult);
}
TEST(test_comparision, test10)
{
    const auto str1{"93.179.90.83"};
    //   5D-B3-5A-53//
    ASSERT_EQ(true, filter_by_byte(str1, 83, BytePlace::forth));
}
TEST(test_comparision, test11)
{
    const auto str1{"93.179.90.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(false, filter_by_byte(str1, 83, BytePlace::forth));
}
TEST(test_comparision, test12)
{
    const auto str1{"93.179.90.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 90, BytePlace::third));
}
TEST(test_comparision, test13)
{
    const auto str1{"93.179.90.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 179, BytePlace::second));
}
TEST(test_comparision, test14)
{
    const auto str1{"93.179.90.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 93, BytePlace::first));
}
TEST(test_comparision, test15)
{
    const auto str1{"93.179.90.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(false, filter_by_byte(str1, 93, BytePlace::forth));
}
TEST(test_comparision, test16)
{
    const auto str1{"90.179.93.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 93, BytePlace::any));
}
TEST(test_comparision, test17)
{
    const auto str1{"92.179.90.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(false, filter_by_byte(str1, 93, BytePlace::any));
}

TEST(test_comparision, test19)
{
    const auto str1{"91.90.93.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 90, BytePlace::any));
}
TEST(test_comparision, test20)
{
    const auto str1{"91.95.90.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 90, BytePlace::any));
}
TEST(test_comparision, test21)
{
    const auto str1{"91.95.99.90"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 90, BytePlace::any));
}
TEST(test_comparision, test18)
{
    const auto str1{"90.179.93.82"};
    //   5D-B3-5A-52//
    ASSERT_EQ(true, filter_by_byte(str1, 90, BytePlace::any));
}
