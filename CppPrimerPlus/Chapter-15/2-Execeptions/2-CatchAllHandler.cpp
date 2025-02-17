#include <iostream>
#include <cmath>

double mySqrt(double x)
{
    if (x < 0.0)
    {
        throw "mySqrt() Received negative input...\n"; 
    }

    return std::sqrt(x);
}

int main()
{
    std::cout << "1. Test Catch-All Exeception Handler\n";

    double x;
    std::cout << "Input a value to do sqrt() function now : ";
    std::cin >> x;

    try
    {
        double ret = mySqrt(x);
	std::cout << "mySqrt() to " << x << " is " << ret;	
    }
    catch(const char * str)
    {
        std::cerr <<  "Error : " << str;
    }
    // Below catch() never got executed since a C-Style string is not a std::string.
    // And, catch don't do type conversion.
    catch(const std::string & str)
    {
        std::cerr <<  "Error : " << str;
    }
    // The catch-all handler must be placed last in the catch block chain. This is 
    // to ensure that exceptions can be caught by exception handlers tailored to 
    // specific data types if those handlers exist.
    catch(...) // Deal with any unanticipated execeptions.
    {
        std::cerr <<  "In a catch-all handler...\n";
    }

    return 0;
}

