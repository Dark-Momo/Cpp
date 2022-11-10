#ifndef BRASS_HPP_
#define BRASS_HPP_

#include <iostream>
#include <string>

// When there is inheritance between class:
// 1. All base method can be accessed by derived object, and only derived can have its own function.
// 2. Functions delcared only in base calss, but not declared in derived class mean they are the same for base/derived.
// 3. Function in base class without 'virtual' means it is the same for both base and derived object;
// *************************************************************************************************************
// Function with 'virtual' means same function name with different function definition. 
// *************************************************************************************************************
//    BUT! You can also just declare the same function name, with same parameter list, in base/derived class,
//    WITHOUT 'virtual', to indicate here is inheritance! Virtual is not a MUST for inheritance!
// *************************************************************************************************************
//    What is the difference between with/without 'virtual'?
//    (1) Without 'virtual' : reference/pointer type will determine which funcion to use;
//    (2) With 'virtual'    : the type of object that reference/pointer refers to determine which to use;
//    (3) If you are not using reference/pointer, but the objectitself, the object will determine which to use;
// *************************************************************************************************************
class Brass
{
    private:
        std::string fullName;
        long accountNumber;
        double accountBalance;

    public:
        Brass(const std::string & fn = "Nobody", long an = -1, double ab = 0.0);
        void deposit(double amt);

        virtual void withdraw(double amt);

        double getBalance() const { return accountBalance; }

        virtual void viewAccount() const;

        // 3. Base class should have a virtual dtor, no matter what it does!
        virtual ~Brass() { std::cout << "Brass Dtor\n"; };
        // In current code example, we generate a Brass object pointer first, and then Brassplus object pointer.
        // Finally, we delete these 2 pointers in order, and 'Brass Dtor' will be printed out twice.
        // The first due to the destruction of Brass object pointer, then estruction of BrassPlus object pointer.

        // The later pointer destructs in such order: 
        // First call dtor of BrassPlus object, which we didn't define here. So a default one will be called.
        // Then it will call dtor of Brass object, to destruct base object part.
        
        // So, using virtual destructor in base class ensures correct destruction sequence. 
};

// Keyword 'virtual' only appears in declaration, not in definition.

class BrassPlus : public Brass
{
    private:
        double maxLoan;
        double rate;
        double owetoBank;

    public:
        BrassPlus(  const std::string & fn = "Nobody", 
                    long an = -1,
                    double ab = 0.0,
                    double ml = 500,
                    double r = 0.1);
                    // double owe = 0.0);

        BrassPlus(const Brass & p, double ml = 500, double r = 0.1);

        // No deposit() declared here.

        virtual void withdraw(double amt);

        // No getBalance() declared here.

        virtual void viewAccount() const;

        // Functions for derived only.
        void setMaxLoan(double m) { maxLoan = m; }
        void setRate(double r) { rate = r; }
        void resetOweBank() { owetoBank = 0; }
};

#endif
