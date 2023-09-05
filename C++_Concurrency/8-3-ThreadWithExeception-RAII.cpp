#include <iostream>
#include <thread>

class ThreadGuard
{
private:
    std::thread thObj;
public:
    explicit ThreadGuard(std::thread && th) : thObj(std::move(th)) {};

    // Delete copy constructor and assignment to prevent copy, since
    // copy to this class object doesn't make any sense.
    ThreadGuard(const ThreadGuard & tg) = delete;
    ThreadGuard & operator=(const ThreadGuard & tg) = delete;

    // The class will take care of the join() if it is joinable().
    ~ThreadGuard()
    {
        if (thObj.joinable())
	{
	    thObj.join();
	}
    }
};

void Hello()
{
    std::cout << "In Hello().\n";
}

int main()
{
    try
    {
        std::thread thr{Hello};
        ThreadGuard TG{std::move(thr)};

        throw std::exception();
	// When throw() is executed, the destructor will take care of the join().
    }
    catch (std::exception & e)
    {
        std::cout << "In catch - exception caught is " << e.what() << "\n";
    }
    
    return 0;
}
