#include <iostream>
#include <thread>
#include <shared_mutex>
#include <chrono>
#include <vector>

// Compafred to [11-1-SingleWriter-MultiReader-Exclusive.cpp], we used std::shared_mutex here, and 
// created std::shared_lock on this mutex for reader, while still exclusive lock for writer.
// 1. In [11-1-SingleWriter-MultiReader-Exclusive.cpp], all 40 threads are exclusive, so thread must 
//    run one after another, so it will take around 4 seconds to finish;
// 2. In this code, 40 reader threads are shared, so they can run concurrently. So this code finishes
//    in a shot that it actually may only take a little more than 100ms in total.

int x = 0;
std::shared_mutex rwMutex;

void writer(void)
{
    // Set EXCLUSIVE mutex for writer
    // -------------------------------------------------------- 
    std::lock_guard<std::shared_mutex> wLockGuard(rwMutex);
    // --------------------------------------------------------
    x++;
    std::cout << "Writer : x = " << x << std::endl;
}

void reader(void)
{
    // Set SHARED mutex for reader
    // -------------------------------------------------------- 
    std::shared_lock<std::shared_mutex> rLockGuard(rwMutex);
    // --------------------------------------------------------
    std::cout << "Reader : x = " << x << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main(void)
{
    // Generate 40 threads.
    std::vector<std::thread> threadVector;
    
    for (int i = 0; i < 20; i++)
    {
        threadVector.push_back(std::thread(reader));
    }

    threadVector.push_back(std::thread(writer));
    threadVector.push_back(std::thread(writer));

    for (int i = 0; i < 20; i++)
    {
        threadVector.push_back(std::thread(reader));
    }

    // Join the generated 40 threads.
    // Here, don't use "auto th" since auto itself will return a copy while thread can't be copied.
    // Both "auto &" and "auto &&" are good here.
    for (auto && th : threadVector)
    {
        th.join();
    }

    return 0;
}
