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
    bool isFull() const;

    Type getTop(); // No const at end since it will modify 'top'.

    bool push(const Type & source);

    Type pop();
    bool pop(Type & target);
};

// Declaration and Definition should be in the same file for template.
template <typename Type>
NormalStack<Type>:: NormalStack()
{
    top = 0;
}

template <typename Type>
bool NormalStack<Type>::isEmpty() const
{
    return top == 0;
}

template <typename Type>
bool NormalStack<Type>::isFull() const
{
    return top == STACKSIZE; // Stack size goes to max of [STACKSIZE - 1].
}

// --------------------------------------------------------------------------
// Example of bad design here!
template <typename Type>
Type NormalStack<Type>::getTop() // No const here since it modify top.
{
    Type val;
    top--;
    val = items[top];
    top++;
    return val;
}
// Here, we didn't check isEmpty(). Otherwise, one problem will come up:
// What should we return if isEmpty()? -1? (Type)(-1)? Or what? 
// --------------------------------------------------------------------------

template <typename Type>
bool NormalStack<Type>::push(const Type & source)
{
    if (!isFull())
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

template <typename Type>
Type NormalStack<Type>::pop()
{
    top--; // Moce top to current 'tip' position that has valid data.
    return items[top];
}

template <typename Type>
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
