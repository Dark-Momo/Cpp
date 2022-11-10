#include <iostream>

int main()
{
    int&& rv = 10; 
    int& lv = rv;
    lv = 20;
    std::cout << rv << "\n";

    return 0;
}
