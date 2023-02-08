#include <iostream>
#include <thread>
#include <chrono>

void testFunc()
{
    std::cout << "----- testFunc() : Sleep for 2000ms...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "----- testFunc() : Sleep for 2000ms Done...\n";
    
}

using namespace std::chrono_literals;
/* There are 2 ways to generate something like '2000ms':
 * 1. - Use using namespace std::chrono_literals;
 *    - Use std::this_thread::sleep_for(2000ms);
 * 2. - Use std::this_thread::sleep_for(std::chrono::milliseconds(2000));
*/

int main()
{
    std::cout << "It is in main() now!\n";
    std::cout << "First create the thread.\n";
    
    std::thread th{testFunc};
    // th.join();

    std::cout << "Let main() sleep for 1000ms now...\n";
    // std::this_thread::sleep_for(2000ms);					// OK
    // std::this_thread::sleep_for(std::literals::chrono_literals::1000ms);	// No!
    // std::this_thread::sleep_for(std::chrono_literals::1000ms);		//No!
    
    // std::this_thread::sleep_for(std::chrono_literals::milliseconds(1000));  	// No!
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));		// OK
    std::cout << "Main() finished sleeping for 1000ms now...\n";

    th.join();
    return 0;



}
