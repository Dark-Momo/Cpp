#include <iostream>

#include "Brass.hpp"

// Base class method.

Brass::Brass(const std::string & fn, long an, double ab) : fullName(fn), accountNumber(an), accountBalance(ab) 
{
    std::cout << "-- Brass constructor!\n"; 
}

void Brass::deposit(double amt)
{
    std::cout << "-- [Brass::deposit()]\n"; 
    if (amt < 0)
    {
        std::cout << "Deposit value must be positive. Cancel current deposit!\n";
    }
    else
    {
        accountBalance = accountBalance + amt;
    }
}

void Brass::withdraw(double amt)
{
    std::cout << "-- [Brass::withdraw()]\n";
    if (amt < 0)
    {
        std::cout << "Withdraw value must be positive. Cancel current Withdraw!\n";
    }
    else if (amt <= accountBalance)
    {
        accountBalance = accountBalance - amt;
    }
    else
    {
        std::cout << "Withdraw value must be less than current balance. Cancel current Withdraw!\n";
    }
}

void Brass::viewAccount() const
{
    std::cout << "-- [Brass::viewAccount()]\n";
    std::cout << "Accout Name : " << fullName << "\n";
    std::cout << "Accout Number : " << accountNumber << "\n";
    std::cout << "Accout Balance : " << accountBalance << "\n";
}

// Derived class method.

BrassPlus::BrassPlus(   const std::string & fn, 
                        long an,
                        double ab,
                        double ml,
                        double r) : Brass(fn, an, ab)
{
    std::cout << "-- [BrassPlus full constructor]\n";
    maxLoan = ml;
    rate = r;
    owetoBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & p, double ml, double r) : Brass(p)
{
    std::cout << "-- [BrassPlus non-full constructor]\n";
    maxLoan = ml;
    rate = r;
    owetoBank = 0.0;
}

void BrassPlus::withdraw(double amt)
{
    std::cout << "-- [BrassPlus::withdraw()]\n";
    double bal = getBalance();
    if (amt <= bal)
    {
        Brass::withdraw(amt); // Need Brass:: here. Otherwise, compiler would think it is
    }                         // BrassPlus::withdraw() calls itself, a recursion! 
    else if (bal - amt + maxLoan - owetoBank >= 0)
    {
        double advance = amt - bal;
        owetoBank = owetoBank +  advance * (1 + rate);
        deposit(advance);
        Brass::withdraw(amt);
    }
    else
    {
        std::cout << "This withdraw is beyond the limit. Cancel!\n";
    }
}

void BrassPlus::viewAccount() const
{
    std::cout << "-- [BrassPlus::viewAccount()]\n";
    Brass::viewAccount();
    std::cout << "Accout MaxLoan : " << maxLoan << "\n";
    std::cout << "Accout Rate : " << rate << "\n";
    std::cout << "Accout OwetoBank : " << owetoBank << "\n";

}
