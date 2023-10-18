#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>

class Singleton
{
private:
    // A static member is shared by all objects of the class. 
    // All static data is initialized to zero when the first object is created, 
    // if no other initialization is present. 
    // ----------------------------------------------------------------------------------------------------------------
    // We can't put it in the class definition but it can be initialized outside the class.
    // ----------------------------------------------------------------------------------------------------------------
    static Singleton * pSingleton;

    // Class constructor is private
    Singleton() { std::cout << "Ctor" << std::endl; }

public:
    // Delete copy ctor
    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;

    // Delete Move
    Singleton(const Singleton &&) = delete;
    Singleton & operator=(const Singleton &&) = delete;

    // ----------------------------------------------------------------------------------------------------------------
    // By declaring a function member as static, you make it independent of any particular object of the class. 
    // A static member function can be called even if no objects of the class exist and the static functions are 
    // accessed using only the class name and the scope resolution operator ::.

    // A static member function can only access static data member, other static member functions and any other 
    // functions from outside the class.

    // Static member functions have a class scope and they do not have access to the this pointer of the class. 
    // You could use a static member function to determine whether some objects of the class have been created or not.
    static Singleton * initialize_Singleton();
    // ----------------------------------------------------------------------------------------------------------------
};

#endif
