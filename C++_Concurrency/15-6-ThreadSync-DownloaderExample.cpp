#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std::chrono_literals;

// Predicate Variables
bool flagProgress = false;
bool flagComplete = false;

std::mutex mutexProgress;
std::mutex mutexComplete;

std::condition_variable condiVarProgress;
std::condition_variable condiVarComplete;

std::string dataString;

// --------------------------------------------------------------------------------------
void dataFetch()
{
    for (int i = 0; i < 10; i++)
    {
	std::this_thread::sleep_for(500ms);

	// 1. Update download data.
	std::unique_lock<std::mutex> progress_Lock(mutexProgress);
	dataString = dataString + "Data" + std::to_string(i);
        std::cout << "DataFetch - We got data : " << dataString << std::endl;

	// -----------------------------------------------------
	// (1) Set predicate before unlock().
	// -----------------------------------------------------
	flagProgress = true;

	// -----------------------------------------------------
	// (2) unlock(), in some way, before notify().
	// -----------------------------------------------------
	progress_Lock.unlock();

	// 2. Notify.
	// Notify() itself of a condition variable doesn't take predicate bool variable as argument.
        condiVarProgress.notify_all();
    }

    // Download Completed.
    std::cout << "DataFetch - All data has been download!" << std::endl;

    std::unique_lock<std::mutex> complete_Lock(mutexComplete);
    flagComplete = true;
    complete_Lock.unlock();

    condiVarComplete.notify_all();
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
