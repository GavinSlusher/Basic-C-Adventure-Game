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
#include <iostream>
#include <string>
#include "MapObjects.hpp"
#include "Forest.hpp"
#include "NPC.hpp"
#include "solidObjects.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*******************************************************************************
* Forest::Forest()
*   Constructor for Forest class. Takes parameters for width, height and name.
*******************************************************************************/
Forest::Forest(int width, int height, string nameIn)
    :Space(width, height, nameIn) 
{
}

/*******************************************************************************
* void Forest::createSpace()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space. 
*******************************************************************************/
void Forest::createSpace()
{
    //NPC Locations
    int sparRow = 5; int sparCol = 4;

    //Exit Locations
    int tExitRow = 0; int tExitCol = 6;
    int rExitRow = 3; int rExitCol = 13;

    //Rocks 
    int rockRow = 1; int rockCol = 10;
    int rockRow2 = 2; int rockCol2 = 1;
    int rockRow3 = 6; int rockCol3 = 9;

    //Trees
    int treeRow = 4; int treeCol = 2;
    int treeRow2 = 2; int treeCol2 = 9;


    //Create Default Space

    Space::createSpace();
    
    //set NPS objects

    mapObjects[sparRow][sparCol] = new riddleNPC(this);

    //set Map Objects
    mapObjects[rockRow][rockCol] = new Rock();
    mapObjects[rockRow2][rockCol2] = new Rock();
    mapObjects[rockRow3][rockCol3] = new Rock();
    
    mapObjects[treeRow][treeCol] = new Tree();
    mapObjects[treeRow2][treeCol2] = new Tree();

    //set Exits
    mapObjects[tExitRow][tExitCol] = new tExit(this, 5, 6);
    mapObjects[rExitRow][rExitCol] = new rExit(this, 3, 1);
}

/*******************************************************************************
* string Forest::getSolved()
*   returns whether the player has solved the riddle within the Forest Class.
*******************************************************************************/
bool Forest::getSolved()
{
    return solved;
}

/*******************************************************************************
* string Forest::getCutscene()
*   Displays the space's name
*******************************************************************************/
void Forest::getCutscene()
{
    clearScreen();
    cout << " You've been tapping Sparrow's shoulder for 2 hours now." << endl;
    cout << " Your hair seems to still be standing on end. Something" << endl;
    cout << " doesn't feel right..." << endl;
    cout << endl;

    char input = 0;

    do
    {
        input = cabinChoice(); 
    }while(input != '1' && input != '2');

    clearScreen();

    if (input == '1') //just static in the air
    {
        cout << " Yes, just static in the air... That's it.\n" << endl;
        cout << " Suddenly, you hear Pina start to scream. There's shuffling" << endl;
        cout << " somewhere on the other side of the cabin. Pina belts out," << endl;
        cout << " 'When was the last time any of you hit an empty wall?'" << endl;
        cout << endl;
        cout << " And then, 'THERE'S SOMETHING ELSE IN HERE.'" << endl;
        cout << endl;

        solved = false;
    }
    else //figured it out
    {
        cout << " If there's four of us, and one moving to touch someone's" << endl;
        cout << " shoulder at any moment- how come you haven't hit an empty" << endl;
        cout << " space? Unless..." << endl;
        cout << endl;
        cout << " THERE'S SOMETHING ELSE IN HERE." << endl;
        cout << endl;

        solved = true;
    }

    enterToCont();
    clearScreen();

    cout << cutscene;
}

/*******************************************************************************
* ForestBR::ForestBR()
*   Constructor for Forest class. Takes parameters for width, height and name.
*******************************************************************************/
ForestBR::ForestBR(int width, int height, string nameIn)
    :Space(width, height, nameIn) 
{
}

