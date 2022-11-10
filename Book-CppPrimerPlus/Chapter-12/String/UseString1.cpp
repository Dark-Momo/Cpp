#include "String.hpp"

const int ArSize = 5;
const int MaxLen = 10;

int main()
{
    String name;
    std::cout << "Hi, what is your name?\n";
    
    std::cin >> name; // Here uses overloaded '>>'.

    std::cout << name << ", please input up to " << ArSize << " short sayings <empty line to quit>:\n";

    String sayings[ArSize]; // In C++, array dimension can be determined by 'const int'.
    // Here, default constructor will be called ArSize times since it is an array of String.

    char temp[MaxLen];

    int i;
    for (i = 0; i < ArSize; i++)
    {
        std::cout << i + 1 <<":";

	// ------------------------------------------------------------------------------------
	// Below is a typical block of input using cin.get().
	std::cin.get(temp, MaxLen); // temp will only hold (MaxLen - 1) char from input buffer.

	char c;
	// while (cin && cin.get() != '\n')
	while (std::cin && (c = std::cin.get()) != '\n')
	{
	    std::cout << "Cleaning " << c << "\n";
	    continue;
	}
        // ------------------------------------------------------------------------------------

	// if (!std::cin || temp[0] == '\0')
	if (!std::cin)
	{
	    std::cout << "std::cin failed!\n";
	    break;
	}
	else if (temp[0] == '\0')
	{
	    std::cout << "temp[0] == null!\n";
	    break;
	}
	else
	    sayings[i] = temp;	// Overloaded '='.
    
    } // End of input sayings for loop.

    int total = i;
    std::cout << "Just input " << total << " sayings.\n";

    if (total > 0)
    {
        std::cout << "Here are your sayings:\n";
	for (i = 0; i < total; i++)
	{
	    std::cout << sayings[i][0] << ": " << sayings[i] << "\n"; 
	}

        int shortest = 0;
	int first = 0;

	for (i = 1; i < total; i++)
        {
	    if (sayings[i].length() < sayings[shortest].length())
	        shortest = i;
	}

	std::cout << "Shortest saying:" << sayings[shortest] << "\n";
       
        std::cout << "This program uses " << String::HowMany() << " String objects. Bye!\n";
	// Here, String::HowMany() will always show 'ArSize + 1' due to the String array.
    }
    else
    {
        std::cout << "No successful input. Bye.\n";
    }

    return 0;
}
