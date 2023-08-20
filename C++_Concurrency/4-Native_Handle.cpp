#include <iostream>
#include <thread>

void helloWorld(void)
{
    std::cout << "Hello World!\n";
}

int main(void)
{
    std::thread testThread(helloWorld); // Run thread immediately. Funtion name can't be overloaded.
    std::cout << "Before join(), native_handle() returns " << testThread.native_handle() << "\n";

    // join() will make main() blockingly wait for child thread to finish here.
    testThread.join();

    std::cout << "After join(), native_handle() returns " << testThread.native_handle() << "\n";

    return 0;
}

