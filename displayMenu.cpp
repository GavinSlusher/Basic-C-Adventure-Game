/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Menu file. Contains functions to display different menus or 
 * **               prompts and return a char if they are meant to be used in a
 * **               switch statement- which will have it's own input validation. 
 * **               If necessary, the prompts have their own input validation
 * **               as well.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include "displayMenu.hpp"
#include "inputValidation.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

/*******************************************************************************
*   int displayMenu()
*       Main menu display. Designed to be used with a switch statement. Can be
*       edited to tailor the need of the program. 
*******************************************************************************/
int displayMenu()
{
    int choice = 0; 
    string input;

    cout << endl;
    cout << "Final Project" << endl; //title, change for others
    cout << "-------------" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter selection: " << endl;

    getline(cin, input);

    if (input.length() > 1)
    {
        cout << "That's too long. ";
    }

    else if(!isdigit(input[0]))
    {
        cout << "That's not a number.";
    }
    
    else
    {
        choice = stoi(input);
    }

    return choice; 
}

/*******************************************************************************
*   char movement()
*       Menu to tell a player what keys to press
*******************************************************************************/

char movement()
{
    char choice = '0'; 
    string input;
    bool valid = false;

    cout << "Key: 'w' = Up, 'a' = Left, 's' = Down, 'd' = Right," << endl;
    cout << "'e' = interact, 'i' = inventory, 'q' = quit"; 
    cout << endl;
    cout << "Input: "; 

    do
    {
        getline(cin, input);

        if (input.length() > 1)
        {
            cout << "That's too long. " << endl;
        }

        else if (input != "w" && input != "a" && input != "s" && input != "d"
                 && input != "e" && input != "i" && input != "q")
        {
            cout << "Not a proper way to move" << endl;
        }
        
        else
        {
            choice = input[0];
            valid = true;
        }

    }while (!valid);

    return choice; 
}

/*******************************************************************************
*   char cabinChoice()
*       Menu to choose riddle event in FinalProject
*******************************************************************************/
char cabinChoice()
{
    char choice = '0'; 
    string input;


    cout << "What's going on?" << endl; //title, change for others
    cout << "----------------" << endl;
    cout << "1. Must still be the static in the air" << endl;
    cout << "2. How come I haven't hit an empty corner yet?" << endl;
    cout << "Enter selection: " << endl;

    getline(cin, input);

    if (input.length() > 1)
    {
        cout << "That's too long. ";
    }
    
    else
    {
        choice = input[0];
    }

    return choice;
}

/*******************************************************************************
*   char endChoice()
*       Menu to choose whether to end the Final Project game
*******************************************************************************/
char endChoice()
{
    char choice = '0'; 
    string input;


    cout << "Do you think we have enough to signal the helicopter?" << endl; 
    cout << "-----------------------------------------------------" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter selection: " << endl;

    getline(cin, input);

    if (input.length() > 1)
    {
        cout << "That's too long. ";
    }
    
    else
    {
        choice = input[0];
    }

    return choice;
}

/*******************************************************************************
*   void clearScreen()
*       Method to clear the screen.
*******************************************************************************/
void clearScreen()
{
    int clearSize = 50;

    for(int i = 0; i < clearSize; i++)
    {
        cout << endl;
    }
}

