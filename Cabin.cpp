/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Cabin class implementation file. A subclass of the Space
 * **               class, it customized it's own layout by overriding the 
 * **               createSpace() method. There are multiple Cabin classes,
 * **               but they are essentially the same class hardcoded with 
 * **               different MapObjects.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "MapObjects.hpp"
#include "Cabin.hpp"
#include "NPC.hpp"
#include "solidObjects.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*******************************************************************************
* Cabin::Cabin()
*   Constructor for Cabin class. Takes parameters for width, height and name.
*******************************************************************************/
Cabin::Cabin(int width, int height, string nameIn)
    :Space(width, height, nameIn) 
{
}

/*******************************************************************************
* void Cabin::createSpace()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space.
*******************************************************************************/
void Cabin::createSpace()
{
    //NPC Locations
    int pepRow = 0; int pepCol = 0;
    int pinaRow = 4; int pinaCol = 0;
    int sparRow = 0; int sparCol = 6;

    //Item Locations
    int stumpRow = 2; int stumpCol = 3;
    
    //NPC Descriptions

    string pinaDesc = " Pina: Ahh! Why are you here? Where's Roni?\n";

    string roniDesc = " Roni: Ahh! Why are you here? Where's Pina?\n";

    //Create Default Space

    Space::createSpace();
    
    //set NPS objects

    mapObjects[pepRow][pepCol] = new NPC("Pep", 'R');
    mapObjects[pinaRow][pinaCol] = new NPC("Pina", 'P');
    mapObjects[sparRow][sparCol] = new npcExit(this, 0, 6);
    
    //set NPC Descriptions

    mapObjects[pepRow][pepCol]->setDescription(roniDesc);
    mapObjects[pinaRow][pinaCol]->setDescription(pinaDesc);

    //set Items

    mapObjects[stumpRow][stumpCol] = new Item("Stump Remover");
}

/*******************************************************************************
* Cabin2::Cabin2()
*   Constructor for Cabin class. Takes parameters for width, height and name.
*******************************************************************************/
Cabin2::Cabin2(int width, int height, string nameIn)
    :Space(width, height, nameIn) 
{
}

/*******************************************************************************
* void Cabin2::createSpace()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space.
*******************************************************************************/
void Cabin2::createSpace()
{
    //NPC Locations
    int pepRow = 4; int pepCol = 0;
    int pinaRow = 4; int pinaCol = 6;
    int sparRow = 0; int sparCol = 0;
    
    //NPC Descriptions

    string pinaDesc = " Pina: Ahh! Why are you here? Where's Roni?\n";

    string roniDesc = " Roni: Ahh! Why are you here? Where's Pina?\n";

    //Create Default Space

    Space::createSpace();
    
    //set NPS objects

    mapObjects[pepRow][pepCol] = new NPC("Pep", 'R');
    mapObjects[pinaRow][pinaCol] = new NPC("Pina", 'P');
    mapObjects[sparRow][sparCol] = new npcExit(this, 0, 0);
    
    //set NPC Descriptions
    
    mapObjects[pepRow][pepCol]->setDescription(roniDesc);
    mapObjects[pinaRow][pinaCol]->setDescription(pinaDesc);

}

/*******************************************************************************
* Cabin3::Cabin3()
*   Constructor for Cabin class. Takes parameters for width, height and name.
*******************************************************************************/
Cabin3::Cabin3(int width, int height, string nameIn)
    :Space(width, height, nameIn) 
{
}

/*******************************************************************************
* void Cabin3::createSpace()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space.
*******************************************************************************/
void Cabin3::createSpace()
{
    //NPC Locations
    int pepRow = 4; int pepCol = 6;
    int pinaRow = 0; int pinaCol = 6;
    int sparRow = 4; int sparCol = 0;
    
    //NPC Descriptions

    string pinaDesc = " Pina: Dang, we've been doing this for a while.\n";
    pinaDesc += " I'm getting tired...\n";

    string roniDesc = " Roni: Does something feel off to you?\n";


    //Create Default Space

    Space::createSpace();
    
    //set NPS objects

    mapObjects[pepRow][pepCol] = new NPC("Pep", 'R');
    mapObjects[pinaRow][pinaCol] = new NPC("Pina", 'P');
    mapObjects[sparRow][sparCol] = new npcExit(this, 3, 0);
    
    //set NPC Descriptions

    mapObjects[pepRow][pepCol]->setDescription(roniDesc);
    mapObjects[pinaRow][pinaCol]->setDescription(pinaDesc);

}

