#include <iostream>
#include <thread>

class TestClass
{
    public:
        void TestFunction(int a) 
        { 
            std::cout << "Will create thread... " << std::endl;
            // Here, show() is member function of the same class where the thread belongs to,
            // so we use 'this' to tell the std::thread whre show() is;
            std::thread testThread(&TestClass::show, this, a);
            testThread.join();
        }

        void show(int a)
        {
            std::cout << "shows " << a << std::endl;
        }
};

int main(void)
{
    TestClass testObj;
    testObj.TestFunction(3);

    std::cout << "In main(), before return...\n";

    return 0;
}