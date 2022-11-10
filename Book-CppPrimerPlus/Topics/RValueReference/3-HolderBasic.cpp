#include <iostream>

class Holder
{
    private:
        int * pData;
        int iSize;
    public:
        Holder(int size = 0)
	{
	    std::cout << "Default Ctor.\n";
	    pData = new int[size];
	    iSize = size;
	}	

        // Rule of Three realated : Copy ctor, Dtor, and Overloaded assignment.
	Holder(const Holder& other)
        {
	    std::cout << "Regular Copy Ctor.\n";
            pData = new int[other.iSize];
            std::copy(other.pData, other.pData + other.iSize, pData);
            iSize = other.iSize;
        }

	Holder & operator=(const Holder & other)
	{
	    std::cout << "Regular = .\n";
	    if (this == &other)
	    {
	        return *this;
	    }

	    delete [] pData;

	    pData = new int[other.iSize];
            std::copy(other.pData, other.pData + other.iSize, pData);
            iSize = other.iSize;

	    return *this;    
	}
	// The key point of the copy constructor and the assignment operator is that they both receive 
	// a const reference to an object in input and make a copy out of it for the class they belong to.

	~Holder()
	{
	    std::cout << "Dtor.\n";
	    delete [] pData;
	}

        // Some examples:
	// Holder h1(10000); // Regular Constructor.
	// ------------------------------------------------------------------------
        // Holder h2 = h1;   // Copy Constructor! No assignment here!
	// ------------------------------------------------------------------------
        // Holder h3(h1);    // Copy Constructor (alternate syntax)
};

// Below function returns by value. It means, 
Holder createHolder(int n)
{
    // (1).
    return Holder(n);

    // (2).
    // Holder tmp(n);
    // return tmp;

    // (1) and (2) actually have the same call procedure and output!
}

// Different versions of main() ------------------------------------------------------------------------------------------

/*
int main()
{
    Holder h1 = createHolder(1000);
    return 0;
}
*/

// Output is:
// --------------------
// Default Ctor.
// Regular Copy Ctor.
// Dtor.
// Regular Copy Ctor.
// Dtor.
// Dtor.
// --------------------
// Above call procedure:
// 1. createHolder(1000) will first call "Default Ctor" to create the original object Holder(1000);
// 2. Then createHolder(1000) returns. Here, a temporary object, which is R-Value, is created, ON MAIN STACK, using "Regular Copy Ctor";
// 3. When return finishes, the original object, Holder(1000), is destroyed, generating "Dtor."
// 4. Use "Regular Copy Ctor" to do "Holder h1 = temporary object" initialization. 
//    Here, though there is a '=', but actully no assignment is called. IT IS INITIALIZATION USING COPY CTOR!
// 5. main() exits, calling "Dtor" twice to destroy h1 and that temporary object.

// ----------------------------------------------------------------------------------------------------------------------

int main()
{
    Holder h1;
    h1 = createHolder(1000);
    return 0;
}

// Output is:
// --------------------
// Default Ctor.
// Default Ctor.
// Regular Copy Ctor.
// Dtor.
// Regular = .
// Dtor.
// Dtor.
// --------------------

// **********************************************************************************************************************
// THE PROBLEM HERE IS:
// We create a object in function, and use copy constructor to generate a temporary object to return;
// And in main(), we use copy constructor again to do object initialization.
// CREATE ONCE, AND COPY CONSTRUCTOR TWICE!
// **********************************************************************************************************************
