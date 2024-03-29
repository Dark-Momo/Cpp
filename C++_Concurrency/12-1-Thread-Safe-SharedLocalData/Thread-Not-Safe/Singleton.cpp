#include "Singleton.hpp"

// Static member function accesses static data member.
// Inside the same class, static member doesn't need ::. 

// Return the address of the ONLY OBJECT of Singleton
Singleton * Singleton::initialize_Singleton()
{
    // We have data race here since several thread may reach here at the same time.
    if (pSingleton == nullptr)
    {
        pSingleton = new Singleton; // This new will call ctor.
    } 
    return pSingleton;
}
