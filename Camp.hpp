/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Camp class implementation file. A subclass of the Space
 * **               class, it customized it's own layout by overriding the 
 * **               createSpace() method.
 * ** *************************************************************************/
#ifndef CAMP_HPP
#define CAMP_HPP 

#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "Space.hpp"
//#include "Game.hpp"

//class Game; //forward declaration

class Camp: public Space 
{
    protected:
        
    public:
        Camp();
        void createSpace();

};

#endif

