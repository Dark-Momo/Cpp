#include <iostream>

int main (void)
{
    char c = 'M';
    std::cout << "cout << 'M' is " << c << std::endl;			// M
    std::cout << "cout << int('M') is " << int(c) << std::endl;		// 77

    // --------------------------------------------------------------------------------
    std::cout << std::endl;

    std::cout << "Now, input a char on keyboard." << std::endl;

    // Here:
    // (1) cin won't have input length check here. You can input many chars here and then enter. Programs still runs;
    // (2) If you input more than 1 char here, cin will assign the FIRST one to c, and won't ask you to input i and 
    // assign the SECOND input to it if it is an integer, or 0, if the SECOND is not a integer;
    std::cin >> c;
    std::cout << "Now, input finished for this char." << std::endl;

    std::cout << "The char just input with its plain form is : c = " << c << std::endl;
    std::cout << "Its integer form is : int(c) = " << int(c) << std::endl;
    // --------------------------------------------------------------------------------

    std::cout << std::endl;

    int i;
    std::cout << "Now, input an integer on keyboard." << std::endl;
    std::cin >> i;
    // Here, when you input a int, what input buffer get is a ASCII first.
    // But it checks that you want to input to an int, it will convert this 
    // ASCII to int and then stores it in i.
    std::cout << "Now, input finished for this integer." << std::endl;

    std::cout << "The integer just input with its plain form is : i = " << i << std::endl;

    // --------------------------------------------------------------------------------
    
    std::cout << std::endl;

    std::cout << "Now, test cin return value." << std::endl;

    int j;
    std::cout << "Now, input an integer on keyboard to int value j." << std::endl;
    if (std::cin >> j)
    {
        std::cout << "cin >> j returns true." << std::endl;    
    }
    else
    {
        std::cout << "cin >> j returns false." << std::endl;
    }

    return 0;
}

/* Input Case:
 * 1. Input 5 for c and 5 for i.
 *    This case, the first 5 will be dealt as char '5', with ASCII code 53, and output c based on this 53.
 *    i will be taken as int 5.
 *
 * 2. Input 'NN' for c.
 *    c will be 'N' and i will automatically be 0 without asking you to input.
 *
 * 3. Input 'N456' for c.
 *    c will be 'N' and i will automatically be 456 without asking you to input.
 *
 * 4. Input 'N001' for c.
 *    c will be 'N' and i will automatically be 1 without asking you to input.
 *
 * 5. Input '102' for c.
 *    c will be '1' and i will automatically be 2 without asking you to input. 
 */
