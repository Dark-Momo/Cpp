#ifndef MY_TIME0_H
#define MY_TIME0_H

#include <iostream>

class Time
{
    private:
            int hour;
            int minutes;

    public:
            Time(int h, int m = 0);
            Time();

	    // Below 4 functins are added to be used by Non-member, Non-friend * overloading function.
	    void setHour(int h) { hour = h; };
	    void setMinutes(int m) { minutes = m; };

	    int getHour(void) const { return hour; };
	    int getMinutes(void) const { return minutes; };

            void addHour(int h);
            void addMin(int m);

            // Below enables obj.Reset() form to set all to 0. 
            void Reset(int h = 0, int m = 0);

            // We will use a new object to hold added value, so 'const' to invoking oject.
            Time Sum(const Time & p) const;

	    void Show() const;
	    
            Time operator+(const Time & p) const;

	    // -------------------- Operator * Overload Form A : Member function. --------------------
	    //
	    // Below overloaded multification '*' can only allow form of 'C = A * 0.5'.
	    // 'C = 0.5 * A' is not allowed since 0.5, on the left of the operator, is not an object.
	    // Under this case, there is no invoking object. Compiler says:
	    // "error: no match for ‘operator*’ (operand types are ‘int’ and ‘Time’)". 

            Time operator*(double n) const;

            // -------------- Operator * Overload Form C : Non-member, Friend function. --------------
	    //
	    // This supports 'C = 0.5 * A' form.
            // Friend is NOT a member of class, but can access provate data.
	    
            friend Time operator*(double n, const Time & p);

            // --------------------------------- Operator << Overload --------------------------------
            // Form 1:
	    // This form works with 'cout << "other string" << [Time obj]', 
	    // but not with 'cout << [Time obj] << "other string"' since it returns void.
	    
	    // friend void operator<<(std::ostream & os, const Time & p);
	    
	    // Form 2:
	    // (1) Can't add 'const' at the beginning as 'friend const';
	    // (2) ostream used in definition, and 'cout/cerr' used when aplied;
	    // (3) return reference because a reference is passed in;
	    friend std::ostream & operator<<(std::ostream & os, const Time & p);
};

// ------------------ Operator * Overload Form B : Non-Member, Non-friend function. ------------------
//
// This supports 'C = 0.5 * A' form.
// But it needs 'Time' to provide public interface to get/set its return value's private data.

Time operator*(double n, const Time & p);

/* [Note here]
 *
 * Form B and C will have the same function defition prototype as 'Time operator*(double n, const Time & p)' 
 * in its .cpp file. 
 *
 * From experiment, the friend declaration above can work with both implementations;
 * while the non-friend non-member declaration here can only work with its own implemantation.
 *
 * It is understandable, since later one can not diectly access private data, so it can not use
 * the implementation of friend. 
 */ 

#endif
