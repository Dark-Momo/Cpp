// A class which is internally synchronized
// The member functions lock a mutex before they access a data member
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std::literals;

class Vector 
{
    std::mutex mut;
    std::vector<int> vec;
public:
    void push_back(const int& i)
    {
        mut.lock();
        
	// Start of critical section
        vec.push_back(i);
        // End of critical section
        
	mut.unlock();
    }

    void print() 
    {
	// ***********************************
	// Key Mutex Here!
	// ***********************************
        mut.lock();
        
	// Start of critical section
	// Output all current values in vec
        for (auto i : vec)
        {
            std::cout << i << ", ";
        }
	std::cout << "\n";
        // End of critical section
        
	mut.unlock();
    }
};

void func(Vector& vec)
{
    for (int i = 0; i < 5; ++i) 
    {
        vec.push_back(i);
        //std::this_thread::sleep_for(50ms);
        vec.print();
    }
}

int main()
{
    Vector vec;

    std::thread thr1(func, std::ref(vec));
    std::thread thr2(func, std::ref(vec));
    std::thread thr3(func, std::ref(vec));

    // 3 thread, only 1 vector, and every thread will try to write 0 1 2 3 4 into vector.

    thr1.join(); thr2.join(); thr3.join();

    std::cout << "vec content : ";
    vec.print();
}

// Correctly Test Run:
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ ./a.out 
// 0, 
// 0, 1, 
// 0, 1, 2, 
// 0, 1, 2, 3, 
// 0, 1, 2, 3, 4, 
// 0, 1, 2, 3, 4, 0, 
// 0, 1, 2, 3, 4, 0, 1, 
// 0, 1, 2, 3, 4, 0, 1, 2, 
// 0, 1, 2, 3, 4, 0, 1, 2, 3, 
// 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 
// 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 
// 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 
// 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 
// 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 
// 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 
// vec content : 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4,
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$
// **********************************************************************************************
// The code itself doesn't gurantee the correct order like above.
// **********************************************************************************************
// If we think the print() function just printing the result, and have no race, we can disabvle
// the mutex there. And we will have something like:
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ ./a.out 
// 0, 
// 0, 0, 0, 
// 0, 0, 0, 1, 1, 
// 0, 0, 0, 1, 1, 2, 
// 0, 0, 0, 1, 1, 2, 3, 
// 0, 0, 0, 1, 1, 2, 3, 4, 
// 0, 65520, 1187058901, 1732035169, 
// 0, 0, 0, 1, 1, 2, 3, 4, 2, 
// 0, 0, 0, 1, 1, 2, 3, 4, 2, 3, 
// 0, 0, 0, 1, 1, 2, 3, 4, 2, 3, 4, 
// 0, 15, 
// 0, 0, 0, 1, 1, 2, 3, 4, 2, 3, 4, 1, 
// 0, 0, 0, 1, 1, 2, 3, 4, 2, 3, 4, 1, 2, 
// 0, 0, 0, 1, 1, 2, 3, 4, 2, 3, 4, 1, 2, 3, 
// 0, 0, 0, 1, 1, 2, 3, 4, 2, 3, 4, 1, 2, 3, 4, 
// vec content : 0, 0, 0, 1, 1, 2, 3, 4, 2, 3, 4, 1, 2, 3, 4, 
// momo@Ubuntu-Linux-22-04:~/Cpp/C++_Concurrency$ 
//
// It is possible that one thread is interrupted when it is resize() for push_back(), and the 
// thread that is put into running starts to run at print().
//
// Conclusion
// **********************************************************************************************
// We should use mutex to do synchronization for both reader and writer for a critical region.
// **********************************************************************************************
