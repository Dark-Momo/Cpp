#include <iostream>

#include "TableTennisPlayer.hpp"

void printHasTable(TableTennisPlayer & p)	// Base class as parameter.
{
    p.showName();
    std::cout << "Has table?";
    if ( p.getHasTable() )
    {
        std::cout << " Yes.\n";
    }
    else
    {
	std::cout << " No.\n";
    }
}

int main (void)
{
    TableTennisPlayer ttp1("Jian", "Mo", true);
    ttp1.showName();

    TableTennisPlayer ttp2("Yu", "Ku", false);
    ttp2.showName();
    ttp2.setHasTable(true);

    RatedPlayer ttp3(1, "YoKi", "Mo", true);
    printHasTable(ttp3);	// Derived class as passed argument.

    return 0;
}

// 1. Public derivated class object can access the methods of base class object, if these methods are NOT PRIVATE!
//    
// 2. Public derivated class object inherites the private data of base class. But it can't access 
//    these inherited private data directly. If it wants to do so, it need to use base class's public method.
//    This is why we can't directly initialize data member of base portion in devived class constructor. Instead,
//    we need to call the ctor of base class first.
//
// 3. A pointer to base class object can be pointed to derived class. So does a reference. But not versa.
//    The reason is, what base class object has, derived class object also has.
//    
//    So: 
//    (1) If a function has parameters of base class pointer/reference, it can be passed with a derived class pointer/reference.
//    (2) We can use a derived class object to initialize a base class object, since every class will have a copy constructor, which 
//        takes reference of a object of this class as parameter. And we can use derived class reference here as passed argument.
//        See Page 8 of paper version note.
