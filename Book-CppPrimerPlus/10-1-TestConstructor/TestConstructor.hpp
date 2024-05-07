#ifndef TESTCONSTRUCTOR_HPP_
#define TESTCONSTRUCTOR_HPP_

#include <string>

class TestClass
{
private:
    std::string m_name;
    int m_val1;
    int m_val2;
public:
    //-------------------------------------------------------------------------------------------------------
    // Default constructor has only 2 forms : Without any arguments, or with All arguments.
    // ------------------------------------------------------------------------------------------------------
    // [Ctor-1] : User Defined Default Constructor With No Arguments
    TestClass();

    // [Ctor-2] : User Defined Default Constructor With All Arguments
    // TestClass(const std::string & name = "DefaultName-2", int val1 = -2, int val2 = -2);

    // ******************************************************************************************************
    // 1. Ctor-1 and Ctor-2 can't be declared at the same time since Ctor-2 actually covers Ctor-1. Otherwise,
    // for "TestClass obj1;", compiler will report:
    // "error: call of overloaded ‘TestClass()’ is ambiguous".

    // 2. When only Ctor-2 is declared and defined, it CAN cover below initialization forms:
    // (1) TestClass obj1;
    // (2) TestClass obj1("NewName");
    // (3) TestClass obj1("NewName", 0);
    // (4) TestClass obj3("NewName", 0, 0);
    // It CAN'T cover below form:
    // (1) TestClass obj5(0);
    // And the compiler compiles well for this case, but has core dump when running.
    // ******************************************************************************************************

    //-------------------------------------------------------------------------------------------------------
    // Below are all explicit user defined constructors.
    //-------------------------------------------------------------------------------------------------------

    // [Ctor-3] : User Defined Explicit Constructor with Partial Arguments
    TestClass(const std::string & name, int val1 = -3, int val2 = -3);
    // ******************************************************************************************************
    // 1. Ctor-3 can't be declared and defined with Ctor-2 because they have the same signature. Otherwise,
    // it will have compilation error:
    // "error: ‘TestClass::TestClass(const string&, int, int)’ cannot be overloaded with"
    // "‘TestClass::TestClass(const string&, int, int)’"

    // 2. When only Ctor-3 is defined, it CAN cover below forms:
    // (1) TestClass obj1("NewName");
    // (2) TestClass obj1("NewName", 0);
    // (3) TestClass obj3("NewName", 0, 0);
    // In other words, Ctor-3 requires the first argument to be provided!
    // It can't cover:
    // (1) TestClass obj1;
    // So you need Ctor-1 to be provided!
    // ******************************************************************************************************
    // As long as any EXPLICIT Ctor is declared and defined, compiler won't provide the default no-argumrnt one.
    // So when you also need this default No-argument Ctor, you need to declare and define it yourself.
    // ******************************************************************************************************

    // [Ctor-4] : User Defined Explicit Constructor with Only One Arguments
    TestClass(int val);
    // ******************************************************************************************************
    // None of the Ctor above can cover the case:
    // (1) TestClass obj1(0);
    // ******************************************************************************************************

    void show();
};

#endif
