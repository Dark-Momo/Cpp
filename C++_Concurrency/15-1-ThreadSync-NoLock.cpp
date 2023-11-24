#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// Global variables that will be accessed by several threads.
bool progress_updated = false;
bool progress_completed = false;

std::string dataString;
// ----------------------------------------------------------

std::mutex progressMutex;
std::mutex completeMutex;

void dataFetch()
{
    for (int i = 0; i < 10; i++)
    {
	// std::cout << "DataFetch - We got new data here coming in..." << std::endl;
	std::this_thread::sleep_for(500ms);

	dataString = dataString + "Data" + std::to_string(i);
        std::cout << "DataFetch - We got data : " << dataString << std::endl;

        // Below 'progress_updated' is a shared global variable.
	progress_updated = true;
    }

    // Below 'progress_completed' is a shared global variable.
    progress_completed = true;
}

// progressBar() should exit when progress_completed is true.
void progressBar()
{
    // Below commented block is the original writing for progressBar(), which demonstrates 
    // itself that why it doesn't work.
    /*
    while (!progress_updated)
    {
        std::cout << "ProgressBar - We received " << dataString.size() << " bytes data.";
	// Below 'progress_updated' is a shared global variable.
	progress_updated = false;
    }
    */

    // 1. When progress_updated is not true, we should sleep for a while and then go back to while()
    // 2. When progress_completed is true, we should exit the whole thread.
    while(true)
    {
        while(!progress_updated)
	{
	    std::this_thread::sleep_for(10ms);
	}

	// We get here when "progress_updated == true"
	// Below 'progress_updated' is a shared global variable.
	progress_updated = false;

	std::cout << "ProgressBar - We received " << dataString.size() << " bytes data." << std::endl;

	if (progress_completed)
	{
	    std::cout << "ProgressBar - We received all expected data. Exit progressBar()." << std::endl;
	    break;
	}
    }
}

void dataProcess()
{
    while(!progress_completed)
    {
        std::this_thread::sleep_for(10ms);
    }

    std::cout << "DataProcess - We process all data here : " << dataString << std::endl; 
}

int main(void)
{
    std::thread thread_DataFetch(dataFetch);
    std::thread thread_ShowBar(progressBar);
    std::thread thread_DataProcess(dataProcess);

    thread_DataFetch.join();
    thread_ShowBar.join();
    thread_DataProcess.join();

    return 0;
}
