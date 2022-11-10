#include <iostream>
#include <cstring>

#include "String.hpp"

// Initialize static (not static const) data member in its .cpp file.
// See .hpp file for exlanation.
int String::num_obj = 0;

// Default constructor
// See document 'Chapter-12-Summary' for reason of this default constructor and how to match 'delete []' in destructor.
String::String()
{
    len = 0;

    // Form 1:
    str = new char[1];
    str[0] = '\0';
    // Form 2:
    // str = nullptr;

    num_obj++;
    // std::cout << "num_obj++ in default ctor\n";
}

// Constructor using C-Style String.
// It can also be used as implicit conversion function.
String::String(const char * s)
{
    len = std::strlen(s);

    str = new char[len + 1];
    std::strcpy(str, s);

    num_obj++;
    // std::cout << "num_obj++ in ctor for C string.\n";
}

// Copy constructor.
String::String(const String & s)
{
    len = s.len;

    str = new char[len + 1];
    std::strcpy(str, s.str);

    num_obj++;
    // std::cout << "num_obj++ in copy ctor\n";
}

// Destructor
String::~String()
{
    delete [] str;
    num_obj--;
}

// Operator Overloading -------------------------------------------------------

// Return 'String &' for = so that chained assignment s1 = s2 = s3 can be done.
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;

    delete [] str;	// Delete data of current assigned object.

    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);

    return *this;
}

// Assign a C-Style String to String class.
String & String::operator=(const char * st)
{
    delete [] str;

    len = std::strlen(st);
    str = new char[len + 1];
    std::strcpy(str, st);

    return *this;
}

// Modifiable version
char & String::operator[](int i) 
{
    return str[i];
}

// Const version
const char & String::operator[](int i) const
{
    return str[i];
}

// Operator overloading using friend ------------------------------------------
bool operator<(const String & str1, const String & str2)
{
    return (std::strcmp(str1.str, str2.str) < 0);
}

bool operator>(const String & str1, const String & str2)
{
    return (std::strcmp(str1.str, str2.str) > 0);
    // Or using operator '<' just overloaded:
    // return (str2 < str1);
}

bool operator==(const String & str1, const String & str2)
{
    return (std::strcmp(str1.str, str2.str) == 0);
}

// Overloading input/output --------------------------------------------------
std::ostream & operator<<(std::ostream & os, const String & str)
{
    os << str.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & str)
{
    char temp[String::CINLIMIT];
    is.get(temp, String::CINLIMIT);
    if (is)
    {
	std::cout << "Input to String class successful!\n";
        str = temp; // Here, '=' is the overloaded one!
    }

    // Data has been fetched out from input buffer, now we clean it by enumerate through it?
    char c;
    while (is && (c = is.get()) != '\n')
    {
	std::cout << "Overloaded istream is cleaning " << c << " \n";
        continue;
    }

    return is;
}

int String::HowMany()
{
    return num_obj;
}
