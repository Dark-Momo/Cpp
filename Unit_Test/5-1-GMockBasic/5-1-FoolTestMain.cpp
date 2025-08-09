// Below 2 are needed for GMock and Gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include <string>

// Need Mock header file
#include "5-1-MockFoolInterface.hpp"

// ------------------------------------------------------------------------------------------------
// Compile using : g++ xxx.cpp -I/usr/include -lgmock -lgtest -lgmock_main -lgtest_main -pthread
// ------------------------------------------------------------------------------------------------

using ::testing::Return;
using ::testing::Sequence;

// ---------------------------------------------------------------
// TEST(FoolInterfaceTest, Test_1)
// {
// ---------------------------------------------------------------
int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc, argv);
// ---------------------------------------------------------------
    MockFoolInterface mockFoolIntf;

    std::string value = "Hello World";
    // Times(1)的意思是运行一次，
    // WillOnce(Return(value))的意思是第一次运行时把value作为getArbitraryString()方法的返回值
    EXPECT_CALL(mockFoolIntf, getArbitraryString())
                .Times(1)
                .WillOnce(Return(value));
    
    std::string retString = mockFoolIntf.getArbitraryString();
    std::cout << "Returned string is: " << retString << std::endl;

    // Test argument matcher
    EXPECT_CALL(mockFoolIntf, setStringValue(::testing::_));
    // below 2 are all correct.
    // mockFoolIntf.setStringValue(std::ref(value));
    mockFoolIntf.setStringValue(value);

    EXPECT_CALL(mockFoolIntf, setIntValue(::testing::Eq(0), ::testing::Ge(2)));
    mockFoolIntf.setIntValue(0, 2); // Error here since 2nd argument is 1, not >= 2;

    // Test DoAll()
    std::string* a = new std::string("yes");
    std::string* b = new std::string("hello");
    EXPECT_CALL(mockFoolIntf, getParameter(testing::_, testing::_))
                .Times(1)
                .WillOnce(testing::DoAll(testing::Assign(&a, b), testing::Return(1)));
    
    std::cout << "a = " << a << ", b = " << b << "\n";
    int ret = mockFoolIntf.getParameter(a, b);
    std::cout << "a = " << a << ", b = " << b << ", ret = " << ret << "\n";

    // Test InSequence
    Sequence S1, S2;
    EXPECT_CALL(mockFoolIntf, getSize())
                .InSequence(S1, S2) // getSize() is first declared in S1 and S2;
                .WillOnce(Return(1));

    EXPECT_CALL(mockFoolIntf, getValue())
                .InSequence(S1)     // getValue() is declared in S1, after getSize();
                .WillOnce(Return(std::string("Hello World!")));
    
    // Error in below order
    std::cout << "Second: " << mockFoolIntf.getValue() << std::endl;
    std::cout << "First: " << mockFoolIntf.getSize() << std::endl;

    return 0;
}

// 这里其实有两种写法:

// 1. 只有TEST(FoolInterfaceTest, Test_1)这一行，那这个主函数就是个GTest，输出是:
// momo@Ubuntu-Linux-22-04:~/Cpp/Unit_Test/5-1-GMockBasic$ ./a.out 
// Running main() from gmock_main.cc
// [==========] Running 1 test from 1 test suite.
// [----------] Global test environment set-up.
// [----------] 1 test from FoolInterfaceTest
// [ RUN      ] FoolInterfaceTest.Test_1
// Returned string is: Hello World
// [       OK ] FoolInterfaceTest.Test_1 (0 ms)
// [----------] 1 test from FoolInterfaceTest (0 ms total)
// 
// [----------] Global test environment tear-down
// [==========] 1 test from 1 test suite ran. (0 ms total)
// [  PASSED  ] 1 test.

// 2. int main()和::testing::InitGoogleMock()，那这个文件就是个普通的，调用了gmock框架的一些函数的main().
// 它的输出是:
// momo@Ubuntu-Linux-22-04:~/Cpp/Unit_Test/5-1-GMockBasic$ ./a.out 
// Returned string is: Hello World