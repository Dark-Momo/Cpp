#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <string>

// Global variable to R/W
std::string sData;

std::mutex rwMutex;
std::condition_variable conditionVar;

// Predicate
bool rwPredicate = false;

using namespace std::chrono_literals;

void Reader1(void)
{
    std::cout << "Reader1 - Trying to lock the mutex......" << std::endl;
    std::unique_lock<std::mutex> rLock(rwMutex);
    std::cout << "Reader1 - Successfully lock the mutex!" << std::endl;

    std::cout << "Reader1 - Going to wait() with predicate" << std::endl;
    conditionVar.wait(rLock, [] {return rwPredicate;});

    std::cout << "Reader1 - Waked up by notification, or predicate" << std::endl;
   
    // Here, when outputing data, we don't lock anymore.
    std::cout << "Reader1 - sData is : " << sData << std::endl;
}

void Reader2(void)
{
    std::cout << "Reader2 - Trying to lock the mutex......" << std::endl;
    std::unique_lock<std::mutex> rLock(rwMutex);
    std::cout << "Reader2 - Successfully lock the mutex!" << std::endl;

    std::cout << "Reader2 - Going to wait() with predicate" << std::endl;
    conditionVar.wait(rLock, [] {return rwPredicate;});

    std::cout << "Reader2 - Waked up by notification, or predicate" << std::endl;
   
    // Here, when outputing data, we don't lock anymore.
    std::cout << "Reader2 - sData is : " << sData << std::endl;
}

void Reader3(void)
{
    std::cout << "Reader3 - Trying to lock the mutex......" << std::endl;
    std::unique_lock<std::mutex> rLock(rwMutex);
    std::cout << "Reader3 - Successfully lock the mutex!" << std::endl;

    std::cout << "Reader3 - Going to wait() with predicate" << std::endl;
    conditionVar.wait(rLock, [] {return rwPredicate;});

    std::cout << "Reader3 - Waked up by notification, or predicate" << std::endl;
   
    // Here, when outputing data, we don't lock anymore.
    std::cout << "Reader3 - sData is : " << sData << std::endl;
}

void Writer(void)
{
    {
        std::cout << "Writer - Trying to lock the mutex......" << std::endl;
        std::lock_guard<std::mutex> wLock(rwMutex);
        std::cout << "Writer - Successfully lock the mutex!" << std::endl;
    
        std::cout << "Writer - Going to sleep for 2s" << std::endl;
        std::this_thread::sleep_for(2000ms);

	std::cout << "Writer - Going to write data" << std::endl;
        sData = "This is a kukumalu";

	// Set predicate before issuing notify().
	// If no this line, we still have 'Lost Wakeup'.
	// -----------------------------------------------------------------
	std::cout << "Writer - Going to set predicate to true" << std::endl;
	rwPredicate = true;
	// -----------------------------------------------------------------
    }

    std::cout << "Writer - Going to notify reader" << std::endl;
    conditionVar.notify_one();
}

int main(void)
{
    sData = "Momo";

    // std::thread wThread(Writer);
    
    std::thread rThread1(Reader1);
    std::thread rThread2(Reader2);
    std::thread rThread3(Reader3);

    /* Below line make sure when notify_one() runs, all Reader threads have been in wait() state.
     * Without this line, you may see "This is a kukumalu" more than once.
     * It doesn't mean more than one threads are waked up by notify_one(). It is because notify_one()
     * is called before other threads get into wait() state, so actually they didn't fall into 
     * wait() state. So notify_one() doesn't take effect. See botton for an example.
     */

    // std::this_thread::sleep_for(10ms);
    /* ------------------------------------------------------------------------------------------ */
    
    std::thread wThread(Writer);

    // wThread.join();

    rThread1.join();
    rThread2.join();
    rThread3.join();

    wThread.join();

    return 0;
}

// [Example 1]

/* momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ ./a.out
* Reader1 - Trying to lock the mutex......
* Reader1 - Successfully lock the mutex!
* Reader1 - Going to wait() with predicate
* Reader3 - Trying to lock the mutex......
* Reader3 - Successfully lock the mutex!
* Reader3 - Going to wait() with predicate
* Writer - Trying to lock the mutex......
* Writer - Successfully lock the mutex!
* Writer - Going to sleep for 2s
* Reader2 - Trying to lock the mutex......
* Writer - Going to write data
* Writer - Going to set predicate to true
* Reader2 - Successfully lock the mutex!
* Reader2 - Going to wait() with predicate
* Reader2 - Waked up by notification, or predicate
* Reader2 - sData is : This is a kukumalu
* Writer - Going to notify reader
* Reader1 - Waked up by notification, or predicate
* Reader1 - sData is : This is a kukumalu
^C
* momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$
*/

// Explanation :
// - At the begin, Reader1 and Reader3 fall into wait() with predicate, while Reader2 is not started.
// - Then Writer starts, does its job, and set predicate, and then notify;
// - Then Reader2 starts - It found predicate to be true, so it directly goes to next line, without 
//   falling into wait()! And prints out "This is a kukumalu".

//   Reader2 is not waked up by notify_one(). It actually doesn't goes into wait().
//   Rememeber this : Wait with predicate is the same as:
//   ------------------------------
//   while (!predicate)
//       wait(std::unique_lock());
//   ------------------------------

// - Then between Reader1 and Reader3, Reader1 is wakedup, by notify_one(), printing out "This is a kukumalu".
