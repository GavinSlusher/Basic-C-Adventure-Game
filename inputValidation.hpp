/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         4/8/2019                
 * ** Description:  Input validation header file. Contains a functions to 
 * **               validate different number types. 
 * **
 * **               Currently  contains two functions to validate an integer,
 * **               and a double
 * ** *************************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP 

bool validateInt(int num, const int MAX_INT, const int MIN_INT);

bool validateDouble(double num, const double MAX_INT, const double MIN_INT);

#endif
