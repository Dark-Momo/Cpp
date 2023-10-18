#include <iostream>
#include <mutex>
#include <thread>

class Test
{
public:
    Test(void) { std::cout << "Ctor." << std::endl; }
    void Func(void) { std::cout << "-- Func." << std::endl; }
};

Test * pTest = nullptr; // Lazy initialization to a shared data.
std::mutex myMutex;

void process(void)
{
    if(!pTest)
    {
        std::lock_guard<std::mutex> myLock(myMutex);
        if(!pTest)
        {
            pTest = new Test;
        }
    }
    pTest->Func();
}

int main()
{
    std::thread th1(process);
    std::thread th2(process);
    std::thread th3(process);
    std::thread th4(process);

    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return 0;
}
