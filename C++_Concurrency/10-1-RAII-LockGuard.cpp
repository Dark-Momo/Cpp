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
		// This code demonstrates how to use std::lock_guard. 
	        std::lock_guard<std::mutex> lockGuard(myMutex);
                for (int index = 0; index < 18; index++)
                {
                    std::cout << str[index];
                }
		std::cout << "\n";
	        // With std::lock_guard, exception throw will call its destructor to release
		// the mutex. So following thread can still acquire this mutex.
		throw std::exception();
		// ----------------------------------------------------------------------------------
		// Problem of std::lock_guard:
		// With this throw, critical section is over here. BUT! The mutex is not release
		// yet. The mutex is locked until the '}' odf the try block.
		//
		// We can call a unlock() here, but when we meet "}", it will have a double unlock,
		// which may crash the program.
		// ----------------------------------------------------------------------------------

		// Below sleep will only take effect when no throw() statement above.
		// std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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

