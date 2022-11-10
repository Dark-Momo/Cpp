#include <iostream>

#include <cstdlib>	// rand(), srand() prototypes
#include <ctime>	// time() prototype

#include "Vector.hpp"

int main(void)
{
    // Use current time as seed for random generator.
    // srand() is usually used, only once, before calling rand().
    // Directly use rand() without first calling srand() to set seed will result in
    // same random number sequence between different executions.
    srand(time(0));

    double Distance;		// Targeted distance.
    double DisperStep;		// Magnitude of each step.

    unsigned int numStep = 0; 	// Count step numbers when reaching target distance.
    double direction = 0;       // Ang of each step.
    VECTOR::Vector curStep;		// Current step with mag and ang. Used to accumulate.
    VECTOR::Vector result(0.0, 0.0, VECTOR::Vector::RECT); // Define result in RECT form.
    
    std::cout << "Enter Target Distance (q to quit): ";
    while (std::cin >> Distance)
    {
        std::cout << "Enter Distance for Each Step : ";
        if ( !(std::cin >> DisperStep) )
            break;

        while (result.magval() < Distance)
	{
	    direction = rand() % 360;	// Generate a angle in (0, 360) degree.
	    // std::cout << "Direction is " << direction << std::endl;
	    
	    curStep.reset(DisperStep, direction, VECTOR::Vector::POL);
	    // std::cout << "curStep is (" << curStep.magval() << "," << curStep.angval() << ")" << std::endl;
	    // std::cout << "curStep is (" << curStep.xval() << "," << curStep.yval() << ")" << std::endl;
	    
	    result = result + curStep;
            // std::cout << "result is (" << result.xval() << "," << result.yval() << ")" << std::endl;
	    
	    numStep++;
	}
        
	result.rect_mode();
	std::cout << "After " << numStep << " steps, the subject has the following location:\n";
        std::cout << result << std::endl;
        
	result.polar_mode();
        std::cout << " or\n" << result << std::endl;
	std::cout << "Average outward distance per step = " << result.magval() / numStep << std::endl;
    
        numStep = 0;
        result.reset(0.0, 0.0);    
        
	std::cout << "Enter Target Distance (q to quit): ";
    }

    std::cout << "Bye!\n";
    std::cin.clear();

    while (std::cin.get() != '\n')
        continue;

    return 0;
}
