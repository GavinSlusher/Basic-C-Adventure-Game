/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  File to store all "solid objects" as defined by a boolean
 *                  set by the MabObjects class. This is the implementation file  
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "MapObjects.hpp"
#include "Space.hpp"
#include "solidObjects.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*******************************************************************************
* rTent::rTent()
*   Constructor for the rTent object
*******************************************************************************/
rTent::rTent()
    :MapObjects(RTENT, true, true, false, " ") 
{
    description = "It's a tent flap";
}

/*******************************************************************************
* lTent::lTent()
*   Constructor for the lTent object
*******************************************************************************/
lTent::lTent()
    :MapObjects(LTENT, true, true, false, " ") 
{
    description = "It's a tent flap";
}

/*******************************************************************************
* Rock::Rock()
*   Constructor for the Rock object
*******************************************************************************/
Rock::Rock()
    :MapObjects(ROCK, true, true, false, " ") 
{
    description = "It's a rock.";
}

/*******************************************************************************
* Tree::Tree()
*   Constructor for the Tree object
*******************************************************************************/
Tree::Tree()
    :MapObjects(TREE, true, true, false, " ") 
{
    description = "It's a tree";
}

/*******************************************************************************
* rExit::rExit()
*   Constructor for the rExit. Needs extra parameters to know what Space the
*   object is currently in, and what coordinates to output to.
*******************************************************************************/
rExit::rExit(Space *currentSpaceIn, int rowIn, int colIn)
    :MapObjects(EXIT, true, true, false, " "), thisSpace(currentSpaceIn),
        exitRow(rowIn), exitCol(colIn) 
{
}

/*******************************************************************************
* void rExit::interact()
*   Method to overide the interact() function so that the current space sends
*   a signal to the Space object that it's in, to tell the game to move on to 
*   the next Space. Also copies the player while doing so.
*******************************************************************************/
void rExit::interact()
{
    //move the player and set to null so no seg fault

    thisSpace->getRight()->setPlayer((thisSpace->getPlayer()), exitRow, exitCol);

    thisSpace->setPlayerNull();

    //set the current space to the new one

    thisSpace->getRight()->resetCurrentSpace();

    thisSpace->setCurrentSpace(thisSpace->getRight());
}

/*******************************************************************************
* npcExit::npcExit()
*   Constructor for the npcExit. Needs extra parameters to know what Space the
*   object is currently in, and what coordinates to output to.
*******************************************************************************/
npcExit::npcExit(Space *currentSpaceIn, int rowIn, int colIn)
    :MapObjects(NPC_EXIT, true, true, false, " "), thisSpace(currentSpaceIn),
        exitRow(rowIn), exitCol(colIn) 
{
}

/*******************************************************************************
* void npcExit::interact()
*   Method to overide the interact() function so that the current space sends
*   a signal to the Space object that it's in, to tell the game to move on to 
*   the next Space. Also copies the player while doing so.
*******************************************************************************/
void npcExit::interact()
{
    //move the player and set to null so no seg fault

    thisSpace->getRight()->setPlayer((thisSpace->getPlayer()), exitRow, exitCol);

    thisSpace->setPlayerNull();

    //set the current space to the new one

    thisSpace->setCurrentSpace(thisSpace->getRight());
}

/*******************************************************************************
* sAddItem::sAddItem()
*   Constructor for sAddItem(). Needs extra parameters to know what Space the
*   object is currently in
*******************************************************************************/
sAddItem::sAddItem(Space *currentSpaceIn)
    :MapObjects(NPC_ADD_ITEM, true, true, false, " "), thisSpace(currentSpaceIn)
{
}

/*******************************************************************************
* sAddItem::interact()
*   Method to overide parent interact() function so that the object can "give"
*   the player an item.
*******************************************************************************/
void sAddItem::interact()
{
    cout << " Sparrow: There's got to be a way for us to get out of here!" << endl;
    cout << " Sparrow: Do you think these will help with something?" << endl;

    cout << endl;
    cout << " *Acquired Oil Pastels!*" << endl;
    enterToCont();

    MapObjects *itemIn = new Item("Oil Pastels"); 

    thisSpace->getPlayer()->addItem(itemIn);
}

/*******************************************************************************
* endNPC::endNPC()
*   Constructor for the endNPC. Needs extra parameters to know what Space the
*   object is currently in
*******************************************************************************/
endNPC::endNPC(Space *currentSpaceIn)
    :MapObjects(END_NPC, true, true, false, " "), thisSpace(currentSpaceIn)
{
}

/*******************************************************************************
* endNPC::interact()
*  Method to overide the interact() so that the object can end the game. 
*******************************************************************************/
void endNPC::interact()
{
    clearScreen();
    cout << " Roni: I hear a helicopter! If only we could signal it somehow..." << endl;
    cout << endl;
    enterToCont();
    clearScreen();

    char input;

    do
    {
        input = endChoice(); 
    }while(input != '1' && input != '2');

    clearScreen();

    if (input == '1')
    {
        thisSpace->setEndGame(true);
    }
}

