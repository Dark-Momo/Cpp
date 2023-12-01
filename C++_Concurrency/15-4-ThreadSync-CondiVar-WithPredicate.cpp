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

// Predicate
bool rwPredicate = false;

using namespace std::chrono_literals;

void Reader(void)
{
    std::cout << "Reader - Trying to lock the mutex......" << std::endl;
    std::unique_lock<std::mutex> rLock(rwMutex);

    std::cout << "Reader - Going to wait() with predicate" << std::endl;
    
    /* In Writer, it is first to set rwPredicate to True, and then do notify().
     * There is some time between these 2 steps. What if wait() here got triggered
     * between these 2 steps? Will it miss the motification?
     * - No! Because wait() with predicate is like a while loop keeping doing wait().
     * - See "Knowledge-2-ThreadsSynchronization.txt" fir this point.
     * - There is always a wait() that can catch this notify().
     */ 
    conditionVar.wait(rLock, [] {return rwPredicate;});

    std::cout << "Reader - Waked up by notification" << std::endl;
   
    // Here, when outputing data, we don't lock anymore.
    std::cout << "Reader - sData is : " << sData << std::endl;
}

void Writer(void)
{
    {
        std::cout << "Writer - Trying to lock the mutex......" << std::endl;
        std::lock_guard<std::mutex> wLock(rwMutex);

        // std::cout << "Writer - Going to write data" << std::endl;
        // sData = "This is a kukumalu";
    
        std::cout << "Writer - Going to sleep for 2s" << std::endl;
        std::this_thread::sleep_for(2000ms);

	std::cout << "Writer - Going to write data" << std::endl;
        sData = "This is a kukumalu";

	// Set predicate before issuing notify().
	// If no this line, we still have 'Lost Wakeup'.
	// -----------------------------------------------------------------
	rwPredicate = true;
	// -----------------------------------------------------------------
    }

    // We need to unlock(), in some way, before we notify().

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
