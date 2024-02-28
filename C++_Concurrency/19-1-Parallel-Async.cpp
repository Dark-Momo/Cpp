#include <iostream>
#include <vector>
#include <future>
#include <numeric>  // std::accumulate

double accum(double* begin, double *end)
{
    // Third parameter is the initial value of the sum for this time.
    // Calculate sum of range [begin, end).
    return std::accumulate(begin, end, 0.0);
}

// Divide input data into 4 segments, and add each segment parallelly.
// The size of the input vector must be multiples of 4.
double add_parallel(std::vector<double> &vec)
{
    auto vec0 = &vec[0];
    auto vsize = vec.size();

    // std::launch::async will start a new thread, and run the task immediately;
    auto fut1 = std::async(std::launch::async, accum, vec0, vec0 + vsize / 4);
    auto fut2 = std::async(std::launch::async, accum, vec0 + vsize / 4, vec0 + vsize / 2);
    auto fut3 = std::async(std::launch::async, accum, vec0 + vsize / 2, vec0 + 3 * vsize / 4);
    auto fut4 = std::async(std::launch::async, accum, vec0 + 3 * vsize / 4, vec0 + vsize);

    return fut1.get() + fut2.get() + fut3.get() + fut4.get();
}
// If with std::launch::async option and use std::future to get its return value, the task is 
// implicitly joined, when the std::future object is out of its scope. It is here, '}'.

int main(void)
{
    std::vector<double> vect(16);
    // std::iota() fills in the range specified, starting from the initial value.
    std::iota(vect.begin(), vect.end(), 1.0);

    std::cout << "The sum of 1 - 16 is : " << add_parallel(vect) << std::endl;

    return 0;
}
