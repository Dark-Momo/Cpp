#include <iostream>
#include <cmath>

// In order for the function’s caller to handle the exception, the call to the current 
// function must be inside a try block, and a matching catch block must be associated. 
// If no match is found, then the caller’s caller (two functions up the call stack) is checked. 
// Similarly, in order for the caller’s caller to handle the exception, the call to the caller 
// must be inside a try block, and a matching catch block must be associated.

// Stack Unwinding - Once an exception is handled, control flow proceeds as normal starting from 
// the end of the matching catch block. All function stacks with calling level below current function
// will be unwinded. Their remaining sentences will not be executed.

// Stack unwinding provides us with some very useful behavior -- if a function does not want to 
// handle an exception, it doesn’t have to. The exception will propagate up the stack until it finds 
// someone who will! This allows us to decide where in the call stack is the most appropriate place 
// to handle any errors that may occur.

double mySqrt(int x)
{
    if (x < 0)
    {
        throw "Input to mySqrt() is negative...\n";
	// This function itself doesan't have try-catch structure for this throw.
	// But it will be, or supposed to be, called from a try block in a higher 
	// level. That try block will have its catch block to process this process. 
    }

    return std::sqrt(x);

}

int main()
{
    std::cout << "-----------------------------------------------------------------------------\n";
    std::cout << "1. Basic try-catch block...\n";
    try
    {
        throw -1;
	// Below line will not be executed since, in try block, once throw got executed,
	// all lines after it (in try block) will not be executed. 
	std::cout << "This is after throw in try block.\n";
    }
    catch(int x)
    {
        std::cerr << "We catched a 'int' thrown of " << x << "\n";
    }
    catch(double x)
    {
        std::cerr << "We catched a 'double' thrown of " << x << "\n";
    } 

    std::cout << "-----------------------------------------------------------------------------\n";
    std::cout << "2. Input a valut for square-root operation : ";
    int x;
    std::cin >> x;
    try
    {
        if (x < 0)
	{
	    throw "You input a negative value, which can't be used to do quare-root operation...\n";
	}
	std::cout << "Square-root of " << x << " is " << std::sqrt(x) << "\n";
    }
    catch(const char * str)
    {
        std::cout << "Error : " << str << "\n";
    }

    std::cout << "-----------------------------------------------------------------------------\n";
    std::cout << "3. Input a value for mySqrt() operation : ";
    int m;
    std::cin >> m;

    try
    {
        double ret = mySqrt(m);
        std::cout << "mySqrt() to " << m << " is " << ret << "\n";
    }
    catch(const char * str)
    {
        std::cerr << "Catch of mySqrt() : " << str << "\n";
    }

    std::cout << "-----------------------------------------------------------------------------\n";
    std::cout << "4. Unhandled exeception example mySqrt(-5) below...\n ";
    std::cout << "The sqrt of -5 is " << mySqrt(-5) << '\n';
    // Output:
    // -------------------------------------------------------------------------------
    // terminate called after throwing an instance of 'char const*'
    // Aborted (core dumped)
    // -------------------------------------------------------------------------------
    // When no exception handler for a function can be found, std::terminate() is called, and the 
    // application is terminated. The operating system will generally notify you that an unhandled 
    // exception error has occurred. How it does this depends on the operating system, but possibilities 
    // include printing an error message, popping up an error dialog, or simply crashing. 

    return 0;
}
