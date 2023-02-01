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

	~Holder()
	{
	    std::cout << "Dtor.\n";
	    delete [] pData;
	}

	// Rule of Five related : Move Copy Ctor, Move Assignment Overloaded =.
	// Both are : 
        // (1) Rvalue reference in input; 
        // (2) NO CONST prefix here!
        // No deep copy anymore.
	Holder(Holder&& other)
        {
	    std::cout << "Move Copy Ctor.\n";
            pData = other.pData;   
            iSize = other.iSize;
            // Very important below:
            // You need to release the control of original temporary object, otherwise
            // both pData and other.pData will point to the same resource.
            // If temporary object dies, it will destroy the data! 
	    other.pData = nullptr;
            other.iSize = 0;
        }

	Holder& operator=(Holder&& other)     // <-- rvalue reference in input
        {
	    std::cout << "Move =.\n";
            if (this == &other) 
	    {
	        return *this;
	    }

            delete[] pData;

            pData = other.pData;
            iSize = other.iSize;

            other.pData = nullptr;
            other.iSize = 0;

            return *this;
        }
};
 
Holder createHolder(int n)
{
    Holder tmp(n);
    return tmp;
}

// Different main() version ----------------------------------------------------------------------------------------------------------------

int main()
{
    Holder h = createHolder(2000); // Move constructor (rvalue in input) 

    return 0;
}

// Output is:
// -----------------
// Default Ctor.    -- Construct 'Holder tmp(2000)'.
// Move Copy Ctor.  -- Main stack takes createHolder()'s return value, which is a rvalue (triggers Move Ctor), to constrct a temporary object.
//                  -- Here, createHolder() returns the value of tmp to main stack, and here, the value copy on main stack is nameless, so a rvalue.
//                  -- Then, temporary object is created from this nameless value. So Move Ctor is trigger since its input is R-Value.
//                  -- And the created temporary object is also a R-Value.
// Dtor.            -- tmp destroyed.
// Move Copy Ctor.  -- Main stack use Move Ctor to construct h from temporary object.
// Dtor.            -- Destroy h.
// Dtor.            -- Destroy temporary object.
// -----------------

/*
int main()
{
    Holder h;
    h = createHolder(2000); // Move constructor (rvalue in input) 

    return 0;
}
*/

// Output is:
// -----------------
// Default Ctor.
// Default Ctor.
// Move Copy Ctor.
// Dtor.
// Move =.
// Dtor.
// Dtor.
// -----------------

// ************************************************************************************************************************************************
// Very important here:
// 1. So called "temporary object" from function return by value, is created on main stack by copying the function return value, which is a R-value;
// 2. The temporary object created from the return value, is also a R-Value;

// They are R-Value because no one is to receive them explicitly, and they are unnamed.
//
// Typically rvalues are temporary objects that exist on the stack as the result of a function call or other operation. 
// Returning a value from a function will turn that value into an rvalue. Once you call return on an object, the name 
// of the object does not exist anymore (it goes out of scope), so it becomes an rvalue.
// ************************************************************************************************************************************************
