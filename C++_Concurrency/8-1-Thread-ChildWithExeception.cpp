#include <iostream>
#include <thread>

void HelloWorld()
{
    try
    {
        throw std::exception();
    }
    catch(std::exception & e)
    {
        std::cout << "In HelloWorld() - Exception caught : " << e.what() << "\n";
    }

    // A thread's exception should be handled in the thread itself. Other thread,
    // incluing its parent, can't handle for it.
    // If no suitable handler is found, the whole program will be terminated.

    std::cout << "In HelloWorld() - After try-catch block.\n";
}

int main()
{
    std::thread th{HelloWorld};
    th.join();

    return 0;
}
