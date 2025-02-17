#include <iostream>

#include "MyTime0.h"

int main(void)
{
    Time planning; 		// Default Constructor
    
    Time coding{2, 30};		// Explicit Constructor
    Time fixing{1, 40};		// Explicit Constructor
    Time total;			// Default Constructor

    std::cout << "planning time = ";
    planning.Show();

    std::cout << "coding time = ";
    coding.Show();

    std::cout << "fixing time = ";
    fixing.Show();

    // total = coding.Sum(fixing);
    
    // total = coding.operator+(fixing);
    
    total = coding + fixing;	// The 3 options here all work. 
    // Above calls Default Constructor.
    // Above is assigning a new value to an existing object.
    // According to Chapter 10's example, here will have a temporary
    // object to hold the valur from 'coding + fixing', and then assigned
    // to 'total'.

    std::cout << "total time = ";
    total.Show();

    Time processing{2, 50};	// Explicit Constructor
    
    // Below works for operator+ since it will be translated into
    // coding.operator+(fixing + processing), and then
    // coding.operator+(fixing.operator+(processing));
    total = coding + fixing + processing;
    // Above will call Default Constructor TWICE to constructor 2 temp objects
    // to hold addition value.
    
    std::cout << "Again, total time = ";
    total.Show();

    std::cout << "-------------------------" << std::endl;
    
    total = coding * 0.5;	// Default Constructor
    std::cout << "coding * 0.5 = ";
    total.Show();

    total = 2 * coding;       // Default Constructor
    std::cout << "2 * coding = ";
    total.Show();

    std::cout << "-------------------------" << std::endl;
    std::cout << total << "Test overload";

    return 0;
}
