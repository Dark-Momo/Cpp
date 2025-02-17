#include <iostream>

// In previous example, we have problem when 'AutoPtr<Resource> ptr2(ptr1)', where we have 2 
// pointers pointing to the same new-ed resource. We can:
// 1. Explicitly define and delete the copy ctor and assignment operator. This will disable
//    operations like 'AutoPtr<Resource> ptr2(ptr1)'. But this will also disable all other 
//    return-by-value of AutoPtr<Resource>;
//
// 2. Deep copy when copy ctor or assignment.  But it is not necessary at most of times, and
//    sometimes, 'AutoPtr<Resource> ptr2(ptr1)' means pointing to the same location, not pointing
//    to a new copy;
//
// 3. Move operation, which means transfer ownship. We will see it here.  

// Deleting a nullptr is okay, as it does nothing.

template <typename T>
class AutoPtr
{
    public:
        T* m_ptr;
    public:
	AutoPtr() : m_ptr(nullptr)
	{
            std::cout << "In Ctor : AutoPtr::AutoPtr()...\n";
        }

	AutoPtr(T* ptr) : m_ptr(ptr) 
	{
	    std::cout << "In Ctor : AutoPtr::AutoPtr(T* ptr)...\n";
	}

	// -------------------------------------------------------------------------
	// A COPY CONSTRUCTOR THAT IMPLEMENTS MOVE OPERATION!
	// -------------------------------------------------------------------------
        AutoPtr(AutoPtr & inst)
	{
	    m_ptr = inst.m_ptr; 	// Transfer ownship
	    inst.m_ptr = nullptr;
	}

        // -------------------------------------------------------------------------
        // AN ASSIGNMENT OPERATOR THAT IMPLEMENTS MOVE OPERATION!
        // -------------------------------------------------------------------------
	AutoPtr& operator=(AutoPtr & inst)
	{
	    if (&inst == this)
                return *this;

	    delete m_ptr;
	    m_ptr = inst.m_ptr;
	    inst.m_ptr = nullptr;
	    return *this;
	}
    
	// Below function is not that useful since after initializing a smart pointer,
	// AutoPtr<Resource> ptr1(new Resource());
	// ptr1 will be a pointer of class Resource type, and it doesn't have a memebr
	// called showPtr().
	void showPtr(void)
	{
	     std::cout << "AutoPtr is " << m_ptr << "\n";
	}

	~AutoPtr()
	{
	    std::cout << "In Dtor : AutoPtr::~AutoPtr()...\n";
	    delete m_ptr;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
    public:
        Resource()
	{
	    std::cout << "Resource Constructed.\n";
	}

	void showAddr(void)
	{
	    std::cout << "Resource::showAddr() : " << this << "\n";
	}
        
	~Resource()
        {
            std::cout << "Resource Destructed.\n";
	}
};

int main()
{
    AutoPtr<Resource> res1(new Resource());
    AutoPtr<Resource> res2; // Start as nullptr

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    res2 = res1; // res2 assumes ownership, res1 is set to null

    std::cout << "Ownership transferred\n";

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    return 0;
}
