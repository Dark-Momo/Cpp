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
    
    // Associate a std::future with it to get its value in current thread.
    // This is communication for threads, since pTask here is a task.
    std::future<int> fut = pTask.get_future();

    // <Knowledge-5-AsynchronousProgram.txt>
    // 1. It is move-only, can't be copied;
    // 2. In a new thread, passing the task to std::thread's constructor. 
    //    Under this case, the calling thread and the new thread will run concurrently;
    // We put this task into a separate thread.
    std::thread taskTh(std::move(pTask), 4, 5); // Task starts when operator() is called.
    
    std::cout << "Waitinf for result of addition...\n";                 // Display immediately.
    std::cout << "Addition of 4 + 5 is : " << fut.get() << std::endl;   // Display after 2000ms.

    taskTh.join();

    return 0;
}