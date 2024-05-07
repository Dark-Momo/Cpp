#include "TestConstructor.hpp"
#include <iostream>

TestClass::TestClass()
{
    std::cout << "[Ctor-1 : User Defined Default Constructor With No Arguments] is called...\n";
    m_name = "DefaultName-1";
    m_val1 = -1;
    m_val2 = -1;
}

/*
TestClass::TestClass(const std::string & name, int val1, int val2)
{
    std::cout << "[Ctor-2 : User Defined Default Constructor With All Arguments] is called...\n";
    m_name = name;
    m_val1 = val1;
    m_val2 = val2;
}
*/

TestClass::TestClass(const std::string & name, int val1, int val2)
{
    std::cout << "[Ctor-3 : User Defined Explicit Constructor With Partial Arguments] is called...\n";
    m_name = name;
    m_val1 = val1;
    m_val2 = val2;
}

TestClass::TestClass(int val)
{
    std::cout << "[Ctor-4 : User Defined Default Constructor With Only One Arguments] is called...\n";
    m_name = "DefaultName-4";
    m_val1 = -4;
    m_val2 = val;

}

void TestClass::show()
{
    std::cout << "Show() - " << m_name << "," << m_val1 << "," << m_val2 << "\n";
}
