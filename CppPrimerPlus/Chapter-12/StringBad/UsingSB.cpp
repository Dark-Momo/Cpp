#include <iostream>

#include "StringBad.hpp"

void PrintWithRef(const StringBad & str);
void PrintWithVal(const StringBad str);

int main(void)
{
    std::cout << "Now starts!\n";

    StringBad OBJ1("Momo");
    StringBad OBJ2("Kukumalu");
    StringBad OBJ3("Midnight");

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

    PrintWithVal(OBJ2);
    std::cout << "OBJ2 after PrintWithRVal() is " << OBJ2 << "\n";
    // Here, PrintWithVal() will create a temporary object to copy OBJ2.
    // When function returns, destructor will be called to process it.
    //
    // (1) If that "delete []str" is enabled in destructor:
    // However, since the str of this temporary is copied by temporary.str = OBJ2.str,
    // deleting this str also deletes the str of OBJ2. Output will be:
    // "
    // In function PrintWithVal().
    // "Kukumalu"
    // "Kukumalu" will be deleted!
    // 2 objects left!
    // OBJ2 after PrintWithRVal() is 
    // "
    // (2) If that "delete []str" is NOT enabled in destructor:
    // Output will be:
    // "
    // In function PrintWithVal().
    // "Kukumalu"
    // "Kukumalu" will be deleted!
    // 2 objects left!
    // OBJ2 after PrintWithRVal() is Kukumalu
    // "
 
    std::cout << "-----------------------------------------------\n";

    std::cout << "Initilize a new OBJ4 with existing OBJ3:\n";

    // Below line will use Default Copy Construtor 
    // since it is INITIALIZING one obj using another existing one. 
    StringBad OBJ4 = OBJ3;	// This line doesn't trigger any constructor defined. So it is using something unkown till now.
    				// Here, OBJ4 and OBJ3 point to the same string.
    std::cout << "OBJ4 is " << OBJ4 << "\n";

    std::cout << "-----------------------------------------------\n";

    std::cout << "Assign a new OBJ5 with existing OBJ1:\n";
    StringBad OBJ5;		// Default constructor.
    // Below line will use Default Assignment Operator!
    OBJ5 = OBJ1;                // No output at all since it is assignment! But what does this assignment do?
                                // Here, OBJ5 and OBJ1 point to the same string.
    std::cout << "OBJ5 is " << OBJ5 << "\n";

    std::cout << "-----------------------------------------------\n";
    std::cout << "Exiting main() now.\n";

    // When an object reaches its life end, such as main exit().
    // Destructor will be called to do cleanup, such as delete them, works.
    // (1) If that "delete []str" is enabled in destructor:
    // -- Deleting OBJ5 will also deleting OBJ1;
    // -- Deleting OBJ4 will also deleting OBJ3;
    // -- OBJ2 has already has an empty string, but its count still exist;
    // So output will be:
    // "
    // Exiting main() now.
    // "Momo" will be deleted!        -- Deleting OBJ5, thus str of OBJ1;
    // 2 objects left!
    // "Midnight" will be deleted!    -- Deleting OBJ4, thus str of OBJ3;
    // 1 objects left!
    // "��g�U" will be deleted!       -- Deleting OBJ3
    // 0 objects left!
    // free(): double free detected in tcache 2
    // Aborted (core dumped)
    // "
    // (2) If that "delete []str" is NOT enabled in destructor:
    // So the output will be:
    // "
    // Exiting main() now.
    // "Momo" will be deleted!
    // 2 objects left!
    // "Midnight" will be deleted!
    // 1 objects left!
    // "Midnight" will be deleted!
    // 0 objects left!
    // "Kukumalu" will be deleted!
    // -1 objects left!
    // "Momo" will be deleted!
    // -2 objects left!
    // "

    return 0;
}

void PrintWithRef(const StringBad & str)
{
    std::cout << "In function PrintWithRef().\n";
    std::cout << "\"" << str << "\"" << "\n";	// str. Can't use 'str.str' here since these 2 functions have no access to str private member.
    // Note here and below function:
    // We are using friend overloaded << (here, the 2nd <<) to output str.
}

void PrintWithVal(const StringBad str)
{
    std::cout << "In function PrintWithVal().\n";
    std::cout << "\"" << str << "\"" << "\n";
}
