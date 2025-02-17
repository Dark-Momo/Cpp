#ifndef STRINGBAD_HPP_
#define STRINGBAD_HPP_

#include <iostream>

class StringBad
{
    private:
        char * str;
        int len;

        static int numSB;

    public:
        StringBad();
	StringBad(const char * s);
        ~StringBad();
	// Friend overloading <<
        friend std::ostream & operator<<(std::ostream & os, const StringBad & p);
};	// Don't forget that there is a ';' at the end of class declaration.

#endif
