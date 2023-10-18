#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>

class Singleton
{
private:
    // --------------------------------------------------------
    // We don't declare a static pointer here even you want it.
    // --------------------------------------------------------
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
    static Singleton * initialize_Singleton();
    // ------------------------------------------------
};

#endif
