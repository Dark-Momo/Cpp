#include "NormalStack.hpp"

int main(void)
{    
    int val = 0;

    NormalStack<int> stack;
   
    std::cout << "Push 2 into stack now..." << std::endl; 
    stack.push(2);
    std::cout << "Current stack top is " << stack.getTop() << std::endl;
    
    std::cout << "Push 3 into stack now..." << std::endl;
    stack.push(3);
    std::cout << "Current stack top is " << stack.getTop() << std::endl;

    std::cout << "Push 4 into stack now..." << std::endl;
    stack.push(4);
    std::cout << "Current stack top is " << stack.getTop() << std::endl;

    val = stack.pop();
    std::cout << "Pop to val..." << std::endl;
    std::cout << "val is " << val << std::endl;
    std::cout << "Current stack top is " << stack.getTop() << std::endl;

    std::cout << "Push 5 into stack now..." << std::endl;
    stack.push(5);
    std::cout << "Current stack top is " << stack.getTop() << std::endl;

    return 0;
}
