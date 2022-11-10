#include <iostream>

#include "StringTest.hpp"

void PrintWithRef(const StringTest & str);
void PrintWithVal(const StringTest str);

int main(void)
{
    std::cout << "Now starts!\n";

    StringTest OBJ1("Momo");
    StringTest OBJ2("Kukumalu");
    StringTest OBJ3("Midnight");

    // std::cout << "We have " << StringBad::numSB << " objects now!\n";
    // You can't access numSB directly since it is private.
    // Compiler says: "UsingSB.cpp:16:43: error: ‘int StringBad::numSB’ is private within this context."

    std::cout << "-----------------------------------------------\n";
    std::cout << "OBJ1 is " << OBJ1 << "\n";
    std::cout << "OBJ2 is " << OBJ2 << "\n";
    std::cout << "OBJ3 is " << OBJ3 << "\n";

    std::cout << "-----------------------------------------------\n";
    PrintWithRef(OBJ1);
    std::cout << "OBJ1 after PrintWithRef() is " << OBJ1 << "\n";

    std::cout << "-----------------------------------------------\n";
    // Copy Constructor first used here since it is passing by value.
    // It needs copy constructor to construct a temporary object of OBJ2.
    PrintWithVal(OBJ2);
    // destructor will al so be used here to delete temporary object.
    std::cout << "OBJ2 after PrintWithRVal() is " << OBJ2 << "\n";
 
    std::cout << "-----------------------------------------------\n";
    std::cout << "Initilize a new OBJ4 with existing OBJ3:\n";

    // Below line will use Copy Construtor Only. No = isn used here. 
    // since it is INITIALIZING one obj using another existing one. 
    StringTest OBJ4 = OBJ3;
    std::cout << "OBJ4 is " << OBJ4 << "\n";

    std::cout << "-----------------------------------------------\n";
    std::cout << "Assign a new OBJ5 with existing OBJ1:\n";
    StringTest OBJ5;		// Default constructor.
    // Below line will use Overloaded Assignment Operator!
    OBJ5 = OBJ1;                // Here, OBJ5 and OBJ1 point to the same string.
    std::cout << "OBJ5 is " << OBJ5 << "\n";

    std::cout << "-----------------------------------------------\n";
    std::cout << "Exiting main() now.\n";

    return 0;
}

void PrintWithRef(const StringTest & str)
{
    std::cout << "In function PrintWithRef().\n";
    std::cout << "\"" << str << "\"" << "\n";	// str. Can't use 'str.str' here since these 2 functions have no access to str private member.
    // Note here and below function:
    // We are using friend overloaded << (here, the 2nd <<) to output str.
}

void PrintWithVal(const StringTest str)
{
    std::cout << "In function PrintWithVal().\n";
    std::cout << "\"" << str << "\"" << "\n";
}