/*******************************************************************************
* riddleNPC::riddleNPC()
*   Constructor for the npcExit. Needs extra parameters to know what Space the
*   object is currently in
*******************************************************************************/
riddleNPC::riddleNPC(Forest *currentSpaceIn)
    :MapObjects(RIDDLE_NPC, true, true, false, " "), thisSpace(currentSpaceIn)
{
}

/*******************************************************************************
* riddleNPC::interact()
*   Method to overide the interact() function so that the current space can send
*   a signal to the Space object that it's in, so that the NPC can return 
*   dialogue dependent on a boolean set by the Space object it's in.
*******************************************************************************/
void riddleNPC::interact()
{
    clearScreen();

    if(thisSpace->getSolved()) //solved riddle
    {
        cout << " You see Pina there gasping for breath." << endl;
        cout << endl;
        cout << " Pina: What the hell was that thing? ...I think I was the last" << endl;
        cout << " one out the door... I kept feeling something sharp and cold in" << endl;
        cout << " my chest, but I ran and ran and ran... until I felt warm again." << endl;
        cout << endl;
        cout << " Pina: Hey man, listen." << endl;
        cout << endl;
        cout << " He pulls out his maps." << endl;
        cout << endl;
        cout << " Pina: Look. There's a trailhead parking lot two miles east from here." << endl;
    }

    else
    {
        cout << " You see a mangled form in the grass." << endl;
        cout << " Oh god... it's Pina" << endl;
    }
    cout << endl;
    enterToCont();
    clearScreen();
}

/*******************************************************************************
* lExit::lExit()
*   Constructor for the lExit class. Needs extra parameters to know what Space the
*   object is currently in, and what coordinates to output to.
*******************************************************************************/
lExit::lExit(Space *currentSpaceIn, int rowIn, int colIn)
    :MapObjects(EXIT, true, true, false, " "), thisSpace(currentSpaceIn),
        exitRow(rowIn), exitCol(colIn) 
{
}

/*******************************************************************************
* void lExit::interact()
*   Method to overide the interact() function so that the current space sends
*   a signal to the Space object that it's in, to tell the game to move on to 
*   the next Space. Also copies the player while doing so.
*******************************************************************************/
void lExit::interact()
{
    //move the player and set to null so no seg fault

    thisSpace->getLeft()->setPlayer((thisSpace->getPlayer()), exitRow, exitCol);

    thisSpace->setPlayerNull();

    //set the current space to the new one
    thisSpace->getLeft()->resetCurrentSpace();

    thisSpace->setCurrentSpace(thisSpace->getLeft());
}

/*******************************************************************************
* tExit::tExit()
*   Constructor for the tExit. Needs extra parameters to know what Space the
*   object is currently in, and what coordinates to output to.
*******************************************************************************/
tExit::tExit(Space *currentSpaceIn, int rowIn, int colIn)
    :MapObjects(EXIT, true, true, false, " "), thisSpace(currentSpaceIn),
        exitRow(rowIn), exitCol(colIn) 
{
}

/*******************************************************************************
* void tExit::interact()
*   Method to overide the interact() function so that the current space sends
*   a signal to the Space object that it's in, to tell the game to move on to 
*   the next Space. Also copies the player while doing so.
*******************************************************************************/
void tExit::interact()
{
    //move the player and set to null so no seg fault

    thisSpace->getTop()->setPlayer((thisSpace->getPlayer()), exitRow, exitCol);

    thisSpace->setPlayerNull();

    //set the current space to the new one
    thisSpace->getTop()->resetCurrentSpace();

    thisSpace->setCurrentSpace(thisSpace->getTop());
}

/*******************************************************************************
* dExit::dExit()
*   Constructor for the dExit. Needs extra parameters to know what Space the
*   object is currently in, and what coordinates to output to.
*******************************************************************************/
dExit::dExit(Space *currentSpaceIn, int rowIn, int colIn)
    :MapObjects(EXIT, true, true, false, " "), thisSpace(currentSpaceIn),
        exitRow(rowIn), exitCol(colIn) 
{
}

/*******************************************************************************
* void dExit::interact()
*   Method to overide the interact() function so that the current space sends
*   a signal to the Space object that it's in, to tell the game to move on to 
*   the next Space. Also copies the player while doing so.
*******************************************************************************/
void dExit::interact()
{
    //move the player and set to null so no seg fault

    thisSpace->getBottom()->setPlayer((thisSpace->getPlayer()), exitRow, exitCol);

    thisSpace->setPlayerNull();

    //set the current space to the new one
    //reset the coming space so that we don't get duplicates pointers...
    thisSpace->getBottom()->resetCurrentSpace();

    thisSpace->setCurrentSpace(thisSpace->getBottom());
}

