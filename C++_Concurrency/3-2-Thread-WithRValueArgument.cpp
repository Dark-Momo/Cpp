#include <iostream>
#include <thread>

// Pass by RValue.
void printString(std::string && str)
{
    const void* str_addr = static_cast<const void*>((str.c_str()));
    std::cout << "Address of str in printString() is " << str_addr << "\n";

    std::cout << "printString() : " << str << "\n";
}

int main(void)
{   
    // Pass by RValue.
    std::string str("Hellow World");

    const void* str_addr = static_cast<const void*>((str.c_str()));
    std::cout << "Address of str in main() is " << str_addr << "\n";
    
    std::cout << "Before std::move(str), str.empty() = " << str.empty() << "\n";

    std::thread testTh(printString, std::move(str));
    // From below running result:
    // std::move() will possibly change the object address, since it will cast the object
    // to be a R-value;
    testTh.join();

    std::cout << "After std::move(str), str.empty() = " << str.empty() << "\n";

    return 0;
}

// Running Result
// --------------------------------------------------
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ ./a.out 
// Address of str in main() is 0xffffc91e22d8
// Before std::move(str), str.empty() = 0
// Address of str in printString() is 0xaaab144b72d8
// printString() : Hellow World
// After std::move(str), str.empty() = 1
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ 
// --------------------------------------------------

