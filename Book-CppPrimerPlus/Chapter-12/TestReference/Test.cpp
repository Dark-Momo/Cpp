#include <iostream>

int f(int & p);

int main(void)
{
    int a = 3;
    int b = f(a);

    a = 4;

    std::cout << a << " " << b << "\n";
}

int f(int & p)
{
    return p;
}
