#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex myMutex;

void printString(std::string str)
{
    for (int i = 0; i < 5; i++)
    {
        try {
                // This code demonstrates how to use std::unique_lock. 
		// unique_lock with default argument, as shown here, will block until successfully blocked.
                std::unique_lock<std::mutex> uniLock(myMutex);
                
		for (int index = 0; index < 18; index++)
                {
                    std::cout << str[index];
                }
                std::cout << "\n";

		// If below unlock() doesn't exist, every line will take 1 second since that
		// sleep is part of critical section;
	        uniLock.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        catch(std::exception &e)
        {
            std::cout << "Exception is: " << e.what() << "\n";
        }
    }
}

int main(void)
{
    // More treads created below will make you easier to see the interleaved output.
    std::thread testTh1(printString, "-Momo is a daddy!-");
    std::thread testTh2(printString, "-Kuku is a babby!-");
    std::thread testTh3(printString, "-Today is a good!-");

    // The order of join() should not matter.
    testTh1.join();
    testTh2.join();
    testTh3.join();

    return 0;
}

