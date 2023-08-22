#include <iostream>
#include <thread>
#include <chrono>

void HelloWorld()
{
    std::cout << "In HelloWorld() - Will sleep for 2000ms.\n";
    // Sleep_1
    // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "In HelloWorld() - Done with sleep for 2000ms.\n";
}

// Both argument forms are correctly when real parameter is move().
// void funcWithThread(std::thread inThread)
void funcWithThread(std::thread && inThread)
{
    std::cout << "In funcWithThread - input thread has ID : " << inThread.get_id() << "\n";
    
    inThread.join();
}

int main()
{
    std::cout << "In main() - Before creating the thread.\n";
    std::thread th{HelloWorld};
    std::cout << "In main() - After creating the thread.\n";

    std::cout << "In main() - thread has ID : " << th.get_id() << "\n";

    // Sleep_2
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    funcWithThread(std::move(th));

    return 0;
}

// 1. When passing thread as an argument to a function, it can only be in move() form. It can't be passed by value.
// And the move-from object, main() in this example, no longer owns the thread; and the move-to object, funcWithThread()
// will own the thread. So funcWithThread() need to do join() insidie it.

// 2. Here, in this example, we first construct a thread with HelloWorld(), and then move() this thread to funcWithThread().
// Q : When is this thread itself, the HelloWorld() executed?
// A : When it is constructed at std::thread th{HelloWorld}.
//
// In this example, if you disable Sleep_1, and enable Sleep_2, you will see:
/*
 * momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ ./a.out
 * In main() - Before creating the thread.
 * In main() - After creating the thread.
 * In main() - thread has ID : 281473838477568
 * In HelloWorld() - Will sleep for 2000ms.
 * In HelloWorld() - Done with sleep for 2000ms.
 * In funcWithThread - input thread has ID : 281473838477568
 */
// So HelloWorld() runs earlier than funcWithThread().
// According to CppReference:
// ------------------------------------------------------------------------------------------------------------------------
// Threads begin execution immediately upon construction of the associated thread object (pending any OS scheduling delays),
// starting at the top-level function provided as a constructor argument.
// ------------------------------------------------------------------------------------------------------------------------
