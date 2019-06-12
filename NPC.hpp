/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  NPC class specification file. Contains logic to house
 * **               NPCs in the game.
 * ** *************************************************************************/
#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "MapObjects.hpp"

#ifndef NPC_HPP
#define NPC_HPP 

class NPC: public MapObjects 
{
    protected:
        std::string name;
        
    public:
        NPC(std::string, char);

        string getName();

};

#endif

