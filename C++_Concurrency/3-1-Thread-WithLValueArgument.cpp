#include <iostream>
#include <thread>

// Pass by value. Here, the argument can's be reference like std::string &str.
void printString(std::string str)
{
    const void* str_addr = static_cast<const void*>((str.c_str()));
    std::cout << "Address of str in printString() is " << str_addr << "\n";

    std::cout << "printString : " << str << "\n";
}

int main(void)
{
    // Pass by value.
    std::string str("Hello World");
    const void* str_addr = static_cast<const void*>((str.c_str()));
    std::cout << "Address of str in main() is " << str_addr << "\n";

    std::thread testTh(printString, "Hello World");
    testTh.join();

    return 0;
}

// Running Result
// -------------------------------------------------------
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ ./a.out 
// Address of str in main() is 0xffffec8e19e8
// Address of str in printString() is 0xffffa657e748
// printString : Hello World
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$
// -------------------------------------------------------
