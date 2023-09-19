// Example of calling try_lock() in a loop until the mutex is locked
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

std::mutex the_mutex;

// 1. lock() is a blocking lock method. It will block until succeed.
// 2. try_lock() is a test-return method. It will immediately return on failure to lock.
//    Typically, if fail, let the thread using try_lock() sleep for a while, and come back
//    to test again.

// This example demonstartes that a single mutex can beused for sync between 2 critical regions.

void task1()
{
	std::cout << "[Task1] Trying to lock the mutex." << std::endl;
	the_mutex.lock();
	std::cout << "[Task1] Has locked the mutex. Will sleep 0.5s only." << std::endl;
	std::this_thread::sleep_for(500ms);
	the_mutex.unlock();
	std::cout << "[Task1] Unlocked the mutex." << std::endl;
}

void task2()
{
	std::this_thread::sleep_for(100ms);
	std::cout << "[Task2] Trying to lock the mutex." << std::endl;
	while (!the_mutex.try_lock()) 
	{
            std::cout << "[Task2] Could not lock the mutex." << std::endl;
	    std::this_thread::sleep_for(100ms);
	}
	std::cout << "[Task2] Has locked the mutex" << std::endl;
	the_mutex.unlock();
}

int main()
{
	std::thread thr1(task1);
	std::thread thr2(task2);
	
	thr1.join();
	thr2.join();
}
