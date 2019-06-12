/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  MapObject class specification file. Contains logic to define
 *                  the objects that will be put in the "map" (2D array) of any
 *                  space class or subclass. Has methods and a constuctor
 *                  to define an object icon, description, and whether or not
 *                  the object is solid, an item, or interactable.
 * ** *************************************************************************/
#ifndef MAPOBJECTS_HPP
#define MAPOBJECTS_HPP 

#include <string>
#include "displayMenu.hpp"
#include "inputValidation.hpp"

const char GRASS= ',';


class MapObjects 
{
    protected:
        //graphics
        char icon;
        std::string description;
        bool interactable;
        bool solid;
        bool item; 
        std::string name;
        
    public:
        MapObjects();
        MapObjects(char, bool, bool, bool, std::string);

        //Methods
        virtual void interact();
        virtual void addItem(MapObjects *&);
        virtual void displayInv();

        //Get Methods
        virtual char getIcon();
        bool getInteractable();
        bool getSolid();
        bool getItem();
        std::string getDescription();
        std::string getName();

        //Set Methods
        virtual void setIcon(char);
        void setInteractable(bool boolIn);
        void setSolid(bool boolIn);
        void setItem(bool boolIn);
        void setDescription(std::string &);
        void setName(string nameIn);

};

#endif
