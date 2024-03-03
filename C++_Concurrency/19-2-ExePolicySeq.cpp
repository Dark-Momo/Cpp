#include <iostream>
#include <execution>
#include <algorithm>
#include <vector>

// Compile this file using "g++ 19-2-ExePolicySeq.cpp -pthread -ltbb -std=c++17"

int main(void)
{
    std::vector<int> vec{3, 1, 1, 5, 7};
    std::sort(std::execution::seq, vec.begin(), vec.end(), [](int a, int b) {return b < a;});

    for (auto i : vec)
        std::cout << i << " ";

    std::cout << std::endl;
}
