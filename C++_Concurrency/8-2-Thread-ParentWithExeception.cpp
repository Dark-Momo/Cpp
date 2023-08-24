#include <iostream>
#include <thread>

void HelloWorld()
{
    std::cout << "In HelloWorld().\n";
}

int main()
{
    std::thread th{HelloWorld};
    try
    {
	// std::thread th{HelloWorld};

        throw std::exception();
	// When this throw is executed, the stack will be unwinded, so the std::thread obj
	// will be destructed, before it will be join() ( join()_1 ). So, std::terminate() 
	// will be called, to terminate the whole program.
	// 
	// [Solution-1] : Move std::thread th{HelloWorld} outside try block so throw won't be
	// able to unwind it (call its destructor); And enable join_2.
	//
	// [Solution-2] : RAII.
	// 
	// The thread itself, HelloWorld() may, or may not be executed, from test.
	
	/* join_1 */
	th.join();
    }
    catch(std::exception & e) // This catch will not be executed.
    {
	std::cout << "In main() - Catch : Exception caught : " << e.what() << "\n";
        /* join_2 */
        th.join();

    }

    return 0;
} 
