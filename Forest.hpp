/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Forest class implementation file. A subclass of the Space
 * **               class, it customized it's own layout by overriding the 
 * **               createSpace() method. There are multiple Forest classes,
 * **               but they are essentially the same class hardcoded with 
 * **               different MapObjects.
 * **               
 * **               The only difference is the main Forest class that has logic
 * **               to get, set, and return whether the player has solved the 
 * **               riddle in that class's cutscene.
 * ** *************************************************************************/
#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "Space.hpp"
#include "Game.hpp"

#ifndef FOREST_HPP
#define FOREST_HPP 

//class Game; //forward declaration

class Forest: public Space 
{
    protected:
        bool solved;
        
    public:
        Forest(int, int, std::string);
        void createSpace();
        void getCutscene();
        bool getSolved();

};

class ForestBR: public Space 
{
    protected:
        
    public:
        ForestBR(int, int, std::string);
        void createSpace();

};

class ForestTR: public Space 
{
    protected:
        
    public:
        ForestTR(int, int, std::string);
        void createSpace();

};

class ForestTL: public Space 
{
    protected:
        
    public:
        ForestTL(int, int, std::string);
        void createSpace();

};
#endif

