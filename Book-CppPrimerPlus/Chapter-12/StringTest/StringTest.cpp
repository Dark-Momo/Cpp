#include <cstring>
// In C++, normal C string operations like strcpy(), strlen() will be added with std:: at begin
// and include <cstring>

#include "StringTest.hpp"

int StringTest::numSB = 0;

StringTest::StringTest()
{
    len = 3;
    str = new char[len + 1]; 		// Allocate including '/0' at end
    std::strcpy(str, "C++");
    
    numSB++;
    std::cout << numSB << ":\"" << str << "\" default object created!\n";
}

StringTest::StringTest(const char * s)
{
    
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);

    numSB++;
    std::cout << numSB << ":\"" << str << "\" object created!\n";
}

// Copy Constructor
StringTest::StringTest(const StringTest & p)
{
    std::cout << "-- Copy Ctor here! --\n";
    len = p.len;
    str = new char[len + 1];
    std::strcpy(str, p.str);

    numSB++;
    std::cout << numSB << ":\"" << str << "\" object created!\n";
}

StringTest::~StringTest()
{
    std::cout << "\"" << str << "\" will be deleted!\n";
    numSB--;
    std::cout << numSB << " objects left!\n";

    // With or without below line make huge difference.
    delete []str;
}

// Member overloading for '=' assignment.
StringTest & StringTest::operator=(const StringTest & p)
{
    std::cout << "-- Overloaded '=' here! --\n";
    // Below 'if'prevent assignment to itself which is pretty important.
    // Details see my paper verson note, or learncpp.com, Chapter 13.15.
    if (this == &p)     // &(reference) as pointer! 
        return *this;	// *this as reference!

    // Delete first snce it may have been pointed to other data.
    delete []str;
    
    len = p.len;
    str = new char[len + 1];
    std::strcpy(str, p.str);

    return *this;
}

std::ostream & operator<<(std::ostream & os, const StringTest & p)
{
    os << p.str;
    return os;
}
