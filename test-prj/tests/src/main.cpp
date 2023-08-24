#include "test1.hpp"
#include "gtest/gtest.h"
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
    ASSERT_TRUE('b' == 'b');
    cout << "continue test after failure" << endl;
}

TEST(TestGroupName, Subtest_3)
{
    int rez = 1;
    auto t1 = TestMe{};
    t1.set_some(rez);
    ASSERT_EQ(t1.get_some(), rez);
    cout << "test pased!" << endl;
}

TEST(Test_classes, Subtest_1)
{
    auto Rectangle1 = Rectangle();
    Rectangle1.get_h();
    Rectangle1.get_w();
    Rectangle1.set_h(10);
    Rectangle1.set_w(15);
    Rectangle1.set_area();
    ASSERT_EQ(Rectangle1.get_area(), 150);
    ASSERT_EQ(Rectangle1.return_my_shape(), ShapeType::rectangle);
}

TEST(Test_classes, Subtest_2)
{
}