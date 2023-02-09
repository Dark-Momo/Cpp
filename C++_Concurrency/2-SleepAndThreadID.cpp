#include <iostream>
#include <thread>
#include <chrono>

void testFunc()
{
    std::cout << "----- testFunc() with ID : " << std::this_thread::get_id() << "\n";
    std::cout << "----- testFunc() : Sleep for 2000ms...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "----- testFunc() : Sleep for 2000ms Done...\n";
    
}

using namespace std::chrono_literals;
/* There are 2 ways to generate something like '2000ms':
 * 1. - [C++14]
 *    - Use using namespace std::chrono_literals;
 *    - Use std::this_thread::sleep_for(2000ms);
 * 2. - [C++11] 
 *    - Use std::this_thread::sleep_for(std::chrono::milliseconds(2000));
*/

int main()
{
    std::cout << "It is in main() with ID : " << std::this_thread::get_id() << "\n";
    std::cout << "First create the thread.\n";
    
    std::thread th{testFunc};
    std::cout << "In main(), created thread ID is : " << th.get_id() << "\n";
    // th.join();

    std::cout << "Let main() sleep for 1000ms now...\n";
    // std::this_thread::sleep_for(1000ms);					// OK
    // std::this_thread::sleep_for(std::literals::chrono_literals::1000ms);	// No!
    // std::this_thread::sleep_for(std::chrono_literals::1000ms);		//No!
    
    // std::this_thread::sleep_for(std::chrono_literals::milliseconds(1000));  	// No!
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));		// OK
    std::cout << "Main() finished sleeping for 1000ms now...\n";

    th.join(); // Flow will be blocked at where join() is.
    std::cout << "In main(), after join(), created thread ID is : " << th.get_id() << "\n";
    return 0;



}
