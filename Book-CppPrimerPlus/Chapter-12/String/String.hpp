#ifndef STRING_HPP_
#define STRING_HPP_

#include <iostream>

class String
{
    private:
        char * str;
        int len;                        // Length of string without '\0' at its end.
        static int num_obj;             // static member can't intialize at declaration.
        static const int CINLIMIT = 10;	// static const can initialize here at declaration.

    public:
        String();                        // Default constructor.
        String(const char * s);          // Constructor that can also be used as implicit conversion function.
	String(const String & s);        // Copy constructor.

	~String();

	int length() const { return len; };

	// ---------------------------------------- Operator overloading as member ----------------------------------------
        // 1. Overload '='
	// Return 'String &' for = so that chained assignment s1 = s2 = s3 can be done.
	String & operator=(const String & st); // Assigment between class objects.

	// Below assign a C style string to this class.
	// Actually the constuctor with parameter 'const char *' can also achieve this conversion. But it
	// involves construction and destruction of temporary objects.
	// So having a overloaded operator here could make it simple. 
        String & operator=(const char * st);

	// 2. Overload '[]'
	// Below one works with declaration as "String example("C++");"
	// It returns reference of a element, can change the value of String member.
	char & operator[] (int i);

	// Below one works with declaration as "const String example("C++");"
	// 1st 'const' means the returned string element char can't be altered;
	// 2nd 'const' means the invoking String object won't be altered;
	const char & operator[] (int i) const;

	// ---------------------------------------- Operator overloading as friend ----------------------------------------
	// Declare them as friend avoids the situation like:
	// if ("love" == example)
	// If they are not friend, but member, the function should be "if ("love".operator==(answer))".
	// -------------------------------------------------------------------------------------------
	// The implicit conversion doesn't work here since it only applies to parameters, not invoker.
	// -------------------------------------------------------------------------------------------
	//
	// If they are friend, the above case is:
	// if(operator==("love", example))
	// This case works with implicit conversion since "love" is parameter now.
	friend bool operator<(const String & str1, const String & str2);
        friend bool operator>(const String & str1, const String & str2);
        friend bool operator==(const String & str1, const String & str2);

	// Overload of '<<' and '>>' should be friend.
	friend std::ostream & operator<<(std::ostream & os, const String & str);
	friend std::istream & operator>>(std::istream & is, String & str);

	// Static function
	// It doesn't need to be invoked by an object. If public, it can be called by:
	// classname::function().
	//
	// It only access static members.
	static int HowMany();
};

#endif
