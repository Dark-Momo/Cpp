#include <cmath>

#include "Vector.hpp"

namespace VECTOR
{
    // This is NOT defined in class. So it is a working constant.
    // See Chapter - 10 for constant defined in class.
    const double Rad_to_Deg = 360.0 / (2.0 * 3.1415);

    // Private methods below.
    // Set x and y from Polar coordinate.
    void Vector::set_x()
    {
        x = mag * std::cos(ang);
    }
     
    void Vector::set_y()
    {
        y = mag * std::sin(ang);
    }

    // Set mag and ang from Rect coordinate.
    void Vector::set_mag()
    {
        mag = std::sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (y == 0.0)
            ang = 0.0;
	else
            ang = std::atan2(y, x); // atan2() returns value in radiant form.
    }

    // Public methods below.
    Vector::Vector() 	// Default constrctor.
    {
	// std::cout << "Default Ctor Here." << std::endl;
        
	x = y = mag = ang = 0.0;
	mode = RECT;
    }

    Vector::Vector(double x_, double y_, Mode m)
    {
	// std::cout << "Explicit Constructor here." << std::endl;

        mode = m;  	// mode here is the private member.
        	
        if (m == RECT)
	{
	    x = x_;
	    y = y_;
            set_mag();
	    set_ang();
	}
	else if (m == POL)
	{
	    mag = x_;
	    ang = y_ / Rad_to_Deg;
	    set_x();
	    set_y();
	}
	else
	{
	    std::cout << "Invalid Mode. Set all member to 0." << std::endl;
	    x = y = mag = ang = 0.0;
	    mode = RECT;
	}
    }

    void Vector::reset(double x_, double y_, Mode m)
    {
        mode = m;  	// mode here is the private member.

        if (m == RECT)
        {
            x = x_;
            y = y_;
            set_mag();
            set_ang();
        }
        else if (m == POL)
        {
            mag = x_;
            ang = y_ / Rad_to_Deg;
            set_x();
            set_y();
        }
        else
        {
            std::cout << "Invalid Mode. Set all member to 0." << std::endl;
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {
        // std::cout << "Default Destructor!" << std::endl;
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }
    
    void Vector::rect_mode()
    {
        mode = RECT;
    }

    // Opertor overloading.
    // Note: All for RECT mode!

    Vector Vector::operator+(const Vector & p) const   // Addition under RECT mode.
    {
        return Vector(this->x + p.x, this->y + p.y);
    }

    Vector Vector::operator-(const Vector & p) const   // Subtraction under RECT mode.
    {
        return Vector(this->x - p.x, this->y - p.y);   // Left to '-' is the invoking object represented by 'this->'.
    }

    Vector Vector::operator*(double n) const		// Form 'Vector * n'.
    {
    	return Vector(n * this->x, n * this->y);
    }

    Vector Vector::operator-() const			// Minus of itself.
    {
        return Vector(-(this->x), -(this->y));
    }

    // Non-member operator overloading
    Vector operator*(double n, const Vector & p)        // Form 'n * Vector'.
    {
        return p * n; // Here, the * is the overloading one previously, not normal *.
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT) // Note here, we use Vector::RECT since friend is not a member, can't directly use RECT.
            os << "(x, y) = (" << v.x << ", " << v.y << ")" << std::endl;
	else if (v.mode == Vector::POL)
	    os << "(mag, ang) = (" << v.mag << ", " << v.ang * Rad_to_Deg << ")" << std::endl;
	else
	    os << "Vector mode invalid for display!" << std::endl;

	return os;
    }
}
