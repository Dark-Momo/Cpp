#include <cstdlib>
#include "Queue.hpp"

// Default ctor of Queue below.
// Its main purpose is to set 'qsize', placing a limit to current Queue object when it is further constructed later.
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

// Interesting!
// The constructor of Queue object does utilize new, but its destructor still need to delete itself.
Queue::~Queue()
{
    Node * temp;

    while (front != nullptr)
    {
        temp = front;
        front = front->next;	
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item & item)
{
    if (isfull())
    {
        return false;
    }

    Node * temp = new Node;
    temp->item = item;		// Here, item's value is assigned to temp->item, and item itself can
    temp->next = nullptr;       // be modified later with influencing temp->item.

    items++;

    // if (isempty())
    if (front == nullptr)	// It WAS an empty queue before. But don't use isempty()
    {                           // because you just 'items++'.
        front = temp;
	// rear = temp;
    }
    else
    {
        rear->next = temp; 	// Current rear->next moved to temp;
	// reat = temp;
    }

    rear = temp;		// Also need to move rear to temp.

    return true;
}

bool Queue::dequeue(Item & item)
{
    if (isempty())
    {
        return false;
    }

    item = front->item;
    items--;
    
    Node * temp = front;
    front = front->next;
    delete temp;

    if (isempty())		// It used to be a queue with one unit.
    {
        rear = nullptr;
    }

    return true;
}

// -----------------------------------------------------------------------------------------------------------------------

void Customer::set(long when)
{
    arrive = when;
    processtime = std::rand() % 3 + 1; // 1 - 3 minutes.
}
