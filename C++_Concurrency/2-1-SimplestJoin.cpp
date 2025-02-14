#include <iostream>
#include <thread>

void helloWorld(void)
{
    std::cout << "Hello World!\n";
}

int main(void)
{
    std::cout << "In main(), before creating the thread.\n";
    std::thread testThread(helloWorld);
    std::cout << "In main(), after creating the thread.\n";

    // join() will make main() blocking-wait for child thread to finish here.
    testThread.join();

    // Below will be executed when join() finishes.
    std::cout << "In main(), after join().\n";

    return 0;
}
