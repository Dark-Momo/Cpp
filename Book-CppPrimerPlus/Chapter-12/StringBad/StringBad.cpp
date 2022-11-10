#include <cstring>
// In C++, normal C string operations like strcpy(), strlen() will be added with std:: at begin
// and include <cstring>

#include "StringBad.hpp"

int StringBad::numSB = 0;

StringBad::StringBad()
{
    len = 3;
    str = new char[len + 1]; 		// Allocate including '/0' at end
    std::strcpy(str, "C++");
    
    numSB++;
    std::cout << numSB << ":\"" << str << "\" default object created!\n";
}

StringBad::StringBad(const char * s)
{
    
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);

    numSB++;
    std::cout << numSB << ":\"" << str << "\" object created!\n";
}

StringBad::~StringBad()
{
    std::cout << "\"" << str << "\" will be deleted!\n";
    numSB--;
    std::cout << numSB << " objects left!\n";

    // With or without below line make huge difference.
    delete []str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & p)
{
    os << p.str;
    return os;
}
