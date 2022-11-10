#include <iostream>
#include <string>

#include "Brass.hpp"

const int CLIENT_LIMIT = 2;

int main(void)
{
    Brass *p[CLIENT_LIMIT];
    
    std::string nameTemp;
    long anTemp;
    double balTemp;

    int accountType;

    for (int i = 0; i < CLIENT_LIMIT; i++)
    {
        std::cout << "Input Client Name now...\n";
        getline(std::cin, nameTemp);

        std::cout << "Input Client Account Number now...\n";
        std::cin >> anTemp;

        std::cout << "Input Client Initial Balance now...\n";
        std::cin >> balTemp;

        std::cout << "Enter to Choose Account Type : 0 - Brass, 1 - BrassPlus...\n";
        
        while ((std::cin >> accountType) && (accountType != 0 && accountType != 1))
        {
            std::cout << "Account Type Must be 0 or 1. Choose again...\n";
        }

        if (accountType == 0)
        {
            std::cout << "You choosed Brass account.\n";
            p[i] = new Brass(nameTemp, anTemp, balTemp);
        }
        else
        {
            std::cout << "You choosed BrassPlus account.\n";

            double mlTemp;
            double rTemp;

            std::cout << "Input Client MaxLoan Limit now...\n";
            std::cin >> mlTemp;
            
            std::cout << "Input Client Interest Rate now...\n";
            std::cin >> rTemp;

            p[i] = new BrassPlus(nameTemp, anTemp, balTemp, mlTemp, rTemp);
        }
        
        // Clear current input buffer for next object input.
        while (std::cin.get() != '\n')
        {
            continue;
        }
    } // End og for loop

    for (int i = 0; i < CLIENT_LIMIT; i++)
    {
        p[i]->viewAccount();
    }

    for (int i = 0; i < CLIENT_LIMIT; i++)
    {
         delete p[i];   
    }

    return 0;
}
