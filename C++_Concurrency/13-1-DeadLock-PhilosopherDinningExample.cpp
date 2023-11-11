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

// -----------------------------------------------------------------------------------------------
void philosopherDine(unsigned int philoIndex)
{
    unsigned int leftFork = philoIndex;
    unsigned int rightFork = (philoIndex + 1) % numOfPhilosopher;

    // 1. First think 2000ms
    print(philoIndex, "will think for 2000ms");
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // 2. Pick up left fork
    print(philoIndex, "will pick up left fork", leftFork);
    ForkMutex[leftFork].lock();
    print(philoIndex, "successfully picked up left fork", leftFork);

    // 3. Think again for 2000ms
    print(philoIndex, "will think for 2000ms");
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // 4. Pick up right fork
    print(philoIndex, "will pick up right fork", rightFork);
    ForkMutex[rightFork].lock();

    // For deadlock demonstration, the code will stuck here.

    // 5. Eat for 1000ms
    print(philoIndex, "will eat for 2000ms");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // 6. Put down both forks
    ForkMutex[rightFork].unlock();
    ForkMutex[leftFork].unlock();
}

int main(void)
{
    std::vector<std::thread> dineThreadArray;

    for (int  i = 0; i < numOfPhilosopher; i++)
    {
        // Both of below works fine.
        // ----------------------------------------------------------------------
        dineThreadArray.push_back(std::thread(philosopherDine, i));
        // dineThreadArray.push_back(std::move(std::thread(philosopherDine, i)));
	// ----------------------------------------------------------------------
    }

    for (auto &th : dineThreadArray)
    {
        th.join();
    }

    return 0;
}
