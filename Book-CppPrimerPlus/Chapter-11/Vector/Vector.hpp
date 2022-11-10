#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>	// For << overloading

namespace VECTOR
{
    class Vector
    {
    public:
            enum Mode {RECT, POL};	// Symbloic constant at compiler time. Mode is a type.
    
    private:
            double x;
	    double y;
	    double mag;
	    double ang;

	    Mode mode;

	    void set_x();	// No const at end since it will modify invoking object.
	    void set_y();
	    void set_mag();
	    void set_ang();
     
    public:
            Vector();

	    // Below constructor receives mag, and ang in degree form as input
	    // in POL mode, and translate into radiant form to store in ang.
	    Vector(double x_, double y_, Mode m = RECT);
	    
	    void reset(double x_, double y_, Mode m = RECT);
	    
	    ~Vector();

	    // Below 4 functions are defined here, in class declaration.
	    // So they are automatically inline function.
	    double xval() const { return x; }
	    double yval() const { return y; }
	    double magval() const { return mag; }
	    double angval() const { return ang; }

	    void polar_mode();
	    void rect_mode();

	    // Operator overloading in member function form. Need invoking object.
	    Vector operator+(const Vector & p) const;	// Addition.
	    Vector operator-(const Vector & p) const;	// Subtraction.
	    Vector operator*(double n) const;		// Form 'Vector * n'.
	    Vector operator-() const;			// Minus of itself.

	    // Operator overloading in non-member, friend form. Need invoking object.
	    friend Vector operator*(double n, const Vector & p); // Form 'n * Vector'.
	    friend std::ostream & operator<<(std::ostream & os, const Vector & v); 
    };
}
#endif
