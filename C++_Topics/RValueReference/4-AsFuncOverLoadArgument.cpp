#include <iostream>

void func(int & val)
{
    std::cout << "func(int &) with argument : " << val << "\n";
}

void func(int && val)
{
    std::cout << "func(int &&) with argument : " << val << "\n";
}

int main()
{
    int a  = 10;
    func(a);
    func(10);

    int && r_ref{5};
    func(r_ref); // func(int & val)
    return 0;
}
