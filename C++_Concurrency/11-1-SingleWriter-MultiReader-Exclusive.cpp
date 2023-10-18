#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

int x = 0;
std::mutex rwMutex;

void writer(void)
{
    std::lock_guard<std::mutex> wLockGuard(rwMutex);
    x++;
    // std::cout << "Writer : x = " << x << std::endl;
}

void reader(void)
{
    // Set this mutex also for reader
    // -------------------------------------------------------- 
    std::lock_guard<std::mutex> rLockGuard(rwMutex);
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

// 1. WITH that reader mutex, output is like:
/*
Reader : x = 0
Reader : x = 0
Reader : x = 0
Reader : x = 0
Reader : x = 1
Reader : x = 2
Reader : x = 2
Reader : x = 2
Reader : x = 2
Reader : x = 2
Reader : x = 2
Reader : x = 2
*/

// 2. WITHOUT that reader mutex, output is like:
/*
Reader : x = 0
Reader : x = 0
Reader : x = 0
Reader : x = 0
Reader : x = 1
Reader : x = 1
Reader : x = 1
Reader : x = 2
Reader : x = Reader : x = 2
2
Reader : x = Reader : x = 2
Reader : x = Reader : x = 22
Reader : x = 2
Reader : x = Reader : x = 22
Reader : x = 2
Reader : x = 2
Reader : x = Reader : x = 2
2
Reader : x = 2
Reader : x = Reader : x = 2
2
Reader : x = 2


Reader : x = 2
Reader : x = 2
Reader : x = 2
2
*/
