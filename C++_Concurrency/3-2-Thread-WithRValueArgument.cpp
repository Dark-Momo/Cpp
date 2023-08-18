#include <iostream>
#include <thread>

// Pass by RValue.
void printString(std::string && str)
{
    std::cout << "printString : " << str << "\n";
}

int main(void)
{
    std::cout << "In main() - Before creating thread.\n";
    
    // Pass by RValue.
    std::string str("Hellow World");
    std::cout << "Before std::move(str), str.empty() = " << str.empty() << "\n";

    std::thread testTh(printString, std::move(str));
    testTh.join();

    std::cout << "After std::move(str), str.empty() = " << str.empty() << "\n";

    std::cout << "In main() - After thread join().\n";

    return 0;
}

