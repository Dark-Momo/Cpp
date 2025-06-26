#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "A.h"
#include "MockDatabase.h"
// ------------------------------------------------------------------------------------------------
// Compile using : g++ A_Test.cpp -I/usr/include -lgmock -lgtest -lgmock_main -lgtest_main -pthread
// ------------------------------------------------------------------------------------------------

using ::testing::Return;
using ::testing::StrEq;

TEST(ATest, InitializeSuccess) 
{
    MockDatabase mock_db;

    // 1. We defined a interface class, Database, which has 2 methods but without implementation so that
    //    we can't really call them.
    //    This maybe due to dependency issue, IP property issue, or just not be developed yet;
    // 2. we have class A which will use these interface. But, again, we don't have the implementation
    // of the interface. How to use them?
    // ---->
    // 3. We define a Mock Class that will fake the input - output of needed interface 

    // Set expectation：
    // Mock class's Connect() will be only called once，with argument "localhost"，and it will return true;
    EXPECT_CALL(mock_db, Connect(StrEq("localhost")))
                .Times(1)
                .WillOnce(Return(true));

    A a(&mock_db);
    bool result = a.Initialize("localhost");
    // Initialize() here will call connect() once, with argument "localhost";
    // As set before, connect() here will return true, so that result will be assigned to true;

    // 断言结果
    EXPECT_TRUE(result);
}