#include <iostream>
#include <thread>

void printStringPointer(std::string * str)
{
    // std::cout << "printString : " << str << "\n";
    /* Above will print like:
     * printString : 0xffffd03e8f48
     */
    
    std::cout << "printString : " << *str << "\n"; // Print string correctly.
}

int main(void)
{
    std::cout << "In main() - Before creating thread.\n";
    
    std::string str{"Hello Momo"};
    std::thread testTh(printStringPointer, &str);
    testTh.join();

    std::cout << "In main() - After thread join().\n";

    return 0;
}