/*******************************************************************************
* void ForestBR::createSpace()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space. 
*******************************************************************************/
void ForestBR::createSpace()
{
    //NPC Locations
    int pepRow = 3; int pepCol = 10;

    //Exit Locations
    int tExitRow = 0; int tExitCol = 6;
    int lExitRow = 3; int lExitCol = 0;

    //Create Default Space

    Space::createSpace();
    
    //Rocks 
    int rockRow = 5; int rockCol = 2;
    int rockRow2 = 1; int rockCol2 = 12;
    int rockRow3 = 6; int rockCol3 = 8;

    //Trees
    int treeRow = 1; int treeCol = 3;
    int treeRow2 = 4; int treeCol2 = 7;

    //set Map Objects
    mapObjects[rockRow][rockCol] = new Rock();
    mapObjects[rockRow2][rockCol2] = new Rock();
    mapObjects[rockRow3][rockCol3] = new Rock();
    
    mapObjects[treeRow][treeCol] = new Tree();
    mapObjects[treeRow2][treeCol2] = new Tree();
    
    //set NPS objects
    mapObjects[pepRow][pepCol] = new endNPC(this);

    //set Exits
    mapObjects[tExitRow][tExitCol] = new tExit(this, 5, 6);
    mapObjects[lExitRow][lExitCol] = new lExit(this, 3, 12);
}

/*******************************************************************************
* ForestTR::ForestTR()
*   Constructor for Forest class. Takes parameters for width, height and name.
*******************************************************************************/
ForestTR::ForestTR(int width, int height, string nameIn)
    :Space(width, height, nameIn) 
{
}

/*******************************************************************************
* void ForestTR::createSpace()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space. 
*******************************************************************************/
void ForestTR::createSpace()
{
    //NPC Locations
    int pepRow = 5; int pepCol = 8;
    int pinaRow = 3; int pinaCol = 4;
    int sparRow = 3; int sparCol = 12;

    //Exit Locations
    int dExitRow = 6; int dExitCol = 6;
    int lExitRow = 3; int lExitCol = 0;
    
    //Rocks 
    int rockRow = 1; int rockCol = 1;
    int rockRow2 = 2; int rockCol2 = 5;
    int rockRow3 = 4; int rockCol3 = 9;

    //Trees
    int treeRow = 5; int treeCol = 3;
    int treeRow2 = 1; int treeCol2 = 10;

    //Create Default Space

    Space::createSpace();

    //set Map Objects
    mapObjects[rockRow][rockCol] = new Rock();
    mapObjects[rockRow2][rockCol2] = new Rock();
    mapObjects[rockRow3][rockCol3] = new Rock();
    
    mapObjects[treeRow][treeCol] = new Tree();
    mapObjects[treeRow2][treeCol2] = new Tree();

    //set Exits
    mapObjects[dExitRow][dExitCol] = new dExit(this, 1, 6);
    mapObjects[lExitRow][lExitCol] = new lExit(this, 3, 12);
}

/*******************************************************************************
* ForestTL::ForestTL()
*   Constructor for Forest class. Takes parameters for width, height and name.
*******************************************************************************/
ForestTL::ForestTL(int width, int height, string nameIn)
    :Space(width, height, nameIn) 
{
}

/*******************************************************************************
* void ForestTL::createSpace()
*   Method that overides the default Space creation by hardcoding MapObjects
*   onto the space. 
*******************************************************************************/
void ForestTL::createSpace()
{
    //NPC Locations
    int sparrowRow = 1; int sparrowCol = 2;

    //Exit Locations
    int dExitRow = 6; int dExitCol = 6;
    int rExitRow = 3; int rExitCol = 13;

    //Create Default Space

    Space::createSpace();
    
    //set NPS objects
    mapObjects[sparrowRow][sparrowCol] = new sAddItem(this);

    //Rocks 
    int rockRow = 0; int rockCol = 6;
    int rockRow2 = 3; int rockCol2 = 1;
    int rockRow3 = 4; int rockCol3 = 9;

    //Trees
    int treeRow = 5; int treeCol = 2;
    int treeRow2 = 1; int treeCol2 = 8;

    //set Map Objects
    mapObjects[rockRow][rockCol] = new Rock();
    mapObjects[rockRow2][rockCol2] = new Rock();
    mapObjects[rockRow3][rockCol3] = new Rock();
    
    mapObjects[treeRow][treeCol] = new Tree();
    mapObjects[treeRow2][treeCol2] = new Tree();

    //set Exits
    mapObjects[dExitRow][dExitCol] = new dExit(this, 1, 6);
    mapObjects[rExitRow][rExitCol] = new rExit(this, 3, 1);
}


