/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  MapObject class implementation file. Contains logic to define
 *                  the objects that will be put in the "map" (2D array) of any
 *                  space class or subclass. Has methods and a constuctor
 *                  to define an object icon, description, and whether or not
 *                  the object is solid, an item, or interactable.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "MapObjects.hpp"
#include "displayMenu.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
* MapObjects::MapObjects()
*   Constructor. Set's the default icon to GRASS, and by default the object is
*   not interactable, solid, or an item.
*******************************************************************************/
MapObjects::MapObjects()
    : icon(GRASS), interactable(false), solid(false), item(false)
{
}

/*******************************************************************************
* MapObjects::MapObjects()
*   Constructor. Let's the user set the object's traits.
*******************************************************************************/
MapObjects::MapObjects(char iconIn, bool interIn, bool solidIn, bool itemIn,
        string nameIn)
            : icon(iconIn), interactable(interIn), solid(solidIn), item(itemIn),
                name(nameIn)
{
}

/*******************************************************************************
* void MapObjects::interact()
*   Method to let the user interact with objects. Can be overriden, but by
*   default, displays the object's description.
*******************************************************************************/
void MapObjects::interact()
{
    if (!interactable)
    {
        cout << endl << "You can't interact with that." << endl;
    }

    else
    {
        cout << getDescription() << endl;
    }
}

/*******************************************************************************
* string MapObjects::getDescription()
*   Get the Map Object's description
*******************************************************************************/
string MapObjects::getDescription()
{
    return description;
}

/*******************************************************************************
* void MapObjects::setDescription()
*   Set the Map Object's description
*******************************************************************************/
void MapObjects::setDescription(string &descriptionIn)
{
    description = descriptionIn;
}

/*******************************************************************************
* char MapObjects::getIcon()
*   Get the Map Object's Icon
*******************************************************************************/
char MapObjects::getIcon()
{
    return icon;
}

/*******************************************************************************
* void MapObjects::setIcon()
*   Set the Map Objects Icon
*******************************************************************************/
void MapObjects::setIcon(char iconIn)
{
    icon = iconIn;
}

/*******************************************************************************
* void MapObjects::setInteractable(bool boolIn)
*   Set whether the object is interactable or not
*******************************************************************************/
void MapObjects::setInteractable(bool boolIn)
{
    interactable = boolIn;
}

/*******************************************************************************
* void MapObjects::setSolid(bool boolIn)
*   Set whether the object is a solid
*******************************************************************************/
void MapObjects::setSolid(bool boolIn)
{
    solid = boolIn;
}

/*******************************************************************************
* void MapObjects::setItem(bool boolIn)
*   Set whether the object is is an item
*******************************************************************************/
void MapObjects::setItem(bool boolIn)
{
    item = boolIn;
}

/*******************************************************************************
* void MapObjects::getInteractable(bool boolIn)
*   Returns whether or not the object is interactable
*******************************************************************************/
bool MapObjects::getInteractable()
{
    return interactable;
}

/*******************************************************************************
* void MapObjects::getSolid(bool boolIn)
*   Returns whether or not the object is a solid
*******************************************************************************/
bool MapObjects::getSolid()
{
    return solid;
}

/*******************************************************************************
* void MapObjects::getItem(bool boolIn)
*   Returns whether or not the object is an item
*******************************************************************************/
bool MapObjects::getItem()
{
    return item;
}

/*******************************************************************************
* MapObjects::getName()
*   Returns the MapObjects name
*******************************************************************************/
string MapObjects::getName()
{
    return name;
}

/*******************************************************************************
* MapObjects::setName()
*   Sets the MapObject's Name
*******************************************************************************/
void MapObjects::setName(string nameIn)
{
    name = nameIn;
}

/*******************************************************************************
* virtual void addItem(MapObjects *&);
*   Placeholder for functions inherited
*******************************************************************************/
void MapObjects::addItem(MapObjects *&objectIn)
{
    cout << "You shouldn't be seeing this" << endl;
}

/*******************************************************************************
* virtual void displayInv();
*   Placeholder for functions inherited
*******************************************************************************/
void MapObjects::displayInv()
{
    cout << "You shouldn't be seeing this" << endl;
}
