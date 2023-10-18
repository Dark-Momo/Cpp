#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>

class Singleton
{
private:
    // ---------------------------------------------------------------------
    // We don't declare a static data merber here even you want it.
    //
    // static class members don't have any magical thread-safety properties. 
    // They are simply global variables with fancy names.
    // ---------------------------------------------------------------------
    // static Singleton * pSingleton;

    // Class constructor is private
    Singleton() { std::cout << "Ctor" << std::endl; }

public:
    // Delete copy ctor
    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;

    // Delete Move
    Singleton(const Singleton &&) = delete;
    Singleton & operator=(const Singleton &&) = delete;

    // ------------------------------------------------
    // This can also be a non-member function.
    static Singleton * initialize_Singleton();
    // ------------------------------------------------
};

#endif
