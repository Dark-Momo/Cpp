#ifndef _STUDENT_PRIINHERITANCE_HPP
#define _STUDENT_PRIINHERITANCE_HPP

#include <string>
#include <valarray>
#include <iostream>

// -- valarray usage: --
// double gpa[5] = {3.1, 3.5, 3.8, 2.9, 3.3};
// valarray<double> v1; 		// an array of double, size 0
// valarray<int> v2(8); 		// an array of 8 int elements
// valarray<int> v3(10,8); 		// an array of 8 int elements, each set to 10
// valarray<double> v4(gpa, 4); 	// an array of 4 elements, initialized to the first 4 elements of gpa
// valarray<int> v5 = {20, 32, 17, 9}; 	// C++11

class Student : private std::string, private std::valarray<double>
// Private Inheritance. Public and protected members of the base class 
// become private members of the derived class.
{
private:
    // Defined in class private, so can only be used inside class.
    typedef std::valarray<double> ArrayDB;

public:
    // Member initialization list below all use class name to represent
    // base class. This is typical for private inheritance, which is
    // different from Containment, which use object name.
    Student() : std::string("DefaultName"), ArrayDB() {};

    // Conversion constructor with only one parameter
    explicit Student(const std::string & s) : std::string(s), ArrayDB() {};
    explicit Student(int n) : std::string("DefaultName"), ArrayDB(n) {};

    Student(const std::string & s, int n) : std::string(s), ArrayDB(n) {};
    Student(const std::string & s, const ArrayDB & a) : std::string(s), ArrayDB(a) {};
    Student(const char * s, const double * pd, int n) : std::string(s), ArrayDB(pd, n) {};

    // This destructor doesn't have virtual prefix, maybe because this is not base class.
    ~Student() {};

    const std::string & Name() const; // Will return the std::string base class
    double Average() const;

    double operator[](int i) const;   // Return value can be modified.
    double & operator[](int i);       // Return valuecan't be modified.

    // Friend function for operator overloading
    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif
