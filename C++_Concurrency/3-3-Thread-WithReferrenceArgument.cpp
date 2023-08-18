#include <iostream>
#include <thread>

// Pass by reference.
void printString_1(std::string &str)
{
    std::cout << "printString with reference : " << str << "\n";
}

void printString_2(const std::string &str)
{
    std::cout << "printString with const reference : " << str << "\n";
}

void modifyStringRef(std::string &inStr)
{
    std::cout << "modifyStringRef : Input str before modifying is : " << inStr << "\n";
    inStr = "Momo is daddy!";
    std::cout << "modifyStringRef : Input str after modifying is  : " << inStr << "\n";
}

int main(void)
{
    std::cout << "In main() - Before creating thread.\n";

    std::string str1{"Hello World"};
    std::thread testTh_1(printString_1, std::ref(str1));
    testTh_1.join();

    std::cout << "In main() - After thread_1 join().\n";

    std::string str2{"Hello Momo"};
    std::thread testTh_2(printString_2, std::cref(str2));
    testTh_2.join();

    std::cout << "In main() - After thread_2 join().\n";

    std::string str3{"Original String"};
    // ----------------------------------------------------------------------------------------
    // Below will have a lot of compilation error.
    // 
    // std::thread testTh_3(modifyStringRef, str3);
    //
    // Since you can't directly use the variable name as reference for a thread, like normally
    // you can do to a normal function. 
    // ----------------------------------------------------------------------------------------
    std::thread testTh_3(modifyStringRef, std::ref(str3));
    testTh_3.join();

    std::cout << "In main() - After thread_3 join().\n";

    return 0;
}

