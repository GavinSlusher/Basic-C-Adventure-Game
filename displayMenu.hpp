/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Menu file. Contains functions to display different menus or 
 * **               prompts and return a char if they are meant to be used in a
 * **               switch statement- which will have it's own input validation. 
 * **               If necessary, the prompts have their own input validation
 * **               as well.
 * ** *************************************************************************/
#ifndef DISPLAYMENU_HPP
#define DISPLAYMENU_HPP

#include "inputValidation.hpp"
#include <string>

using std::string;

int displayMenu();

char cabinChoice();

char endChoice();

char movement();

void clearScreen();

void enterToCont();

int promptInt(string& promptIn, const int MAX_INT, const int MIN_INT);

int promptPosInt(string& promptIn);

double promptDouble(string& promptIn, const int MAX_INT, const int MIN_INT);

std::string promptString(string& promptIn);

int returnRandInt(const int MAX_INT, const int MIN_INT);

#endif
