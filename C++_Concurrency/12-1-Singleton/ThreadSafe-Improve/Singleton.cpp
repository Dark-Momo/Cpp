#include "Singleton.hpp" 

// Return the address of the ONLY OBJECT of Singleton
Singleton * Singleton::initialize_Singleton()
{
    // ------------------------------------------------------
    // We declare the static pointer here.
    // Initialize by the first thread executing the function.
    static Singleton * pSingleton = new Singleton;
    // ------------------------------------------------------
    return pSingleton;
}
