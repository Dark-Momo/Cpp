#include "Student.hpp"

// Accessing Base-Class Objects
const std::string & Student::Name() const
{
    return (const std::string &) *this;
    // For private inheritance, we use explicit type cast from object of derived class
    // to a base class as method of access to base class.
    // Here:
    // (1) *this is an object of Student class;
    // (2) (const string &) *this is the embedded string class object in this Student object; 
    //
    // According to test book, a ctor will be called if we don't have this explicit type cast.
    // TRY!
}

// Accessing Base-Class Methods
double Student::Average() const
{
    if(ArrayDB::size() > 0)
    {
        return ArrayDB::sum() / ArrayDB::size();
    }
    else
    {
        return 0;
    }
    // Use base class name and the scope-resolution operator, NOT object name, to invoke base-class methods.
}

double Student::operator[](int i) const
{
    // return ArrayDB::operator[](i); // Use operator[](int i) overloading of std::valarray<double>.
    // How about "return ((std::valarray<double> & ) *this)[i]"? Try! -- OK!
    return ((std::valarray<double> &) *this)[i];
}

double & Student::operator[](int i)
{
    // return ArrayDB::operator[](i);
    // How about "return ((std::valarray<double> &) *this)[i]"? Try! -- OK!
    return ((std::valarray<double> &) *this)[i]; 
}

// Accessing Base-Class Friends
// Use String version of operator>>()
std::istream & operator>>(std::istream & is, Student & stu)
{
    is >> (std::string &)stu;
    return is; 
}
// Use string friend getline(istream &, const string &)
std::istream & getline(std::istream & is, Student & stu)
{
    getline(is, (std::string &)stu);
    return is;
}

// Use string version of operator<<()
std::ostream & operator<<(std::ostream & os, const Student & stu)
{
    os << "Name is " << (const std::string &)stu;
    // Here we have a type cast from class Student to class string.
    // After that, the second << would be os << string, so it will
    // be the friend overloading of << of string.
    return os;
}

// FOR PRIVATE INHERITANCE, YOU MUST DO A EXPLICIT TYPE CAST WHEN YOU WANT TO ACCESS BASE CLASS'S REFERENCE FROM
// DERIVED CLASS OBJECT.
