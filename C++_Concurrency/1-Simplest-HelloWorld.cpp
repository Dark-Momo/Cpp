#include <iostream>
#include <thread>

void helloWorld(void)
{
    std::cout << "Hello World!\n";
}

int main(void)
{
    std::cout << "In main(), before creating the thread.\n";
    std::thread testThread(helloWorld); // Run thread immediately. Funtion name can't be overloaded.
    std::cout << "In main(), after creating the thread.\n";

    return 0;

    // One possible running result is
    /*
     * In main(), before creating the thread.
     * In main(), after creating the thread.
     * terminate called without an active exception
     * Hello World!
     * Aborted (core dumped)
     */ 

    // main() and the thread doesn't belong to each other. When main() ends, the thread may have endded, or not.
    // Anyway, when main() ends, std::thread's destructor will call std::terminate(), and at this moment, the 
    // thread may still be running.
}
