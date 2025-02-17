#ifndef QUEUE_HPP_
#define QUEUE_HPP_

class Customer
{
    private:
        long arrive;		// Arrive time.
	int processtime;         // Process time. Assumed between 1 to 3 minutes.  

    public:
	Customer() { arrive = processtime = 0; }	// Customer has this default ctor only.
	void set(long when);				// Set arrive time and random process time of a customer.
        long getarrive() const { return arrive; }
	int getprotime() const { return processtime; }
};

typedef Customer Item;		// No need to add 'class' before Customer here.

class Queue
{
    private:

	enum {Q_SIZE = 10}; 	// Check Chapter - 10 for inside class scope constant definition.
                            	// Put constant definition here in private section, and this Q_SIZE is in class scope.

        struct Node
	{
            Item item; 
            struct Node * next;
        };
	// User data is capsulated into struct Node. And struct Node is the unit of the Queue.
	// This is a uni-direction link list, which suites the purpose of a queue.
	//
	// Define a struct/class inside another struct/class is called 'nested' (the inside one).
	// And, the nested one can access the outside one's private member, while the versa can't.

        Node * front;		// Pointer to the front of the queue.
	Node * rear;  		// Pointer to the back of the queue.

	int items;    		// Current number of elements in queue.

	const int qsize; 	// Max number of elements in queue.
	                        // 
	                        // You can declare a 'const int' in class declaration (.h file);
				// but don't initialize it here. Use 'enum' or 'static const' if you want to do that.
				// --------------------------------------------------------------------------------------------------------------
				// C++11 allows you to initialize data member, include const, in class declaration! 
				//
                                // ------------------------ Important ---------------------------------------------------------------------------
				// You can initialize 'qsize' using 'qsize =  ' form since it is a const.
				// const can be initialized, but not assigned.
				// When you call a constructor, with the purpose of 'qsize =  ' to assign a value to it,
				// befor the ctor body is executed, program first allocate memory to all it data member,
				// incluing 'qsize', which is initialization to 'qsize'.
				// So, 'qsize =  ' inside ctor body is assignment to 'qsize', which is not allowed.
				//
				// Use 'Member Initializer List', which is for ctor only, for const, and also other data member, initialization.
				//
				// --------------------------------------------------------------------------------------------------------------


	Queue(const Queue & q) : qsize(0) { };
	Queue & operator=(const Queue & q) { return *this; };
	// Defined deep copy related copy constructor and '=' here, in 'private' section.
	// (1) We don't want any deep copy for Queue. But in case it happens, define these 2 in private section
	// will force compiler to use them, not the default function ones. And since them are private, can't be 
	// called directly, compiler will give you error like they are not accessible. 
	//
	// Queue snick(nip); // Not Allowed.
	// snick = tuck;     // Not Allowed. 
	// 
	// This at least lets you know what happens.
	//
	// (2) (1) actually leads to a method that when you don't want your object to be copied!
	//
        // (3) Since no functional copy constructor is defined, we can't pass value of a Queue, or pass Queue as value, in a function,
	// because these operations generates temporary objects.


    public:
        Queue(int qs = Q_SIZE); 	// qs is the length od the queue that you want to initialize. Default is Q_SIZE.
	                        	// Member Initializer List is not here for const member 'qsize'.
					// It will be in function definition.
        ~Queue();

        bool isempty() const;
	bool isfull() const;

	int queuecount() const; 	// Current queue size.

	bool enqueue(const Item & item);
	bool dequeue(Item & item);	// Dequeue data into argument item.
};
#endif
