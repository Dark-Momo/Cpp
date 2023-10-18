#include "Singleton.hpp" 

// Return the address of the ONLY OBJECT of Singleton
Singleton * Singleton::initialize_Singleton()
{
    // ------------------------------------------------------
    // We declare the static pointer here.
    // Initialize by the first thread executing the function.
    // Since it is static, the object pSingleton points to, 
    // will last as long as the program exists.
    static Singleton * pSingleton = new Singleton;
    // ------------------------------------------------------
    return pSingleton;
}
