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
// Test fixture should be a struct (with public access), or class with public;
class MyClassTest : public ::testing::Test
{
// We need public since in TEST_F() we directly use mc->
public:
    MyClass *mc;
    void SetUp() {
        std::cout << "Class Ctor\n"; 
        mc = new MyClass(100);
    }

    void TearDown() {
        std::cout << "Class Dtor\n"; 
        delete mc;
    }
};
// The purpose of SetUp() is to initialize the object that you want to test, maybe filling some data.
// For example, if you want to test a array, you can use SetUp() to initialize the array.
// TearDown() is more like a destructor, and you may not need anything inside if it is not from nwe().

// 2. TEST() -> TEST_F()
// 3. First argument of TEST_F() is the name of Test Fixture Class name
// 4. Each Test_F() below will have its OWN class construction and destruction!
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