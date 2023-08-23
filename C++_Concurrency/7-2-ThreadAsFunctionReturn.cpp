#include <iostream>
#include <thread>
#include <chrono>

void HelloWorld()
{
    std::cout << "In HelloWorld().\n";
}

std::thread funcReturnThread()
{
    std::cout << "In funcReturnThread() - Creating the thread and sleep 100ms.\n";
    std::thread th{HelloWorld};
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "In funcReturnThread() - Created thread with ID : " << th.get_id() << "\n";
    
    // When returning a thread, compiler will move it for us.
    return th;
    // We don't need to explicitly call "return std::move(th);". Compiler will do it.
}

int main()
{
    std::thread thInMain = funcReturnThread();
    std::cout << "In main() - returned thread ID : " << thInMain.get_id() << "\n";
    
    // main().thInMain has gotten the ownership of the thread created in funcReturnThread().
    // So main() need to join().
    thInMain.join();
    return 0;
}

