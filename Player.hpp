/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Player class specification file. Contains logic for the 
 *                  main player within the game. The class inherits from the
 *                  MapObjects class, but adds in an additional MapObjects
 *                  vector to hold more MapObjects as items, along with methods
 *                  to manipulate the container.
 * ** *************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP 

#include <string>
#include <vector>
#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "Items.hpp"
#include "MapObjects.hpp"

class Player: public MapObjects 
{
    protected:
        const int MAX_INVENTORY = 7;

        std::string name;

        std::vector<MapObjects *> items;
        
    public:
        Player();
        ~Player();

        void setName(std::string);
        std::string getName();
        virtual void addItem(MapObjects *&);
        virtual void displayInv();
        bool searchInv(std::string &);
        int checkInvSize();


};

#endif

