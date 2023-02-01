#include <iostream>
#include <thread>

void func(std::string &str)
{
    str = "123";
}

void threadPassByValue(std::string str)
{
    std::cout << str;
}

void threadPassByRef(std::string & str)
{
    str = "xyz";
}

void threadPassByPointer(std::string * str)
{
    *str = "mnq";
}


int main(void)
{
    // Don't use th_value{threadPassByValue("Hello, Create a Thread Pass By Value!\n")}.
    // The ctor of std::thread is 
    // ***********************************************************************
    // template< class Function, class... Args >
    // explicit thread( Function&& f, Args&&... args );
    // ***********************************************************************
    // std::thread constructor take a function pointer, and its parameter separately.
 
   
    // 1. Pass by value for the argument of thread.
    std::cout << "-----------------------------------------------------------\n";	
    std::thread th_value{threadPassByValue, "Hello, Create a Thread Pass By Value!\n"};
    std::cout << "Hello, main(), before ththreadPassByValue join()!\n";
    th_value.join();
    std::cout << "Hello, main(), after threadPassByValue join()!\n";

    std::cout << "-----------------------------------------------------------\n";
    std::string s{"abc"};
    std::cout << "Create a std::string : abc\n";

    // 2. Pass by reference for the argument of thread.

    // Below shows if you pass a string to a function that takes string reference
    // as argument, the passed string is actually passed by reference.
    func(s);
    std::cout << "After passed to func(), s is : " << s << std::endl; 		// Modified to '123'

    // std::ref() must be added, otherwise a bunch of errors!
    // Here, the above rule is not obeyed. It is some kind of special when you pass
    // to a thread constructor. You need to add additionally the std::ref() to 
    // tell compiler explicitly that you are passing by reference.
    std::thread th_reference{threadPassByRef, std::ref(s)};
    th_reference.join();
    std::cout << "After from thread by reference, s is : " << s << std::endl; 	// Modified to 'xyz'

    // ----------------------------------------------------------------------------------------------
    // std::thread normally allow copy and move of its argument.
    // The reason for std::thread doesn't allow passing by reference directly is that this would
    // result in multiple thread to hold the same piece of data, which is not that desired.
    // ----------------------------------------------------------------------------------------------

    // 3. Pass by pointer for the argument of thread.
    std::cout << "-----------------------------------------------------------\n";
    std::thread th_pointer{threadPassByPointer, &s};
    th_pointer.join();
    std::cout << "After from thread by pointer, s is : " << s << std::endl;   // Modified to 'mnq'

    return 0;
}







