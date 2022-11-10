// #include <iostream>
#include "MyTime0.h"

Time::Time()
{
    std::cout << "-- In default Constructor" << std::endl; 
    hour = 0;
    minutes = 0;
}

Time::Time(int h, int m)
{
    std::cout << "-- In explicit Constructor" << std::endl;
    hour = h;
    minutes = m;
}

void Time::addHour(int h)
{
    hour = hour + h;
}

void Time::addMin(int m)
{
    minutes = minutes + m;
    
    hour = (minutes / 60);
    minutes = (minutes % 60);
}

void Time::Reset(int h, int m)
{
    hour = h;
    minutes = m;
}

Time Time::Sum(const Time & p) const
{
    Time temp;

    // This denotes to the invoking object.
    temp.minutes = this->minutes + p.minutes;
    temp.hour = this->hour + p.hour + (temp.minutes / 60);
    temp.minutes = (temp.minutes % 60);

    return temp;
}

// Operator overload. Its body is the same as previous one.
// C = A + B;
// The left at the + is the invoking object while the one at right is the parameters.
Time Time::operator+(const Time & p) const
{
    Time temp;

    temp.minutes = this->minutes + p.minutes;
    temp.hour = this->hour + p.hour + (temp.minutes / 60);
    temp.minutes = (temp.minutes % 60);

    return temp;
}

void Time::Show() const
{
    std::cout << hour << " hours " << minutes << " minutes" << std::endl;
}

// ----------------------------- Operator Overload Form A : Member function. ------------------------------
// It only allows form of 'C = A * 0.5' because member function one needs a invoking object.

Time Time::operator*(double n) const
{
    Time temp;
    // Below uses normal '*' as operation of overloaded '*'
    long totalminutes = this->hour * n * 60 + this->minutes * n;
    temp.hour = totalminutes / 60;
    temp.minutes = totalminutes % 60;

    return temp;
}

// Note here:
// Form B and C below will have the same function prototype in its .cpp file!
// They are all 'Time operator*(double n, const Time & p)';

// ---------------------- Operator Overload Form B : Non-Member, Non-friend function. ---------------------
// Using Class public interface to get its data.
// It only allows form of 'C = 0.5 * A'.

/*
Time operator*(double n, const Time & p)
{
    Time temp;
    long totalminutes = p.getHour() * n * 60 + p.getMinutes() * n;
    temp.setHour(totalminutes / 60);	// Can't use temp.hour to get its member. Public interface needed.
    temp.setMinutes(totalminutes % 60);

    return temp;
}
*/

// ----------------------- Operator Overload Form C : Non-member, Friend function. ------------------------

Time operator*(double n, const Time & p)
{
    Time temp;
    long totalminutes = p.hour * n * 60 + p.minutes * n;
    temp.hour = totalminutes / 60;
    temp.minutes = totalminutes % 60;

    return temp;
}

// An iplementation suitable for both Non-member, Non-friend one, and Non-member, friend one.

/*
Time operator*(double n, const Time & p)
{
    return p * n;	// Uses the operator overload from member one that need invoking object.
}
*/


// ----------------- Operator << Overload Form 1 : Non-member, Friend, Void function. ---------------------
/*
void operator<<(std::ostream & os, const Time & p)
{
    os << p.hour << " hours " << p.minutes << " minutes." << std::endl;
}
*/

// --------------- Operator << Overload Form 1 : Non-member, Friend, Non-Void function. -------------------

std::ostream & operator<<(std::ostream & os, const Time & p)
{
    os << p.hour << " hours " << p.minutes << " minutes. ";
    return os;
}
