#include <iostream>
#include <thread>
#include <chrono>

void HelloWorld()
{
    std::cout << "Inside HelloWorld() : thread ID is : " << std::this_thread::get_id() << "\n";
}

int main()
{
    std::cout << "In main() -  main() has ID : " << std::this_thread::get_id() << "\n";
    
    std::thread testThread(HelloWorld);
    std::cout << "In main() - return thread HelloWorld()'s ID before join(): " << testThread.get_id() << "\n";

    testThread.join();
    std::cout << "In main() - return thread HelloWorld()'s ID after join(): " << testThread.get_id() << "\n";

    return 0;

}

// Two active thread will have unique ID, while a active thread may have the same ID as a previous active, but already
// dead thread.
