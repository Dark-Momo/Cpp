#ifndef STRINGTEST_HPP_
#define STRINGTEST_HPP_

#include <iostream>

class StringTest
{
    private:
        char * str;
        int len;

        static int numSB; // This will reside in .data area, shared by all class objects.

    public:
        StringTest();
	StringTest(const char * s);

        // Copy constructor
        StringTest(const StringTest & p);

        // Destructor
        ~StringTest();

        // Member function operator overloading for assignment.
	// This doesn't need to be friend since it is always used in form of "A = B", both are class objects.
        StringTest & operator=(const StringTest & p);
	
        // Friend overloading <<
        friend std::ostream & operator<<(std::ostream & os, const StringTest & p);

};	// Don't forget that there is a ';' at the end of class declaration.

#endif
