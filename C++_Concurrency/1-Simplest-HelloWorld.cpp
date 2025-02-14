#include <iostream>
#include <thread>

void helloWorld(void)
{
    std::cout << "Hello World!\n";
}

int main(void)
{
    std::cout << "In main(), before creating the thread.\n";

    // *******************************************************************************
    // 1. std::thread will create and run thread immediately;
    // 2. Funtion name for std::thread can't be overloaded;
    // 3. If taking below as a function, std::thread's return type is also std::thread;
    // *******************************************************************************
    std::thread testThread(helloWorld);
    // 1. For non-class memebr function, function name is enough;
    // 2. For class memeber function, we need & before function name;

    std::cout << "In main(), after creating the thread.\n";

    return 0;
}

// One possible running result is
/*
 * In main(), before creating the thread.
 * In main(), after creating the thread.
 * terminate called without an active exception
 * Hello World!
  Aborted (core dumped)
 */ 

// main() and the thread doesn't belong to each other. When main() ends, the thread may have endded, or not.
// Anyway, when main() ends, std::thread's destructor will call std::terminate(), and at this moment, the 
// thread may still be running.
