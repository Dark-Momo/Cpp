#include <iostream>

using std::cout;
using std::endl;

class Stack
{
    private:
        int * mpstack;
        int mtop;
        int msize;

    public:
        // Default Ctor
        Stack(int size = 1000) : msize(size), mtop(0)
        {
	    cout << "Stack(int)" << endl;
	    mpstack = new int[size];
        }
	
        // Dtor
        ~Stack()
        {
	    cout << "~Stack()" << endl;
	    delete [] mpstack;
	    mpstack = nullptr;
        }
	
        // Copy Ctor
        Stack(const Stack &src) : msize(src.msize), mtop(src.mtop)
        {
	    cout << "Stack(const Stack&)" << endl;
	    mpstack = new int[src.msize];
	    for (int i = 0; i < mtop; ++i) 
	    {
	        mpstack[i] = src.mpstack[i];
	    }
        }

	// Move Copy Ctor using R-Value reference
        Stack(Stack &&src) : msize(src.msize), mtop(src.mtop)
        {
            cout << "Stack(const Stack&&)" << endl;
            mpstack = src.mpstack; // Key point here. Direct assignment, no 'new' and data copy!
	    src.mpstack = nullptr;
        }

        // Overloaded Assignment
        Stack& operator=(const Stack &src)
        {
	    cout << "operator=" << endl;
	    if (this == &src)
     	        return *this;

	    delete [] mpstack;

	    msize = src.msize;
	    mtop = src.mtop;
	    mpstack = new int[src.msize];
	    for (int i = 0; i < mtop; ++i) 
	    {
	        mpstack[i] = src.mpstack[i];
	    }
	    return *this;
        }

        // Move assignment using R-Value reference
        Stack& operator=(Stack &&src)
        {
            cout << "operator=(Stack &&)" << endl;
            if (this == &src)
                return *this;

            delete [] mpstack;

            msize = src.msize;
            mtop = src.mtop;
            mpstack = src.mpstack;
	    src.mpstack = nullptr;

            return *this;
        }

        int getSize() 
        {
	    return msize;
        }
};

Stack GetStack(Stack &stack)
{
    Stack tmp(stack.getSize());	// Outout : Stack(int). Call default ctor to construct tmp;
    return tmp;
    // When GetStack() returns, it will call copy constructor to copy the content of tmp to a temporary object,
    // and returns this object to s.
    // Then tmp will be destroyed.
}

// ***************************************** Problem of this code *********************************************
// This code calls copy constructor, and overloaded '=' once for each, and each of them is time consuming.
// And:
// (1) When GetStack() returns, 'tmp' is assigned to a temporary object, and then 'tmp' is destroyed!
// (2) When s = GetStack(s) returns, that temporary object is destroyed!
// ------------------------------------------------------------------------------------------------------------
// So, how about giving tmp to temporary object, and then to s?
// This is the purpose of rvalue reference.
// ------------------------------------------------------------------------------------------------------------

int main()
{
    Stack s;		// Outout : Stack(int). Call default ctor to construct s;
    s = GetStack(s);
    // Here, when above assignment finishes, the temporary object from GetStack() will be destroyed.
    return 0;
    // Here, s will be destroyed.
}

// Need to use "g++ -fno-elide-constructors 1-NormalStack.cpp -o NormalStack" to compile to see un-optimized effect.
// 1. Output when commented out R-Value reference ctor and '=' is :
// parallels@parallels-Parallels-Virtual-Platform:~/CppPrimerPlus/Others/Value$ ./NormalStack
// Stack(int)
// Stack(int)
// Stack(const Stack&)
// ~Stack()
// operator=
// ~Stack()
// ~Stack()
// 
// 2. Output when enabling R-Value reference ctor and '=' is :
// Stack(int)
// Stack(int)
// Stack(const Stack&&)     -- Pass the orignal data section of 'tmp' to temporary object.
// ~Stack()
// operator=(Stack &&)      -- Pass the orignal data section of temporary object to 's'.
// ~Stack()
// ~Stack()