/*******************************************************************************
*   void enterToCont()
*       Menu to enter to cont.
*******************************************************************************/
void enterToCont()
{
    cout << "Press Enter to Continue";

    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

/*******************************************************************************
*   int promptInt(string& promptIn)
*       Prompt designed to take in a string as the prompt the user wants to 
*       print out, and validate the resulting input. For this function, we are
*       specifically validating  integers. The function uses getline 
*       to prompt the user to enter a string. We use getline because it will
*       take the entirely of the user's input, including spaces, up until the 
*       user presses <enter>. This way, we can iterate over the string and 
*       reject improper inputs. 
*
*       We also have an if statement that rejects the input if the number of 
*       characters in the string is too big. This way, we avoid the program 
*       trying to enter in an integer that is too big for the int data type.
*
*   Sources:
*   
*   -https://www.learncpp.com/cpp-tutorial/
*   5-10-stdcin-extraction-and-dealing-with-invalid-text-input/
*
*   -https://stackoverflow.com/questions/21257544/c-wait-for-user-input
*
*   -https://jesushilarioh.com/how-to-validate-an-integer-in-c-plus-plus/
*
*   -https://www.geeksforgeeks.org/5-different-methods-find-length-string-c/
*
*   -https://stackoverflow.com/questions/18534036/
*    checking-the-int-limits-in-stoi-function-in-c
*
*   -https://stackoverflow.com/questions/25020129/
*    cin-ignorenumeric-limitsstreamsizemax-n
*
*   -https://stackoverflow.com/questions/13556890/
*    why-do-i-have-to-press-enter-twice
*
*******************************************************************************/
int promptInt(string& promptIn, const int MAX_INT, const int MIN_INT)
{
    string num;
    int validInput; 
    bool valid;

    do //validate string
    {
        valid = true;
        cout << endl << promptIn << endl;
        getline(cin, num);

        if (num[0] == '-') //if the first char is negative
        {
            for (int i = 1; i < num.length(); i++)
              {
                if (!isdigit(num[i]))
                {
                  valid = false;
                }
              }
        }

        else //first char is not negative
        {
            for (int i = 0; i < num.length(); i++)
              {
                if (!isdigit(num[i]))
                {
                  valid = false;
                }
              }
        }

        if (num.length() == 0) 
        {
            valid = false;
            cout << "You didn't put anything in. ";
        }
        
        if (num.length() > 10) 
        {
            valid = false;
            cout << "That is way too big. ";
        }

        if (!valid)
              cout << "Not a valid entry." << endl;
        
    }while(!valid);

    validInput = stoi(num);

    if (!validateInt(validInput, MAX_INT, MIN_INT)) 
    {
        validInput = promptInt(promptIn, MAX_INT, MIN_INT);
    }

    return validInput;
}

/*******************************************************************************
*   int promptInt(string& promptIn)
*       Prompt designed to take in a string as the prompt the user wants to 
*       print out, and validate the resulting input. For this function, we are
*       specifically validating positive integers. The function uses getline 
*       to prompt the user to enter a string. We use getline because it will
*       take the entirely of the user's input, including spaces, up until the 
*       user presses <enter>. This way, we can iterate over the string and 
*       reject improper inputs. 
*
*       We also have an if statement that rejects the input if the number of 
*       characters in the string is too big. This way, we avoid the program 
*       trying to enter in an integer that is too big for the int data type.
*
*   Sources:
*   
*   -https://www.learncpp.com/cpp-tutorial/
*   5-10-stdcin-extraction-and-dealing-with-invalid-text-input/
*
*   -https://stackoverflow.com/questions/21257544/c-wait-for-user-input
*
*   -https://jesushilarioh.com/how-to-validate-an-integer-in-c-plus-plus/
*
*   -https://www.geeksforgeeks.org/5-different-methods-find-length-string-c/
*
*   -https://stackoverflow.com/questions/18534036/
*    checking-the-int-limits-in-stoi-function-in-c
*
*   -https://stackoverflow.com/questions/25020129/
*    cin-ignorenumeric-limitsstreamsizemax-n
*
*   -https://stackoverflow.com/questions/13556890/
*    why-do-i-have-to-press-enter-twice
*
*******************************************************************************/
int promptPosInt(string& promptIn)
{
    string num;
    int validInput; 
    bool valid;

    do //validate string
    {
        valid = true;
        cout << endl << promptIn << endl;
        getline(cin, num);

        for (int i = 0; i < num.length(); i++)
          {
            if (!isdigit(num[i]))
            {
              valid = false;
            }
          }

        if (num.length() == 0) 
        {
            valid = false;
            cout << "You didn't put anything in. ";
        }
        
        if (num.length() > 10) 
        {
            valid = false;
            cout << "That is way too big. ";
        }

        if (!valid)
              cout << "Not a valid entry." << endl;
        
    }while(!valid);

    validInput = stoi(num);

    return validInput;
}

/*******************************************************************************
*   int promptRandInt(const int MAX_INT)
*       Prompt to designed to return a random number. Takes a constant integer,
*       MAX_INT/MIN_INT, so that the user can define the range of the max/min 
*       number. 
*
*       Sources:
*           "Starting out with C++: Early Objects, 9th Edition," pg 135
*******************************************************************************/

int returnRandInt(const int MAX_INT, const int MIN_INT)
{
    int randInt;

    randInt = rand() % (MAX_INT - MIN_INT + 1) + MIN_INT; //random number between min and max

    return randInt;
}

/*******************************************************************************
*   string promptString(string& promptIn)
*       Function to prompt a string. Validates if user doesn't put anything in,
*       or if the string is longer than is reasonable for use of the prompt.
*******************************************************************************/
string promptString(string& promptIn)
{
    string prompt;
    bool valid;

    do //validate string
    {
        valid = true;
        cout << endl << promptIn << endl;
        getline(cin, prompt);

        if (prompt.length() == 0) 
        {
            valid = false;
            cout << "You didn't put anything in. ";
        }
        
        if (prompt.length() > 1000) 
        {
            valid = false;
            cout << "That is way too big. ";
        }

        if (!valid)
              cout << "Not a valid entry." << endl;
        
    }while(!valid);

    return prompt;
}

/*******************************************************************************
*   string promptDouble(string& promptIn)
*       Function to prompt a double, given a string as the prompt to user.
*       Inspired by promptInt() function. 
*
*       Source referenced: https://stackoverflow.com/questions/29169153/
*                           how-do-i-verify-a-string-is-valid-double-even-
*                           if-it-has-a-point-in-it
*******************************************************************************/
double promptDouble(string& promptIn, const int MAX_INT, const int MIN_INT)
{
    string num;
    double validInput; 
    bool valid;

    do //validate string
    {
        valid = true;
        int count = 0;
        cout << endl << promptIn << endl;
        getline(cin, num);

        for (int i = 0; i < num.length(); i++)
          {
            if (!isdigit(num[i]) && num[i] != '.')
            {
              valid = false;
            }

            if (num[i] == '.')
            {
                count++;
            }
          }

        if (count > 1)
        {
            valid = false;
            cout << "Too many decimals. ";
        }

        if (num.length() == 0) 
        {
            valid = false;
            cout << "You didn't put anything in. ";
        }
        
        if (num.length() > 10) 
        {
            valid = false;
            cout << "That is way too big. ";
        }

        if (!valid)
              cout << "Not a valid entry." << endl;
        
    }while(!valid);

    validInput = stod(num);
    
    if (!validateInt(validInput, MAX_INT, MIN_INT)) 
    {
        validInput = promptDouble(promptIn, MAX_INT, MIN_INT);
    }

    return validInput;
}

    
