/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Items class specification file. Contains logic to define
 *                  the objects that will be put in the "map" (2D array) of any
 *                  space class or subclass. Has methods and a constuctor
 *                  to define an object icon, description, and whether or not
 *                  the object is solid, an item, or interactable.
 * ** *************************************************************************/
#include <string>
#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "MapObjects.hpp"

#ifndef ITEMS_HPP
#define ITEMS_HPP 

class Item: public MapObjects 
{
    protected:
        
    public:
        Item(std::string);
        
};

#endif

