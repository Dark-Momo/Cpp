// Compile : g++ [FineName.cpp] -I/usr/include -lgtest -lgtest_main -pthread

#include <iostream>
#include <gtest/gtest.h>

class MyClass
{
private:
    int baseValue;
public:
    MyClass(int _bv) : baseValue(_bv) {}
    void Increment(int byValue) { baseValue = baseValue + byValue; }
    int getValue() { return baseValue; }
};

// The problem of below test is you need duplicate of creating the class
TEST(TestMyClass, Inc_by_5)
{
    MyClass mc(100);
    mc.Increment(5);
    EXPECT_EQ(mc.getValue(), 105);
}

TEST(TestMyClass, Inc_by_10)
{
    MyClass mc(100);
    mc.Increment(10);
    EXPECT_EQ(mc.getValue(), 110);
}

int main(int argc, char **argv)
{
    // Below is not from std:: namespace
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}