#include <iostream>
#include <thread>
#include <chrono>

void HelloWorld()
{
    std::cout << "Inside HelloWorld() : thread ID : " << std::this_thread::get_id() << "\n";
}

int main()
{
    std::cout << "main() has thread ID : " << std::this_thread::get_id() << "\n";
    
    std::thread testThread(HelloWorld);
    std::cout << "In main() - testThread's ID before join(): " << testThread.get_id() << "\n";
    // Here, testThread and function HelloWorld have the same thread ID

    testThread.join();
    std::cout << "In main() - testThread's ID after join(): " << testThread.get_id() << "\n";

    return 0;

}

// Two active thread will have unique ID, while a active thread may have the same ID as a 
// previous active, but already dead thread.
