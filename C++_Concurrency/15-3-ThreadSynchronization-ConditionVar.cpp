#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <string>

// Global variable to R/W
std::string sData;

std::mutex rwMutex;
std::condition_variable conditionVar;

using namespace std::chrono_literals;

/* In order to make wait() - notify_one() pair work, wait() must be able to start
 * before notify_one()/all(). 
 * Otherwise, if notify_one() runs first, then wait() starts, wait() will miss the 
 * signal, and wait there forever. - Lost Wakeup.
 */

void Reader(void)
{
    std::cout << "Reader - Going to lock the mutex" << std::endl;
    std::unique_lock<std::mutex> rLock(rwMutex);

    std::cout << "Reader - Going to wait()" << std::endl;
    // This wait() will actually unlock the mutex, making it available for other threads,
    // and THIS thread will then go to sleep on this line;
    conditionVar.wait(rLock);

    std::cout << "Reader - Waked up by notification" << std::endl;
    
    // Here, when outputing data, we don't lock anymore.
    std::cout << "Reader - sData is : " << sData << std::endl;
}

void Writer(void)
{
    {
        std::cout << "Writer - Going to lock the mutex" << std::endl;
        std::lock_guard<std::mutex> wLock(rwMutex);

        // std::cout << "Writer - Going to write data" << std::endl;
        // sData = "This is a kukumalu";
    
        std::cout << "Writer - Going to sleep for 2s" << std::endl;
        std::this_thread::sleep_for(2000ms);

	std::cout << "Writer - Going to write data" << std::endl;
        sData = "This is a kukumalu";
    }

    /* Add this line to make sure wait() starts before notify_one() to avoid 'lost wakeup' */
    std::this_thread::sleep_for(10ms);

    std::cout << "Writer - Going to notify reader" << std::endl;
    conditionVar.notify_one();
}

int main(void)
{
    sData = "Momo";

    std::thread rThread(Reader);
    std::thread wThread(Writer);

    rThread.join();
    wThread.join();

    return 0;
}
