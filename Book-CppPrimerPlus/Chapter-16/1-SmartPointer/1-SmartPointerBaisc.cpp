#include <iostream>

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
        // We don't define any copy contructor, or assignment operator here.
        // So when they are required, default ones will be called, doing shadow copy.

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
    // Below will have error : wrong number of template arguments (0, should be 1)
    // So you must have type info when initialize a template.
    /* 
     * AutoPtr<> p1; 
     */

    // Below will call the default ctor only, and shows '0' as nullptr. 
    /*
     * AutoPtr<int> exam; 
     * exam.showPtr();
     */

    AutoPtr<Resource> ptr1(new Resource());
    // ptr1->showPtr();
    ptr1->showAddr();

    AutoPtr<Resource> ptr2(ptr1); // 2 pointers pointing to 1 newed resource.
    // ptr2->showPtr();           // Will be deleted twice when exit.
    ptr2->showAddr();
 
    return 0;
}

/* Above program runs as
 * momo@Parallel-Ubuntu:~/Cpp/Book-CppPrimerPlus/Chapter-16/1-SmartPointer$ ./a.out
 * In Ctor - Resource::Resource()...
 * In Ctor : AutoPtr::AutoPtr(T* ptr)...
 * In Resource::showAddr() : 0x55f57742feb0
 * In Resource::showAddr() : 0x55f57742feb0
 * In Dtor : AutoPtr::~AutoPtr()...   // Here deletes ptr2.
 * In Dtor - Resource::~Resource()... // here deletes ptr2->m_ptr, which is pointing to he newed Resource. 
 * In Dtor : AutoPtr::~AutoPtr()...   // Here deletes ptr1.
 * In Dtor - Resource::~Resource()...
 * free(): double free detected in tcache 2
 * Aborted (core dumped)
 */
