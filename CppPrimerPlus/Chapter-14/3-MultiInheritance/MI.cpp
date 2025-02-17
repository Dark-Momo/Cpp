#include "MI.hpp"

// For Worker -------------------------------------------------------------------------------------------------------------------
Worker::~Worker() 
{ 
    std::cout << "Worker - ~Worker()\n";
}

void Worker::Data() const
{
    std::cout << "Worker - Obj Name : " << fullname << "\n";
    std::cout << "Worker - Obj ID   : " << id << "\n";
}

void Worker::Get()
{
    std::cout << "Worker - Enter Worker's Name : \n";
    getline(std::cin, fullname);

    std::cout << "Worker - Enter Worker's ID : \n";
    std::cin >> id;

    while(std::cin.get() != '\n')
    {
        continue;
    }
}

void Worker::Show() const
{
    Data();
}

void Worker::Set()
{
    Get();
}

// For Waiter -------------------------------------------------------------------------------------------------------------------
void Waiter::Data() const
{
    std::cout << "Waiter - Gender is " << gender << "\n";
}

void Waiter::Get()
{
    std::cout << "Waiter - Enter Waiter's Gender : 1 for Man, 0 for Woman.\n";
    std::cin >> gender;

    while(std::cin.get() != '\n')
    {
        continue;
    }
}

void Waiter::Show() const
{
    std::cout << "Waiter.Show()\n";
    Worker::Data();
    Data();
}

void Waiter::Set()
{
    std::cout << "Waiter.Set()\n";
    Worker::Get();
    Get();
}

// For Singer -------------------------------------------------------------------------------------------------------------------

const char * Singer::dayName[Singer::DayNumOfWeek] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

void Singer::Data() const
{
    std::cout << "Singer - singingDay is " << dayName[singingDay] << "\n";
}

void Singer::Get()
{
    std::cout << "Singer - SingingDay option is :\n";
    
    for (int i = 0; i < DayNumOfWeek; i++)
    {
        std::cout << i << " - " << dayName[i] << "\n";
    }
    
    std::cout << "Singer - Enter singingDay : ";
    std::cin >> singingDay;

    while(std::cin.get() != '\n')
    {
        continue;
    }
}

void Singer::Show() const
{
    std::cout << "Singer.Show()\n";
    Worker::Data();
    Data();
}

void Singer::Set()
{
    std::cout << "Singer.Set()\n";
    Worker::Get();
    Get();
}

// SingingWaiter ----------------------------------------------------------------------------------------------------------------
void SingerWaiter::Show() const
{
    std::cout << "SingerWaiter.Show()\n";
    Worker::Data();
    Data();
}
void SingerWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}
void SingerWaiter::Set()
{
    std::cout << "SingerWaiter.Set()\n";
    Worker::Get();
    Get();
}
void SingerWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

