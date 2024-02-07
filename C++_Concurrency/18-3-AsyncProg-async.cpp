#include <iostream>
#include <future>
#include <chrono>

unsigned long long int fibonacci(unsigned int n)
{
    if (n <= 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    std::cout << "Calculate fibonacci(44)\n";

    // Below task will run immediately when std::aysn() is called. Different from std::packaged_task.
    // auto fiboResult = std::async(fibonacci, 44);
    std::future fiboResult = std::async(fibonacci, 44);
    
    bool fiboFinished = false;

    // Meaning of below line is straight-forward.
    while (fiboResult.wait_for(std::chrono::milliseconds(1000)) != std::future_status::ready)
    {
        std::cout << "Calculaing...\n";
    }

    std::cout << "fibonacci(44) = " << fiboResult.get() << "\n";

    return 0;
}