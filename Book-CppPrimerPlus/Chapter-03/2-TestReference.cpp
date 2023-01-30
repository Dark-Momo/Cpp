#include <iostream>

int & testFunc(int & p)
{
    return p;
}

int main(void)
{
    int a = 10;
    int & ref = a;
    std::cout << "First set a = 10. ref is " << a << std::endl;
    a = 20;
    std::cout << "Then set a = 20. ref is " << a << std::endl;

    // ------------------------------------------------------------------------------------------
    std::cout << "Now we pass 'a' to a function that takes and returns reference!" << std::endl;
    std::cout << "1. Define a reference, c_ref, to get its return value." << std::endl;
    int & c_ref = testFunc(a);
    std::cout << "c_ref is " << c_ref << std::endl;
    std::cout << "Now set a = 30." << std::endl;
    a = 30;
    std::cout << "c_ref is " << c_ref << std::endl; // Output : c_ref = 30

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Now set a = 20." << std::endl;
    a = 20;
    std::cout << "2. Define a value, c_val, to get its return value." << std::endl;
    int c_val = testFunc(a);
    std::cout << "c_val is " << c_val << std::endl;
    std::cout << "Now set a = 30." << std::endl;
    a = 30;
    std::cout << "c_val is " << c_val << std::endl; // Output : c_val = 20

    return 0;
}
