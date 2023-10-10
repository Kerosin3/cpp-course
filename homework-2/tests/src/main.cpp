#include "exampleLib/example_lib.hpp"
#include "test1.hpp"
#include "gtest/gtest.h"
#include <cstdint>
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
TEST(test_converting, test1)
{
    const auto str1{"111.111.111.111"s};
    Filtering filter1(std::cin);
    uint32_t answ = 0x6f6f6f6f;
    ASSERT_EQ(answ, filter1.get_ipv4_int(str1));
}
TEST(test_converting, test2)
{
    const auto str1{"111.111.112.111"s};
    Filtering filter1(std::cin);
    uint32_t answ = 0x6f6f706f;
    ASSERT_EQ(answ, filter1.get_ipv4_int(str1));
}
TEST(test_compare, test1)
{
    uint32_t num1 = 0xFE;
    uint32_t num2 = 0xFF;
    Filtering filter1(std::cin);
    // second is greater = true
    ASSERT_EQ(true, compare_strings(num1, num2));
}
TEST(test_compare, test2)
{
    uint32_t num1 = 0xFF;
    uint32_t num2 = 0xFE;
    Filtering filter1(std::cin);
    // first is greater = false
    ASSERT_EQ(false, compare_strings(num1, num2));
}
TEST(test_compare, test3)
{
    uint32_t num1 = 0xFA'BB'CC'FF;
    uint32_t num2 = 0xAA'BB'CC'FF;
    Filtering filter1(std::cin);
    // first is greater = false
    ASSERT_EQ(false, compare_strings(num1, num2));
}
TEST(test_compare, test4)
{
    uint32_t num1 = 0xFA'BB'CC'FF;
    uint32_t num2 = 0xFA'BF'CC'FF;
    Filtering filter1(std::cin);
    // second is greater = true
    ASSERT_EQ(true, compare_strings(num1, num2));
}
TEST(test_hex_to_int_repr, test5)
{
    Filtering filter1(std::cin);
    uint32_t num1 = 0xAA'BB'CC'FF;
    const auto* str = "170.187.204.255";
    ASSERT_EQ(str, filter1.get_ip_char_repr(num1));
}
TEST(test_comparision, test1)
{
    //"93.179.90.83"
    uint32_t ip_as_uint32 = 0x5D'B3'5A'53;
    ASSERT_EQ(true, filter_by_byte(ip_as_uint32, 83, BytePlace::forth));
}
TEST(test_comparision, test2)
{
    //"93.179.90.83"
    uint32_t ip_as_uint32 = 0x5D'B3'5A'54;
    ASSERT_EQ(false, filter_by_byte(ip_as_uint32, 83, BytePlace::forth));
}
TEST(test_comparision, test3)
{
    //"93.179.90.83"
    uint32_t ip_as_uint32 = 0x5D'B3'5A'53;
    ASSERT_EQ(true, filter_by_byte(ip_as_uint32, 90, BytePlace::third));
}
TEST(test_comparision, test4)
{
    //"93.179.90.83"
    uint32_t ip_as_uint32 = 0x5D'B3'5B'53;
    ASSERT_EQ(false, filter_by_byte(ip_as_uint32, 90, BytePlace::third));
}
