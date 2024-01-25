#include <iostream>
#include <atomic>

int main(void)
{
    std::atomic<int> x = 0;
    std::cout << "Initialized x = " << x << std::endl;
    std::cout << "x.load() = " << x.load() << std::endl;

    x.store(1);
    std::cout << "Initialized x = " << x << std::endl;
    std::cout << "x.load() = " << x.load() << std::endl;

    std::cout << "x.exchange(2) = " << x.exchange(2) << std::endl; // x.exchange(2) = 1
    std::cout << "Initialized x = " << x << std::endl;
    std::cout << "x.load() = " << x.load() << std::endl;

    return 0;
}
