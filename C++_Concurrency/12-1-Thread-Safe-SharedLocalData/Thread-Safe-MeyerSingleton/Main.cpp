#include <thread>
#include <vector>

#include "Singleton.hpp"

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

// Run result :
/* 1. Address always the same;
 * 2. Ctor only appears ONCE, which means the constructor is called only ONCE, by the first thread; 
*/
