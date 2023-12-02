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
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(1000ms);

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

    // ---------------------------------------------------------
    std::unique_lock<std::mutex> complete_Lock(mutexComplete);
    flagComplete = true;
    complete_Lock.unlock();

    condiVarComplete.notify_all();
    // ---------------------------------------------------------
}

// progressBar() should exit when flagComplete is true.
void progressBar()
{
    while(true)
    {
        // 1. Deal with progress
        std::unique_lock<std::mutex> progress_Lock(mutexProgress);

	    std::cout << "ProgressBar - Wait() on mutexProgress lock, with predicate......" << std::endl;
        condiVarProgress.wait(progress_Lock, [] {return flagProgress;} );
	
	    // Wake up means progress_lock got and locked mutexProgress.
	    std::cout << "ProgressBar - Waked up by Progress!" << std::endl;
        
	    flagProgress = false;

	    std::cout << "ProgressBar - We have received " << dataString.size() << " bytes data." << std::endl;
	
	    progress_Lock.unlock();

        // 2. Deal with complete check
	    std::unique_lock<std::mutex> complete_Lock(mutexComplete);
	    // Wait 10ms, then check flagComplete, If false, wait_for() return false.
        if ( condiVarComplete.wait_for(complete_Lock, 10ms, [] { return flagComplete; }) ) 
        {
            std::cout << "ProgressBar - Waked up by download finish!" << std::endl;
            break;
        }
	    else
	    {
	        std::cout << "ProgressBar - Download ongoing..." << std::endl;
	    }
    }
}

void dataProcess()
{
    std::unique_lock<std::mutex> complete_Lock(mutexComplete);
    std::cout << "dataProcess - Wait() on mutexComplete lock, with predicate......" << std::endl;
    condiVarComplete.wait(complete_Lock, [] { return flagComplete; });
    std::cout << "dataProcess - Waked up by download finished!" << std::endl;
    std::cout << "DataProcess - We process all data here : " << dataString << std::endl;
    // complete_Lock.unlock();
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
