#ifndef _MI_HPP
#define _MI_HPP

#include <iostream>

class Worker // An abstract base class
{
private:
    std::string fullname;
    long int id;
protected:
    // Data() and Get() are helpers for Show() and Set() below.
    // They are used to display/set 'extra' data part of class in the inheritance chain.
    // They should not be private, otherwise derved class can't utilize the base ones.
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("Empty Name"), id(-1)	// Always use Member Initialization List, maybe. 
    {
        std::cout << "----- Default Ctor of Worker!\n";
    }

    // --------------------------------------------------------------------------------------------------------------
    // Worker(const std::string & str = "Empty Name", long int n = -1) : fullname(str), id(n) {}
    // --------------------------------------------------------------------------------------------------------------
    // Above form of ctor, with all arguments assigned with default values, can't exist with the above
    // one, Worker(), at the same time.
    // Because, a ctor with all arguments assigned with a default value is also a default ctor.
    // When you call 'Worker()', it can be this one, or the first one.  
    // So it will be ambigious for compiler.

    Worker(const std::string & str, long int n) : fullname(str), id(n)
    {
        std::cout << "----- Full Ctor of Worker!\n";
    }
    
    // --------------------------------------------------------------------------------------------------------------
    // Do we need a copy constructor for later use as Worker(wk)? Is it using default copy constructor from compiler?
    // --------------------------------------------------------------------------------------------------------------

    virtual ~Worker() = 0; // Pure virtual function, declared by assigning 0 to a virtual function.

    virtual void Show() const = 0;
    virtual void Set() = 0;
};

class Waiter : virtual public Worker
{
private:
    bool gender; // True for Man, False for Woman.
protected:
    void Data() const; // NO virtual keyword for these 2.
    void Get();
public:
    // Waiter() : fullname("Empty Name"), id(-1), gender(true) 
    // Above form is invalid since for public inheritance, you can't access base class's private data derectly.
    // You need to call base class's ctor to initialize it.

    // 1. Default Ctor. You still need to initialize everything by using member initialization list.
    Waiter() : Worker(), gender(true) 
    {
        std::cout << "----- Default Ctor of Waiter!\n";
    }

    // 2. Full Ctor.
    Waiter(const std::string & str, long int n, bool g = true) : Worker(str, n), gender(g)
    {
        std::cout << "----- Full Ctor of Waiter!\n";
    }

    // 3. Ctor for inheritance.
    Waiter(const Worker & wk, bool g = true) : Worker(wk), gender(g)
    {
        std::cout << "----- Inheriting Ctor of Waiter, with Worker(wk)!\n";
    }

    // No Dtor here!

    void Show() const; // No virtual and '= 0' for these 2. 
    void Set();
};

class Singer : virtual public Worker
{
protected:
    // Two enum can't be in private since SingerWaiter is using them.
    enum {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    enum {DayNumOfWeek = 7};

    void Data() const;
    void Get();

private:
    // Dispaly day name when initializing as helper.
    // Staic class member:Different objs shares only one copy of the static data.
    static const char * dayName[DayNumOfWeek];
    int singingDay; // On which day will the singer sings.

public:
    Singer() : Worker(), singingDay(Monday)
    {
        std::cout << "----- Default Ctor of Singer!\n";        
    }

    Singer(const std::string & str, long int n, int d = Monday) : Worker(str, n), singingDay(d) 
    {
        std::cout << "----- Full Ctor of Singer!\n";    
    }

    Singer(const Worker & wk, int d = Monday) : Worker(wk), singingDay(d)
    {
        std::cout << "----- Inheriting Ctor of Singer, with Worker(wk)!\n";
    }

    // No Dtor here!

    void Show() const;
    void Set();
};

class SingerWaiter : public Waiter, public Singer
{
protected:
    void Data() const;
    void Get();

public:
    // SingerWaiter()
    // SingerWaiter() : Worker(), Waiter(), Waiter()
    SingerWaiter() : Worker(), Singer(), Waiter()
    {
         std::cout << "----- Default Ctor, SingerWaiter(), of SingerWaiter!\n";
	 std::cout << "----- What is called here?!\n";
    }
    // Test for this:
    // Excute 'WorkerObjList[2] = new SingerWaiter;'
    // The 3 prototype above will have the same result below:
    // ----- Default Ctor of Worker!
    // ----- Default Ctor of Waiter!
    // ----- Default Ctor of Singer!
    // ----- Default Ctor, SingerWaiter(), of SingerWaiter!
    // ----- What is called here?!

    SingerWaiter(const std::string & str, long int n, bool g = true, int d = Monday) : Worker(str, n), Waiter(str, n, g), Singer(str, n, d)
    {
        std::cout << "----- Full Ctor of SingerWaiter!\n";
	std::cout << "----- Is there duplicate call for Worker Ctor here?!\n";
    }

    SingerWaiter(const Worker & wk, bool g = true, int d = Monday) : Worker(wk), Waiter(wk, g), Singer(wk, d)
    {
        std::cout << "----- Inheritance Ctor of SingerWaiter with Worker!\n";
	std::cout << "----- Is there duplicate call for Worker Ctor here?!\n";
    }

    SingerWaiter(const Waiter & wt, int d = Monday) : Worker(wt), Waiter(wt), Singer(wt, d)
    {
        std::cout << "----- Inheritance Ctor of SingerWaiter with Waiter!\n";
	std::cout << "----- Is there duplicate call for Worker Ctor here?!\n";
    }

    SingerWaiter(const Singer & sg, bool g = true) : Worker(sg), Waiter(sg, g), Singer(sg)
    {
        std::cout << "----- Inheritance Ctor of SingerWaiter with Singer!\n";
	std::cout << "----- Is there duplicate call for Worker Ctor here?!\n";
    }

    // No Dtor here!

    void Show() const;
    void Set();
};

#endif
