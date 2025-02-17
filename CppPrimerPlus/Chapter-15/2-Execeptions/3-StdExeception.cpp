#include <iostream>
#include <string>
#include <exception> // for std::exception

class myExeception : public std::exception
{
private:
    std::string myErrorMessage{};
public:
    myExeception(std::string & error) : myErrorMessage{error} 
    {
        std::cout << "Calling Ctor using 'std::string &' of class myExeception.\n";
    }

    // This one will be called.
    myExeception(const char* str) : myErrorMessage{str}
    {
        std::cout << "Calling Ctor using 'const char*' of class myExeception.\n";
    }
    
    // 1. We are re-defining/overriding what() in std::exeception, where what() has prototype
    //    const char* what() const noexcept;
    //    Since it is overriding, we need to keep the function prototype exactly the same in derived class.
    // 2. Keyword 'override' means checking whether this function, in derived class, has a fucntion in base 
    //    class, that has exactly the same prototype. Its purpose is to guarantee it is a overriding function. 
    const char* what() const noexcept override 
    {
        return myErrorMessage.c_str(); 
    }
};

class IntArray
{
private:
    int arrayData[5] {};
public:
    IntArray() {} // No ; here at the end

    int& operator[](const int index)
    {
        if (index < 0 || index >= 5)
	{
	    throw myExeception("Invalid index when accessing IntArray...");
	}

	return arrayData[index];
    } 
};

int main()
{
    IntArray myArray;

    try
    {
        myArray[6];
    }
    catch(const myExeception& execep)
    {
        std::cerr << "Error : " << execep.what() << "\n";
    }
}

