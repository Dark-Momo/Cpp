#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Queue.hpp"

bool generateNewCustomer(double p)
{
    return ((std::rand() * p / RAND_MAX) < 1); // If p == 6, there is 1/6 probability that returns true.
}

int main(void)
{
    std::cout << "-------------------- Bank Service Simulation -------------------\n";
    
    const int MIN_PER_HOUR = 60;

    // Set the seed for rand().
    std::srand(std::time(0));

    // Determine how long the simualtion would last.
    int simHours;
    std::cout << "Input how many hours the smulation will last : ";
    std::cin >> simHours;
    std::cout << simHours << "\n";

    // Give how many guests come per hour.
    double guestPerHour;
    std::cout << "Input how many guest come per hour : ";
    std::cin >> guestPerHour;
    std::cout << guestPerHour << "\n";

    // Enter the max length of the queue.
    int queueSize;
    std::cout << "Input the max length of the queue : ";
    std::cin >> queueSize;
    std::cout << queueSize << "\n";

    // Ge nerate a empty queue here.
    Queue Line(queueSize);
    
    Item tempItem;

    // --------------------------------------------------------------------------------------------------------------------
    int simCycleLimit = MIN_PER_HOUR * simHours;		// Loop cycle number.
    double minutesPerGuest = MIN_PER_HOUR / guestPerHour; 	// Example: 60 / 10, so generate guest will probability 1/6.

    // Statistics ------------
    int turnAwayCount 	  = 0;
    int totalGuestCount   = 0;		// Total guest generated.
    int servedGuestCount  = 0;          // Total guest generated and served.

    int totalLineLength   = 0;
    int totalNodeWaitTime = 0;          // Sum of wait time of each node when they got processed.
    // ------------------------------
    int curWaitTime = 0;                // Time of wait for node currently at the front of the queue.

    for (int simCycleIndex = 0; simCycleIndex < simCycleLimit; simCycleIndex++)
    {
	// 1. Generate a new guest and check whether to add to line.
        if (generateNewCustomer(minutesPerGuest))
	{
	    if (Line.isfull())
	    {
	        turnAwayCount++;    
	    }
	    else
	    {
	        tempItem.set(simCycleIndex);
		Line.enqueue(tempItem);
                
		// Statistics
		totalGuestCount++;
	    }
	 }

	// 2. When queue is not empty and the bank counter is idle. Pop out data and reset wait time. 
	if (curWaitTime <= 0 && (!Line.isempty()))
	{
	    Line.dequeue(tempItem);
	    curWaitTime = tempItem.getprotime();
            // Statistics
            totalNodeWaitTime += simCycleIndex - tempItem.getarrive(); 
	    servedGuestCount++;
	}

        if (curWaitTime > 0)
	{
	    curWaitTime--;
	}

	// Statistics
	totalLineLength += Line.queuecount();
    } // End of for loop.

    std::cout << "Output Statistics Below ----------\n";
    if (totalGuestCount > 0)
    {
        std::cout << totalGuestCount << " guests joined the wait line,\n"
	          << servedGuestCount << " of them got served,\n"
	          << turnAwayCount << " guests got turned away.\n";
    
        std::cout << "Average line length is " << (double) totalLineLength / simCycleLimit << "\n";
        std::cout << "Average wait time is " <<  totalNodeWaitTime / servedGuestCount << "\n";
    }
    else
    {
        std::cout << "No guests generated!\n";
    }
    
    return 0;
}
