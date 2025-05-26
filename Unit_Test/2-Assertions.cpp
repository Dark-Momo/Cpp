#include <iostream>
#include <gtest/gtest.h>

// Assertions has 3 types:
// 1. Success;
// 2. Non-fatal failure: test coce of the test case will CONTINUE executions after the failure;
// 3. Fatal failure: test coce of the test case will STOP executions after the failure;

// Assertions have what we have seen previously, ASSERT_TRUE() and ASSERT_FALSE().
// There are also EXPECT_EQ() and ASSERT_EQ():
// (1) They are the same when successful;
// (2) EXPECT_EQ() leads to Non-Fatal failure, while ASSERT_EQ() leads to Fatal failure;

// Failure              Non-Fatal                 Fatal
// True         ---->   EXPECT_TRUE(a == b)       ASSERT_TRUE(a == b)
// False        ---->   EXPECT_FALSE(a == b)      ASSERT_FALSE(a == b)
// Equal        ---->   EXPECT_EQ(a, b)           ASSERT_EQ(a, b)
// Not Equal    ---->   EXPECT_NE(a, b)           ASSERT_NE(a, b)
// LessThan     ---->   EXPECT_LT(a, b)           ASSERT_LT(a, b)
// GreatThan    ---->   EXPECT_GT(a, b)           ASSERT_GT(a, b)

TEST(TestExample, SubTest_1_NonFatalFailure)
{
    EXPECT_EQ(1, 2);
    // Below line got displayed
    std::cout << "After EXPECT_EQ(1, 2)...\n"; 
}

TEST(TestExample, SubTest_2_FatalFailure)
{
    ASSERT_EQ(1, 2);
    // Below line didn't get displayed
    std::cout << "After ASSERT_EQ(1, 2)...\n"; 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Compile : g++ [FineName.cpp] -I/usr/include -lgtest -lgtest_main -pthread