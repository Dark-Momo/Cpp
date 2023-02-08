#include <iostream>

int main()
{
    const int NUM = 3;
    const char * sp[NUM] = {"1 - Momo", "2 - Kukumalu", "3 - Hoody"};
    // sp is a pointer, it pointes to an array. That array contains 3 address.

    std::cout << "sp is     : " << sp << std::endl;
    std::cout << "sp + 1 is : " << sp + 1 << std::endl;
    std::cout << "sp + 2 is : " << sp + 2 << std::endl;

    for (int i = 0; i < NUM; i++)
    {
        std::cout << i << " : " << sp[i] << std::endl; 
    }

    return 0;
}
