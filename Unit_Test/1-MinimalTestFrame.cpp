#include <iostream>
#include <gtest/gtest.h>

TEST(TestName, SubTest_1_CheckSimpleEqual)
{
    EXPECT_TRUE(1 == 1);
}

// Below case will have error:
/* [ RUN      ] TestName.SubTest_2_CheckSimpleNonEqual
/* 1-MinimalTestFrame.cpp:13: Failure
/* Value of: 1 == 2
/*   Actual: false
/* Expected: true
/* [  FAILED  ] TestName.SubTest_2_CheckSimpleNonEqual (0 ms)
*/
/*
TEST(TestName, SubTest_2_CheckSimpleNonEqual)
{
    ASSERT_TRUE(1 == 2);
}
*/

TEST(TestName, SubTest_3_ExpectFalse)
{
    EXPECT_FALSE(1 == 2);
}

int main(int argc, char **argv)
{
    // Below is not from std:: namespace
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Compile : g++ [FineName.cpp] -I/usr/include -lgtest -lgtest_main -pthread