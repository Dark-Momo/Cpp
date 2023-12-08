#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

int data = 0;

// If no guard, the result would be less than 1000000.
std::mutex rwMutex;

void selfIncrement(void)
{
    // 1. Guard can be added here	
    // std::lock_guard<std::mutex> rwGuard(rwMutex);
    for (int i = 0; i < 100000; i ++)
    {
	// 2. Guard can also be added here so every increment is using previous data.
	std::lock_guard<std::mutex> rwGuard(rwMutex);
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
