#include <iostream>

int main()
{
    // 1. Use a L-Value Ref to modify a R-Value Ref. 
    // When initializing an r-value reference with a literal, a temporary object is constructed 
    // from the literal so that the reference is referencing a temporary object, not a literal value;
    int&& rv = 10; // Will create a temp obj holding 10, and then let rv initialized using it.
    int& lv = rv;
    lv = 20;
    std::cout << rv << "\n"; // Output : 20

    // 2. Directly modify value using R-Value Ref itself.
    int&& r_ref{ 5 };        // because we're initializing an r-value reference with a literal, a temporary with value 5 is created here
    r_ref = 10;
    std::cout << r_ref << '\n'; // Output : 10

    return 0;
}
