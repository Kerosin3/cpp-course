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

TEST(TestGroupName, Subtest_2)
{
    auto env_variable{"GITHUB_RUN_N"};
    char* ret = getenv(env_variable);
    int patch = atoi(ret);
    ASSERT_EQ(get_build_n(), patch);
}
