#include <iostream>
#include <thread>

// std::thread t(FuncNmae, std::ref(argument))

// Pass by reference.
void printString_1(std::string &str)
{
    const void* str_addr = static_cast<const void*>((str.c_str()));
    std::cout << "Address of str in printString_1() is " << str_addr << "\n";

    std::cout << "printString_1() with reference : " << str << "\n";
}

void printString_2(const std::string &str)
{
    std::cout << "printString_2() with [const] reference : " << str << "\n";
}

void modifyStringRef(std::string &inStr)
{
    std::cout << "modifyStringRef() : Input str before modifying is : " << inStr << "\n";
    inStr = "Momo is daddy!";
    std::cout << "modifyStringRef() : Input str after modifying is  : " << inStr << "\n";
}

int main(void)
{
    std::string str1{"Hello World"};

    const void* str1_addr = static_cast<const void*>((str1.c_str()));
    std::cout << "Address of str1 in main() is " << str1_addr << "\n";
    // Running Result
    // Address of str1 in main() is 0xffffd73614a8
    // Address of str in printString_1() is 0xffffd73614a8

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
    // --------------------------------------------
    // std::thread testTh_3(modifyStringRef, str3);
    // --------------------------------------------
    // because you can't directly use the variable name as reference for a thread, like normally
    // you can do to a normal function. 
    // ----------------------------------------------------------------------------------------
    std::thread testTh_3(modifyStringRef, std::ref(str3));
    testTh_3.join();
    std::cout << "In main() - str3 = " << str3 << "\n";
    std::cout << "In main() - After thread_3 join().\n";

    return 0;
}

