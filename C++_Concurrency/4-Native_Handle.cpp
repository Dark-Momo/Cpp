#include <iostream>
#include <thread>

// native_handle() returns the thread handle as a pthread_t on POSIX systems,
// or as a HANDLE on Windows. 
// This handle can be used with platform-specific thread management functions. 

void helloWorld(void)
{
    std::cout << "Hello World!\n";
}

int main(void)
{
    std::thread testThread(helloWorld);
    
    // Below shows 3 ways to get thread ID
    std::cout << "native_handle() returns " << testThread.native_handle() << "\n";
    
    // Print the thread ID (POSIX specific)
    pthread_t handle = testThread.native_handle();
    std::cout << "Thread ID: " << handle << std::endl;

    std::cout << "Thread ID: " << testThread.get_id() << std::endl;

    testThread.join();
    std::cout << "After join(), native_handle() returns " << testThread.native_handle() << "\n";

    return 0;
}

// Running Result
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ ./a.out 
// native_handle() returns 281473724117248
// Thread ID: 281473724117248
// Thread ID: 281473724117248
// Hello World!
// After join(), native_handle() returns 0
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ 

