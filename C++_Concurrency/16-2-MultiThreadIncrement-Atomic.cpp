#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <atomic>

std::atomic<int> data = 0;

void selfIncrement(void)
{
    // data is atomic now, so is "data++". So we don't need lock anymore.
    for (int i = 0; i < 100000; i ++)
    {
        data++;
    }
}

int main(void)
{
    std::vector<std::thread> thVector;

    for (int thCount = 0; thCount < 10; thCount++)
    {
        thVector.push_back( std::move( std::thread(selfIncrement) ) );
    }

    for (auto & th : thVector)
    {
        th.join();
    }

    std::cout << "data = " << data << std::endl;
    return 0;
}
