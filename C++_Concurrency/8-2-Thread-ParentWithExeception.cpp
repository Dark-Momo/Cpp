#include <iostream>
#include <thread>

void HelloWorld()
{
    std::cout << "In HelloWorld().\n";
}

int main()
{
    try
    {
	std::thread th{HelloWorld};
	
	/* join()_1 */
	// th.join();

        throw std::exception();
        
	/* join_2 */
	th.join();
    }
    catch(std::exception & e)
    {
        /* join_3 */
	// th.join();
        
	std::cout << "In HelloWorld() - Exception caught : " << e.what() << "\n";
    }

    return 0;
}  
