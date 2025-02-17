#include "TestConstructor.hpp"

#include <iostream>

int main(void)
{

    TestClass obj1;
    obj1.show();

    TestClass obj2("NewName");
    obj2.show();

    TestClass obj3("NewName", 0);
    obj3.show();

    TestClass obj4("NewName", 0, 0);
    obj4.show();

    TestClass obj5(0);
    obj5.show();

    return 0;
}
