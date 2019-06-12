/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         4/8/2019                
 * ** Description:  Input validation file. Contains a functions to validate 
 * **               different number types. 
 * **
 * **               Currently  contains two functions to validate an integer,
 * **               and a double
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include <limits>
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
* bool validatePosInt(int num, const int MAX_INT, const int MIN_INT)
*    Function to validate an integer based off user-defined maximums and
*    minimums. This validation function assumes that the input is definitely
*    an integer, so it should be used in tandem with another validation
*    function that rejects other kinds of input. 
*******************************************************************************/
bool validateInt(int num, const int MAX_INT, const int MIN_INT)
{
    bool valid;

    valid = true;

    if (num > MAX_INT)
    {
        valid = false;
        cout << "That number is too big. ";
    }

    if (num < MIN_INT)
    {
        valid = false;
        cout << "That number is too small. ";
    }
   
    if (!valid)
      cout << "Not a valid entry." << endl;

    return valid;
}

/*******************************************************************************
* bool validateDouble(double num, const double MAX_INT, double int MIN_INT)
*    Function to validate an double based off user-defined maximums and
*    minimums. This validation function assumes that the input is definitely
*    an double, so it should be used in tandem with another validation
*    function that rejects other kinds of input. 
*******************************************************************************/
bool validateDouble(double num, const double MAX_INT, const double MIN_INT)
{
    bool valid;

    valid = true;

    if (num > MAX_INT)
    {
        valid = false;
        cout << "That number is too big. ";
    }

    if (num < MIN_INT)
    {
        valid = false;
        cout << "That number is too small. ";
    }
   
    if (!valid)
      cout << "Not a valid entry." << endl;

    return valid;
}
