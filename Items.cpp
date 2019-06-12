/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Items class Implementation file. Contains logic to define
 *                  the objects that will be put in the "map" (2D array) of any
 *                  space class or subclass. Has methods and a constuctor
 *                  to define an object icon, description, and whether or not
 *                  the object is solid, an item, or interactable.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "MapObjects.hpp"
#include "Items.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*******************************************************************************
* Items::Items()
*   Constructor for the Vampire. Sets the appropriate character attributes.
*******************************************************************************/
Item::Item( string nameIn)
    :MapObjects('o', true, false, true, nameIn) 
{
    //All items have an icon of'o'
    //They are interactable, but not solid (can walk over to pick them up
}


