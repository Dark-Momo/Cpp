#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator} 
    {
        std::cout << "In Fraction Ctor...\n";
    }

    ~Fraction() 
    {
        std::cout << "In Fraction Dtor...\n";
    }

    friend std::ostream& operator<<(std::ostream & out, const Fraction& fra)
    {
        out << fra.m_numerator << "/" << fra.m_denominator;
	return out;
    }
};

int main()
{
    /* Use && to define a R-Value Reference.
     * Here, Fraction(3, 5) will initialize a temporary Fraction object, which is a R-Value. Normally, this temporary
     * object will be destructed after this line. However, we use a R-Valur Reference, Fraction&& r_ref, to initialize
     * using this temporary object. So, the life span of the temporary object Fraction(3, 5), will be extended to when
     * this R-Value Reference goes to die.
     */

    //auto&& r_ref{Fraction(3, 5)};
    Fraction&& r_ref{Fraction(3, 5)};

    std::cout << r_ref << "\n";

    // Dtor will be called here...

    return 0;
}
