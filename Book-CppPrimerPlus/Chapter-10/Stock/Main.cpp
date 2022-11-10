#include <iostream>
#include "Stock00.h"
int main()
{
    using std::cout;

    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);		// Explicit Constructor Called; No temporary object here.
    stock1.show();

    Stock stock2 = Stock("Boffo Objects", 2, 2.0);	// Explicit Constructor Called; No temporary object here.			
    stock2.show();

    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;		                        // Assignment, not initialization. NO Constructor Called here, because stock2 already exists.

    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0);	        // Explicit Constructor Called by temporary object, then assign,
    cout << "Revised stock1:\n";			// and then Destructor Called for temporary object.
    stock1.show();

    cout << "Done\n";

    return 0;
}
