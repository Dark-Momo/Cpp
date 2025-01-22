#include "simpleAdder.hpp"

#include <iostream>

int simpleMath::simpleAdder(int a, int b)
{
    std::cout << "This is int version of simpleMath::simpleAdder()...\n";
    return (a + b);
}

float simpleMath::simpleAdder(float a, float b)
{
    std::cout << "This is float version of simpleMath::simpleAdder()...\n";
    return (a + b);
}

