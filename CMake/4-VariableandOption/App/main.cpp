#include "simpleAdder.hpp"

#include <iostream>

int main()
{
    std::cout << simpleMath::simpleAdder(2, 3);
    std::cout << simpleMath::simpleAdder(2.5f, 3.5f);

    return 0;
}
