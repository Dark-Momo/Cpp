#include <thread>
#include <vector>

#include "Singleton.hpp"

// Initialize the static member of class.
// Since it is a static member, it should be initialized outside the class.
Singleton * Singleton::pSingleton = nullptr;

void task()
{
    Singleton * pInst = Singleton::initialize_Singleton();
    std::cout << "Addr = " << pInst << std::endl;
}

int main(void)
{
    std::vector<std::thread> thArray;
    for (int i = 0; i < 10; i++)
    {
        thArray.push_back(std::thread(task));
    }

    for (auto & th : thArray)
    {
        th.join();
    }

    return 0;
}

// Run result : It returns different address sometimes.
/* 
momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency/12-1-Singleton/Basic$ ./a.out 
Ctor
Addr = 0xffffb0000b70
CtorCtor
Addr = 0xffffa8000b70

Addr = 0xffff98000b70
Addr = 0xffff98000b70
Ctor
Addr = 0xffff90000b70
Ctor
Addr = 0xffffa0000b70
Ctor
Addr = 0xffffac000b70
Addr = 0xffffac000b70
Addr = 0xffffac000b70
Addr = 0xffffac000b70
*/
