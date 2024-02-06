#include <iostream>    // std::cout
#include <future>      // std::packaged_task, std::future
#include <chrono>      // std::chrono::seconds
#include <thread>

int addAfterDelay(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return a + b;
}

int main(void)
{
    // We created a task below, but it didn't really run then.
    std::packaged_task<int(int, int)> pTask(addAfterDelay);
    
    // <Knowledge-5-AsynchronousProgram.txt>
    // Associate a std::future with it to get its value in current thread.
    // This is communication for threads, since pTask here is a task.
    std::future<int> fut = pTask.get_future();

    std::cout << "Before initialize pTask with argument.\n";            // Display immediately.

    // <Knowledge-5-AsynchronousProgram.txt>
    // Here we call this task in current thread. 
    // Under this case, the current calling thread will stop and wait for the new task to finish. 
    // It is like calling a function, it is Synchoronous;
    pTask(4, 5); // Task starts when operator() is called.
    
    std::cout << "Waitinf for result of addition...\n";                 // Display after 2000ms.
    std::cout << "Addition of 4 + 5 is : " << fut.get() << std::endl;   // Display after 2000ms.

    return 0;
}