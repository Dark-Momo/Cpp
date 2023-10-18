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

std::once_flag pTest_Flag;

void process(void)
{
    // Use the flag to denote whether has been executed or not.
    std::call_once(pTest_Flag, [](){
        std::cout << "Initialize." << std::endl;
        pTest = new Test;
    });

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
