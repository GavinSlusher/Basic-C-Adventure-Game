/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Camp class implementation file. A subclass of the Space
 * **               class, it customized it's own layout by overriding the 
 * **               createSpace() method.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "MapObjects.hpp"
#include "Camp.hpp"
#include "NPC.hpp"
#include "solidObjects.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*******************************************************************************
* Camp::Camp()
*   Constructor for Camp class. Takes parameters for width, height and name.
*******************************************************************************/
Camp::Camp()
    :Space() 
{
}

/*******************************************************************************
* Camp::Camp()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space. 
*******************************************************************************/
void Camp::createSpace()
{
    //NPC Locations
    int pepRow = 5; int pepCol = 8;
    int pinaRow = 3; int pinaCol = 4;
    int sparRow = 3; int sparCol = 12;

    //NPC Descriptions

    string pinaDesc = " Pina: Go ahead and get going without me! I still need\n";
    pinaDesc += " to break down my tent and pack up my maps.";

    string sparDesc = " Sparrow: I'm almost done packing up! Gosh, do you think\n";
    sparDesc += " all these art supplies are worth carrying? I barely have time to\n";
    sparDesc += " sketch these days.";

    string roniDesc = " Roni: Did you know I used to be a chemistry teacher before\n";
    roniDesc += " all this? It's odd, I kind of miss the lab.\n";

    //Left Tent Locations
    int lTentRow = 2; int lTentCol = 6;
    int lTentRow2 = 7; int lTentCol2 = 3;
    int lTentRow3 = 3; int lTentCol3 = 11;

    //Right Tent Locations
    int rTentRow = 2; int rTentCol = 7;
    int rTentRow2 = 7; int rTentCol2 = 4;

    //Item Locations
    int medTapeRow = 4; int medTapeCol = 1;
    int matchesRow = 9; int matchesCol = 1;
    int shirtRow = 8; int shirtCol = 9;
    int sugarRow = 1; int sugarCol = 12;

    //Exit Locations
    int rExitRow = 4; int rExitCol = 19;

    //Create Default Space

    Space::createSpace();
    
    //set NPC objects

    mapObjects[pepRow][pepCol] = new NPC("Pep", 'R');
    mapObjects[pinaRow][pinaCol] = new NPC("Pina", 'P');
    mapObjects[sparRow][sparCol] = new NPC("Sparrow", 'S');

    //set NPC Descriptions
    mapObjects[pepRow][pepCol]->setDescription(roniDesc);
    mapObjects[pinaRow][pinaCol]->setDescription(pinaDesc);
    mapObjects[sparRow][sparCol]->setDescription(sparDesc);
    
    //set Left Tent objects
    
    mapObjects[lTentRow][lTentCol] = new lTent();
    mapObjects[lTentRow2][lTentCol2] = new lTent();
    mapObjects[lTentRow3][lTentCol3] = new lTent();
    
    //set Right Tent objects
    
    mapObjects[rTentRow][rTentCol] = new rTent();
    mapObjects[rTentRow2][rTentCol2] = new rTent();

    //set Items
    mapObjects[medTapeRow][medTapeCol] = new Item("Medical Tape");
    mapObjects[matchesRow][matchesCol] = new Item("Matches");
    mapObjects[shirtRow][shirtCol] = new Item("A ratty shirt");
    mapObjects[sugarRow][sugarCol] = new Item("Sugar");

    //set Exits
    mapObjects[rExitRow][rExitCol] = new rExit(this, 4, 6);
}

