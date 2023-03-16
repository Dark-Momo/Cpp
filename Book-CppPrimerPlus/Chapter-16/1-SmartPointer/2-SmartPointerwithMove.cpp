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
};

class Resource
{
    public:
        Resource()
	{
	    std::cout << "In Ctor - Resource::Resource()...\n";
	}

	void showAddr(void)
	{
	    std::cout << "In Resource::showAddr() : " << this << "\n";
	}
        
	~Resource()
        {
            std::cout << "In Dtor - Resource::~Resource()...\n";
	}
};

int main()
{
    AutoPtr<Resource> ptr1(new Resource());
    ptr1->showAddr();

    AutoPtr<Resource> ptr2(ptr1);
    ptr2->showAddr();

    return 0;
}
