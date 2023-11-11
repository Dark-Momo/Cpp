#include <iostream>
#include <string> 
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>

const unsigned int numOfPhilosopher = 5;

const unsigned int numOfFork = numOfPhilosopher;
std::mutex ForkMutex[numOfFork];

std::mutex printMutex;

using namespace std::chrono_literals;
// -----------------------------------------------------------------------------------------------
// When multithread, even std::cout will need lock to do synchronization.
void print(unsigned int philoIndex, const std::string & message)
{
    std::lock_guard<std::mutex> printGuard(printMutex);
    std::cout << "Philosopher " << philoIndex << ": " << message << std::endl;
}

void print(unsigned int philoIndex, const std::string & message, unsigned int forkIndex)
{
    std::lock_guard<std::mutex> printGuard(printMutex);
    std::cout << "Philosopher " << philoIndex << ": " << message << " " << forkIndex << std::endl;
}


void print(unsigned int philoIndex, const std::string & message, unsigned int leftForkIndex, unsigned int rightForkIndex)
{
    std::lock_guard<std::mutex> printGuard(printMutex);
    std::cout << "Philosopher " << philoIndex << ": " << message << " " << leftForkIndex << " and " << rightForkIndex << std::endl;
}

// -----------------------------------------------------------------------------------------------
void liveLock_philosopherDine(unsigned int philoIndex)
{
    unsigned int leftFork = philoIndex;
    unsigned int rightFork = (philoIndex + 1) % numOfPhilosopher;

    // 1. First think 2000ms
    print(philoIndex, "will think for 2000ms");
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    bool bothForkLocked = false;

    while (!bothForkLocked)
    {
	// 2. Pick up left fork
	print(philoIndex, "will pick his left fork", leftFork);
        ForkMutex[leftFork].lock();
	print(philoIndex, "successfully picked his left fork", leftFork);

	// 3. Think for 2000ms
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	// 4. Try to pick up right fork
	print(philoIndex, "will try to pick his right fork", rightFork);
	bothForkLocked = ForkMutex[rightFork].try_lock();
	if (!bothForkLocked)
	{
	    print(philoIndex, "will put down his left fork", leftFork); 
	    // -------------------------------------------------------------
	    // Sleep here will have live lock
	    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	    // -------------------------------------------------------------
	    ForkMutex[leftFork].unlock();

	    // -------------------------------------------------------------
	    // Sleep here will not have live lock
	    // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	    // -------------------------------------------------------------
	}
    }

    print(philoIndex, "successfully picked his right fork - ", rightFork);

    print(philoIndex, "will eat for 1000ms...");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    print(philoIndex, "will put down his both forks", leftFork, rightFork);
    ForkMutex[leftFork].unlock();
    ForkMutex[rightFork].unlock();
}

int main(void)
{
    std::vector<std::thread> dineThreadArray;

    for (int  i = 0; i < numOfPhilosopher; i++)
    {
        // Both of below works fine.
        // ----------------------------------------------------------------------
        dineThreadArray.push_back(std::thread(liveLock_philosopherDine, i));
        // dineThreadArray.push_back(std::move(std::thread(liveLock_philosopherDine, i)));
	// ----------------------------------------------------------------------
    }

    for (auto &th : dineThreadArray)
    {
        th.join();
    }

    return 0;
}
