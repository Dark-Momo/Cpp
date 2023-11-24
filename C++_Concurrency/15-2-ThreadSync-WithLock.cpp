#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// Global variables that will be accessed by several threads.
bool progress_updated = false;
bool progress_completed = false;

std::string dataString;
// -------------------------------------------------------------------------------

std::mutex progressMutex; // Deal with 'progress_updated' and 'dataString' access.
std::mutex completeMutex; // Deal with 'progress_completed' access.

/*
 * The keypoint of this code is, for above 3 global varialbes, EVERY single access
 * to them is protected by lock, even it is just a checking, like what we have here
 * in processData().
 */

void dataFetch()
{
    for (int i = 0; i < 10; i++)
    {
	std::this_thread::sleep_for(500ms);

	/* 
	 * We use a lock_guard to protect the data writing and flag setting below.
	 */
	std::lock_guard<std::mutex> data_Lock(progressMutex);
	
	dataString = dataString + "Data" + std::to_string(i);
        std::cout << "DataFetch - We got data : " << dataString << std::endl;

	progress_updated = true;

	// Above lock_guard will be destructed here.
    }

    /* We use a lock_guard to protect the flag setting below.
     */
    // Below 'progress_completed' is a shared global variable.
    std::lock_guard<std::mutex> completed_Lock(completeMutex);
    progress_completed = true;
}

// progressBar() should exit when progress_completed is true.
void progressBar()
{
    // 1. When progress_updated is not true, we should sleep for a while and then go back to while()
    // 2. When progress_completed is true, we should exit the whole thread.
    while(true)
    {
	// We use unique_lock here since we need to explicitly call .unlock().
	std::unique_lock<std::mutex> progress_Lock(progressMutex);
        while(!progress_updated)
	{
	    progress_Lock.unlock();
	    std::this_thread::sleep_for(10ms);
	    progress_Lock.lock();
	}

	// We get here when "progress_updated == true"
	// Below 'progress_updated' is a shared global variable.
	progress_updated = false;
	std::cout << "ProgressBar - We received " << dataString.size() << " bytes data." << std::endl;
        progress_Lock.unlock();

	std::lock_guard<std::mutex> completed_Lock(completeMutex);
	if (progress_completed)
	{
	    std::cout << "ProgressBar - We received all expected data. Exit progressBar()." << std::endl;
	    break;
	}
    }
}

void dataProcess()
{
    std::unique_lock<std::mutex> completed_Lock(completeMutex);
    while(!progress_completed)
    {
	completed_Lock.unlock();
        std::this_thread::sleep_for(10ms);
	completed_Lock.lock();
    }

    completed_Lock.unlock();
    // Above code shows even you just want to check a global variable, you need complicated lock scheme. 
    // -------------------------------------------------------------------------------------------------

    std::lock_guard<std::mutex> data_Lock(progressMutex);
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
