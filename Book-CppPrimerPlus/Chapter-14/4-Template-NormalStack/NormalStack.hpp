#ifndef _NORMALSTACK_HPP
#define _NORMALSTACK_HPP

#include <iostream>

template <typename Type>
// template <class Type>

class NormalStack
{
private:
    enum {STACKSIZE = 10};
    Type items[STACKSIZE]; // Element on computer stack.
    int top;               // top is the position for -NEXT- element.
public:
    NormalStack();
    bool isEmpty() const;
    bool inFull() const;

    Type & top() const;             // Return 'Type' or 'Type &'?

    bool push(const Type & source); // What if clear source after push()?

    Type & pop();                   // What if clear the stack element after pop it?
    bool pop(Type & target);
}

// Declaration and Definition should be in the same file for template.
template <typename Type>
NormalStack<Type>:: NormalStack()
{
    top = 0;
}

bool NormalStack<Type>::isEmpty() const
{
    return top == 0;
}

bool NormalStack<Type>::isFull() const
{
    return top == STACKSIZE; // Stack size goes to max of [STACKSIZE - 1].
}

Type & NormalStack<Type>::top()
{
    if (!isEmpty())
    {
        top--;
	return items[top];
    }
    else
    {
        std::cout << "Stack top() failed since it is empty! Return -1...\n";
        return -1;
    }
}

bool NormalStack<Type>::push(const Type & source)
{
    if (!isFull)
    {
        items[top] = source;
        top++;
	return true;
    }
    else
    {
        return false;
    }
}

Type & NormalStack<Type>::pop()
{
    if (!isEmpty)
    {
	top--;
        return items[top]
    }
    else
    {
        std::cout << "Stack pop() failed since it is empty! Return -1...\n";
	return -1;
    }
}

bool NormalStack<Type>::pop(Type & target)
{
    if (!isEmpty())
    {
	top--;
        target = items[top];
        return true;	
    }
    else
    {
        std::cout << "Stack pop(Type &) failed since it is empty! Return flase...\n";
	return false;
    }
}

#endif
