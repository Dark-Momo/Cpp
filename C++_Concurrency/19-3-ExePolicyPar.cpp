#include <iostream>
#include <execution>
#include <algorithm>
#include <vector>

// Compile this file using "g++ 19-3-ExePolicyPar.cpp -pthread -ltbb -std=c++17"
// This code is the same as the one of 19-2 with seq policy, and the result ias the same.


int main(void)
{
    std::vector<int> vec{3, 1, 1, 5, 7};
    std::sort(std::execution::par, vec.begin(), vec.end(), [](int a, int b) {return b < a;});

    for (auto i : vec)
        std::cout << i << " ";

    std::cout << std::endl;
}
