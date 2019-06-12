/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Player class implementation file. Contains logic for the 
 *                  main player within the game. The class inherits from the
 *                  MapObjects class, but adds in an additional MapObjects
 *                  vector to hold more MapObjects as items, along with methods
 *                  to manipulate the container.
 * ** *************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "Items.hpp"
#include "MapObjects.hpp"
#include "Player.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/*******************************************************************************
* Player::Player()
*   Constructor for the Player. 
*******************************************************************************/
Player::Player()
    :MapObjects('A', false, false, false, " ") 
{
    //player's icon is 't'
}
/*******************************************************************************
* Player::~Player()
*   Destructor for the player. Needs to deallocate items. 
*******************************************************************************/
Player::~Player()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i] != nullptr)
        {
            delete items[i];
        }
    }

    items.clear();
}



/*******************************************************************************
* void Player::addItem(MapObjects *&itemIn)
*   Method to add an item to the item vector.
*******************************************************************************/
void Player::addItem(MapObjects *&itemIn)
{
    if (items.size() < MAX_INVENTORY)
    {
        items.push_back(itemIn);
    }
    else
    {
        cout << "Inventory full." << endl;
    }
}

/*******************************************************************************
* Player::displayInv()
*   Method to display inventory
*******************************************************************************/
void Player::displayInv()
{
    if (items.empty())
    {
        cout << "You're not carrying anything special" << endl;
    }

    else
    {
        cout << "Inventory" << endl;
        cout << "---------" << endl;

        for (int i = 0; i < items.size(); i++)
        {
            cout << i+1 << ": " << items[i]->getName() << endl;
        }
    }
}

/*******************************************************************************
* Player::searchInv()
*   Method to search through inventory
*******************************************************************************/
bool Player::searchInv(string &stringIn)
{
    if (items.empty())
    {
        cout << "You're not carrying anything" << endl;
        return false;
    }

    else
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (stringIn == items[i]->getName())
            {
                return true;
            }
        }
    }
}

/*******************************************************************************
* Player::checkInvSize()
*   Method to return inventory size
*******************************************************************************/
int Player::checkInvSize()
{
    return items.size();
}
