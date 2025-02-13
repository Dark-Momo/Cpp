#include <iostream>
#include <thread>

class TestClass
{
    public:
        void TestFunction(int a) { std::cout << "Input is " << a << std::endl; }
};

int main(void)
{
    TestClass testObj;

    std::thread testThread(&TestClass::TestFunction, &testObj, 2);
    // 1. If the function for the std::thread is a normal non-class function, don't add 'this'
    //    as second argument, otherwise you will get:
    //    'this' may only be used inside a nonstatic member functionC/C++(258)
    // 2. '&testObj' is used to tell where the function, '&TestClass::TestFunction' is in memory;
    
    testThread.join();
    // Below will be executed when join() finishes.
    std::cout << "In main(), after join().\n";

    return 0;
}