#include <iostream>
#include <thread>
#include <mutex>

std::mutex task_mutex;

void printString(std::string str)
{
    for (int i = 0; i < 10; i++)
    {
	// Only gurantees that line itself doesn't interleave.
	// The order of lines may still get mixed.
	task_mutex.lock();
	for (int index = 0; index < 16; index++)
	{
            std::cout << str[index];
	}
	std::cout << "\n";
	task_mutex.unlock();
    }
}

int main(void)
{
    // More treads created below will make you easier to see the interleaved output.
    std::thread testTh1(printString, "Momo is a daddy!");
    std::thread testTh2(printString, "Kuku is a babby!");
    std::thread testTh3(printString, "Today is a good!");
    
    // The order of join() should not matter.
    testTh1.join();
    testTh2.join();
    testTh3.join();

    return 0;
}

// Result:
// 1. Without the Mutex, it will have:
// -----------------------------------------------------
// momo@Parallel-Ubuntu:~/Cpp/C++_Concurrency$ ./a.out
// Momo is a daddy!
// Momo is a daddy!
// MomoKuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// Kuku is a babby!
// is a daddy!
// Momo is a daddy!
// Momo is a daddy!
// Momo is a daddy!
// Momo is a daddy!
// Momo is a daddy!
// Momo is a daddy!
// Momo is a daddy!
// -----------------------------------------------------
// 2. With std::mutex, you never see that.
