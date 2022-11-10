// Stock.cpp

#include <iostream>
#include "Stock00.h"

Stock::Stock(const std::string& co, long n, double pr)	// Explicit constructor
{
	std::cout << "Explicit Constructor for " << co << " Called!\n";

	company = co; // company and co is standard string object, so it can use = for assignment.
	if (n < 0)    // co is reference, so it will pass the addr of string literal to company from initilization code.
	{
		std::cout << "Constructor - Number of shares can't be negative; "
			  << company << "shares set to 0. \n";
		shares = 0;
	}
	else
	{
		shares = n;
		share_val = pr;
	}
	set_tot();
}

Stock::Stock()	// Default constructor
{
	std::cout << "Default Constructor Called!\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;	// Only here, in constructor, sets total_val.
}

Stock::~Stock()
{
	std::cout << "Bye, " << company << "!\n";
}

void Stock::buy(long num, double price)
{
	if (num <= 0)
	{
		std::cout << "Buy - operation number can't be negative, "
			  << "operation cancelled!\n";
	}
	else
	{
		shares = shares + num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;

	if (num <= 0)
	{
		cout << "Sell -  operation number can't be negative, "
		     << "operation cancelled!\n";
	}
	else if (num > shares)
	{
		cout << "Sell -  operation number can't be more than you have! "
		     << "Operation cancelled!\n";
	}
	else
	{
		shares = shares - num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	std::cout << "	Company: " << company << '\n'
	          << " 	Shares : " << shares << '\n'
		  << " 	Shares Price : $" << share_val << '\n'
		  << "	Total Worth : $" << total_val << '\n';
}

const Stock & Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;	// this is a pointer, adding * to dereference.
}

// topval() can be used as:
// top = stock1.topval(stock2);
// top = stock2.topval(stock1);

