// Stock Class Interface

#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock 
{
	private:								// private members can only be accessed by public functions, or friends.
										// private is default, means if we don't have privae here, these members below are still private.
		std::string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot() { total_val = shares * share_val; }		// Inline function. Can also be define in .cpp as 'inline void Stock::set_tot()'. 
		// Inline function will be defined in each file in which they are used.
		// So, include inline definition in the sam header file where the class is defined, so refering to this header file contain inline definition.

	public:
		Stock(const std::string & co, long n, double pr);		// A : Explicit constructor
		Stock();							// B : Default constructor

		// Here, 2 constructors are defined. There are several froms that can define a class object:
		// 1. Stock foods = Stock("Whole foods", 10, 10.5);
		// 2. Stock foods("Whole foods", 10, 10.5);
		// 3. Stock * foods = new Stock("Whole foods", 10, 10.5);

		// 4. Stock foods = Stock();
		// 5. Stock foods;
		// 6. Stock * foods = new Stock;

		// 1, 2, and 3 use explicit constructor, while 4, 5, and 6 use default constructor. Parameters determine the constructor type.
		// Without default constructor, 4, 5, and 6 would not be allowed since you have provided explicit constructor.
		// When you provide explicit constructor, compiler will NOT provide you with default constructor.

		// You can also combine explicit and default constructors in one declaration and definition:
		// C : Stock(const string & co = "Error", int n = 0, double pr = 0.0);
		// Under C case, it is the only constructor that will be called since it covers all initial cases. 
		
		// D : Stock(const string & co , int n = 0, double pr = 0.0); is NOT a combined one, it is explicit constructor with two default patameters.
		
		// C++ 11:
		// Stock A = {"Derivatives Plus Plus", 100, 45.0};
		// Stock B {"Sport Age Storage, Inc"};
		// Stock C { };
		// Stock * foods = new Stock{"Whole foods", 10, 10.5};

		~Stock();

		// void acquire(const std::string& co, long n, double pr);
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show() const;		// const here, after the function declaration, means it will not modify the invoking object

		double total() const { return total_val; }

		const Stock & topval(const Stock & s) const;	// 3 const here. Explanation on Page 15 of notes, Chapter 10.
	        // s is the explicit invoked object used to compare, and this function also has an implicit invoked object.
};

#endif
