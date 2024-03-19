#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::vector<int> vec;
std::mutex myMutex;

void fillin_Lower(void)
{
    std::lock_guard<std::mutex> lockGuard(myMutex);
    for (int i = 0; i < 10000; i++)
    {
        vec.push_back(i);
    }    
}

void fillin_High(void)
{
    std::lock_guard<std::mutex> lockGuard(myMutex);
    for (int i = 10000; i < 20000; i++)
    {
        vec.push_back(i);
    }    
}

int main(void)
{
    std::thread thLower(fillin_Lower);
    std::thread thHigh(fillin_High);
    
    thLower.join();
    thHigh.join();

    for (int i = 0; i < 20000; i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "Finish!\n";

    return 0;
}

