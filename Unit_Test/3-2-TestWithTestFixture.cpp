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

// Below is a test fixture class
// 1. Test fixture should be a struct (with public access), or class with public;
class MyClassTest : public ::testing::Test
{
// We need public since in TEST_F() we directly use mc->
public:
    MyClass *mc;
    void SetUp() { mc = new MyClass(100); }
    void TearDown() { delete mc; }
};

// 2. TEST() -> TEST_F()
// 3. First argument of TEST_F() is the name of Test Fixture Class name
// 4. Each Test_F() below will have its own class construction and destruction!
TEST_F(MyClassTest, Inc_by_5)
{
    mc->Increment(5);
    EXPECT_EQ(mc->getValue(), 105);
}

TEST_F(MyClassTest, Inc_by_10)
{
    mc->Increment(10);
    EXPECT_EQ(mc->getValue(), 110);
}

int main(int argc, char **argv)
{
    // Below is not from std:: namespace
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}