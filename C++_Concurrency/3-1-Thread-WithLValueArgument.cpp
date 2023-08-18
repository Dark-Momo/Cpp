#include <iostream>
#include <thread>

// Pass by value. Here, the argument can's be reference like std::string &str.
void printString(std::string str)
{
    std::cout << "printString : " << str << "\n";
}

int main(void)
{
    std::cout << "In main() - Before creating thread.\n";
    // Pass by value.
    std::thread testTh(printString, "Hello World");
    testTh.join();

    std::cout << "In main() - After thread join().\n";

    return 0;
}
