// We need to call the header file of the library with its full path to use it, 
// if we didn't install the library and its header in previous project "1-SimpleLibrary".

// #include "../2-SimpleLibrary/simpleAdder.hpp"

// However, we do install them in previous project "1-SimpleLibrary".
// So we directly call the name, getting rid of the path dependency.
#include "simpleAdder.hpp" // Call from /usr/local/include/

#include <iostream>

int main()
{
    // Where is the library for simpleMath::simpleAdder()?
    // Define it in CMakeLists.txt file.
    std::cout << simpleMath::simpleAdder(2, 3);
    
    std::cout << simpleMath::simpleAdder(2.5f, 3.5f);
    // You need to have that 'f' at the end of the numbers, otherwise you will have:
    // ------------------------------------------------------------------------------
    // error: call of overloaded ‘simpleAdder(double, double)’ is ambiguous
    // std::cout << simpleMath::simpleAdder(2.5, 3.5);
    // ------------------------------------------------------------------------------
    // Why? Because the argument you give, 2.5 and 3.5, will be double type by GCC,
    // and you only gave 'int' and 'float' for the override.
    // For 'double', 'int' and 'float' has no priority preference when do casting.
    // So GCC will tell you it can't make decision. 

    return 0;
}
