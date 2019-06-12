/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  NPC class specification file. Contains logic to house
 * **               NPCs in the game.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "MapObjects.hpp"
#include "NPC.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*******************************************************************************
* Player::NPC()
*   Constructor. Creates a template for NPCs
*******************************************************************************/
NPC::NPC(string nameIn, char charIn)
    :MapObjects(charIn, true, true, false, nameIn) 
{
    //An NPC's icon is 'T', it is interactable, solid, but not an item
}

/*******************************************************************************
* getName::getName()
*   Returns the NPC name
*******************************************************************************/
string NPC::getName()
{
    return name;
}


