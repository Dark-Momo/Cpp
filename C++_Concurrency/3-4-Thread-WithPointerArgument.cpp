#include <iostream>
#include <thread>

void printStringPointer(std::string * str)
{
    std::cout << "printString : " << str << "\n";
}

int main(void)
{
    std::cout << "In main() - Before creating thread.\n";
    
    std::string str{"Hello Momo"};
    std::thread testTh(printStringPointer, str);
    testTh.join();

    std::cout << "In main() - After thread join().\n";

    return 0;
}

