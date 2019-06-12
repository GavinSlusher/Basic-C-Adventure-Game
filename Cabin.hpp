/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Cabin class specification file. A subclass of the Space
 * **               class, it customized it's own layout by overriding the 
 * **               createSpace() method. There are multiple Cabin classes,
 * **               but they are essentially the same class hardcoded with 
 * **               different MapObjects.
 * ** *************************************************************************/
#ifndef CABIN_HPP
#define CABIN_HPP 

#include "displayMenu.hpp"
#include "inputValidation.hpp"
//#include "Game.hpp"
#include "Space.hpp"

//class Game; //forward declaration

class Cabin: public Space 
{
    protected:
        
    public:
        Cabin(int, int, std::string);
        void createSpace();

};

class Cabin2: public Space 
{
    protected:
        
    public:
        Cabin2(int, int, std::string);
        void createSpace();

};

class Cabin3: public Space 
{
    protected:
        
    public:
        Cabin3(int, int, std::string);
        void createSpace();

};

#endif


