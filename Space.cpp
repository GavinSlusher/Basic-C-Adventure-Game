/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Space class specification file. Contains logic to create,
 *                  display, and move around in a map defined by the 2D array
 *                  of MapObjects within the class. Also has logic to interact
 *                  with MapObjects. Designed as an abstract class, this class
 *                  should be used a base when creating custom "maps" via 
 *                  subclasses.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "displayMenu.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

/*******************************************************************************
* Space::Space()
*   Constructor. Set's a default map size and all links to null
*******************************************************************************/
Space::Space()
    :mapWidth(20), mapHeight(10), top(nullptr), right(nullptr), left(nullptr),
        bottom(nullptr), currentSpace(this), name("  CAMP")
{
    playerRow = 1;
    playerCol = 0;
    cutscenePlayed = false;
    endGame = false;
}

/*******************************************************************************
* Space::Space()
*   Constructor. Let's the user define the map size. Links are still null by
*   default. They are meant to be linked later.
*******************************************************************************/
Space::Space(int mapWidthIn, int mapHeightIn, string nameIn)
    :mapWidth(mapWidthIn), mapHeight(mapHeightIn), top(nullptr), right(nullptr), 
        left(nullptr), bottom(nullptr), currentSpace(this), name(nameIn)
{
    playerRow = 1;
    playerCol = 0;
    cutscenePlayed = false;
    endGame = false;
}

/*******************************************************************************
* void Space::createSpace()
*   Method to create a "map" based on the pre-determined map size. Everything is
*   set to null by default, and all map objects should be "placed" in subclasses
*******************************************************************************/
void Space::createSpace()
{
    for (int i = 0; i < mapHeight; i++)
    {
        //create a vector of vectors pointint to MapObjects
        
        mapObjects.push_back( vector<MapObjects *>() );

        for (int j = 0; j < mapWidth; j++)
        {
            mapObjects[i].push_back(nullptr);
        }
    }
}

/*******************************************************************************
* Space::~Space()
*   Destructor. Deletes any objects in the vector, if one was created.
*******************************************************************************/
Space::~Space()
{
    if(!mapObjects.empty())
    {
        if (mapObjects[playerRow][playerCol] != nullptr)
        {
            delete dynamic_cast<Player *>(mapObjects[playerRow][playerCol]);

            mapObjects[playerRow][playerCol] = nullptr;
        }
    }

    for (int i = 0; i < mapObjects.size(); i++)
    {
        for (int j = 0; j < mapObjects[i].size(); j++)
        {
            if (mapObjects[i][j] != nullptr) //if there's an object to delete
            {
                delete mapObjects[i][j];
            }
        }
    }
}

/*******************************************************************************
* Space::displaySpace()
*   Method to display the 2D array, and thereby display the "map". If one wants
*   to change the default "floor," they should change the FLOOR char in the 
*   subclass.
*******************************************************************************/
void Space::displaySpace()
{
    cout << "+"; //corner

    for (int j = 0; j < mapWidth; j++)
    {
        cout << "-";
    }
    
    cout << "+"; //corner

    cout << endl;

    for (int i = 0; i < mapHeight; i++)
    {
        cout << "|"; //Border at the beginning

        for (int j = 0; j < mapWidth; j++)
        {
            if (mapObjects[i][j] == nullptr) //default ground display
            {
                cout << FLOOR;
            }

            else
            {
            cout << mapObjects[i][j]->getIcon();
            }
        }

        cout << "|" << endl; //Border at end of line
    }

    cout << "+"; //corner
    
    for (int j = 0; j < mapWidth; j++)
    {
        cout << "-";
    }
    
    cout << "+"; //corner

    cout << endl;
}

/*******************************************************************************
* Space::movePlayer()
*   Method to control a player's action, whether that's to move, interact, or
*   quit. Checks to make sure that the action is within bounds, if the adjacent
*   position is already filled with an object or not, and it takes the
*   appropriate action accordingly.
*******************************************************************************/
void Space::playerAction(char action)
{
    switch(action)
    {
        //Player wants to move UP

        case 'w':
            
            if (!playerRow - 1 < 0)
            {
                if (mapObjects[playerRow - 1][playerCol] == nullptr) //if empty
                {
                    moveUp();
                }
                
                //Order matters here! Need to check item first
                
                else if (mapObjects[playerRow - 1][playerCol]->getItem()) 
                {
                    mapObjects[playerRow][playerCol]->addItem(
                        mapObjects[playerRow - 1][playerCol]);
                    
                    //note: don't need to worry about memory leaks because
                    //the Player class should take care of items added to 
                    //it's inventory

                    moveUp();

                    cout << "You picked up an item!" << endl;
                }

                else if (!mapObjects[playerRow - 1][playerCol]->getSolid()) 
                {
                    moveUp();
                }

                else
                {
                    cout << "Can't go up there." << endl;
                }
            }

            else
            {
                cout << "You can't go there." << endl;
            }

        break;

        //Player wants to move DOWN
        
        case 's':
        
            if (playerRow + 1 < mapHeight)
            {
                if (mapObjects[playerRow + 1][playerCol] == nullptr)
                {
                    moveDown();
                }
                
                else if (mapObjects[playerRow + 1][playerCol]->getItem()) 
                {
                    mapObjects[playerRow][playerCol]->addItem(
                        mapObjects[playerRow + 1][playerCol]);
                    
                    //note: don't need to worry about memory leaks because
                    //the Player class should take care of items added to 
                    //it's inventory

                    moveDown();
                    
                    cout << "You picked up an item!" << endl;
                }

                else if (!mapObjects[playerRow + 1][playerCol]->getSolid())
                {
                    moveDown();
                }

                else
                {
                    cout << endl << "Can't move down there." << endl;
                }
            }

            else
            {
                cout << "You can't go there." << endl;
            }

        break;

        //Player wants to move to the LEFT

        case 'a':
        
            if (!playerCol - 1 < 0)
            {
                if (mapObjects[playerRow][playerCol - 1] == nullptr)
                {
                    moveLeft();
                }
                
                else if (mapObjects[playerRow][playerCol - 1]->getItem()) 
                {
                    mapObjects[playerRow][playerCol]->addItem(
                        mapObjects[playerRow][playerCol - 1]);
                    
                    //note: don't need to worry about memory leaks because
                    //the Player class should take care of items added to 
                    //it's inventory

                    moveLeft();
                    
                    cout << "You picked up an item!" << endl;
                }

                else if (!mapObjects[playerRow][playerCol - 1]->getSolid())
                {
                    moveLeft();
                }
                
                else
                {
                    cout << "You can't go there." << endl;
                }
            }

            else
            {
                cout << "You can't go there." << endl;
            }

        break;

        //Player wants to move to the RIGHT

        case 'd':
        
            if (playerCol + 1 < mapWidth)
            {
                if (mapObjects[playerRow][playerCol + 1] == nullptr)
                {
                    moveRight();
                }
                
                else if (mapObjects[playerRow][playerCol + 1]->getItem()) 
                {
                    mapObjects[playerRow][playerCol]->addItem(
                        mapObjects[playerRow][playerCol + 1]);
                    
                    //note: don't need to worry about memory leaks because
                    //the Player class should take care of items added to 
                    //it's inventory

                    moveRight();
                    
                    cout << "You picked up an item!" << endl;
                }

                else if (!mapObjects[playerRow][playerCol + 1]->getSolid())
                {
                    moveRight();
                }
                
                else
                {
                    cout << "You can't go there." << endl;
                }
            }

            else
            {
                cout << "You can't go there." << endl;
            }

        break;
        
        case 'e':

            interact();

        break;
        
        case 'i':

            mapObjects[playerRow][playerCol]->displayInv();

        break;

        default:

            cout << "Goodbye" << endl;

        break;
    }
}

/*******************************************************************************
* Space::setPlayer()
*   Places the player object in the designated row and column within the
*   mapObjects vector. Takes the character as a parameter
*******************************************************************************/
void Space::setPlayer(Player *playerIn, int rowIn, int colIn)
{
    if (playerIn == nullptr)
    {
        cout << "Couldn't find the player pointer" << endl;
    }

    else
    {
        mapObjects[rowIn][colIn] = playerIn;
    }

    playerRow = rowIn;
    playerCol = colIn;
}

/*******************************************************************************
* Space::setPlayer()
*   Places the player object in the designated row and column within the
*   mapObjects vector. Creates a new character.
*******************************************************************************/
void Space::setPlayer(int rowIn, int colIn)
{
    mapObjects[rowIn][colIn] = new Player();

    playerRow = rowIn;
    playerCol = colIn;
}

/*******************************************************************************
* Space::getPlayer()
*   Returns player within the map
*******************************************************************************/
Player *Space::getPlayer()
{
    return dynamic_cast<Player *>(mapObjects[playerRow][playerCol]);
}

/*******************************************************************************
* void Space::setPlayerNull()
*   Sets the player location to null
*******************************************************************************/
void Space::setPlayerNull()
{
    mapObjects[playerRow][playerCol] = nullptr;
}

/*******************************************************************************
* Space::moveUp()
*   Moves the player one space "up" in the mapObjects 2D array
*******************************************************************************/
void Space::moveUp()
{
    if (!playerRow - 1 < 0)
    {
        //update new location with object
        mapObjects[playerRow - 1][playerCol] = mapObjects[playerRow][playerCol]; 
        
        //replace old location
        mapObjects[playerRow][playerCol] = nullptr; 

        //update player location
        playerRow--;
    }

    else
    {
        cout << endl << "Can't move up there." << endl;
    }
}

/*******************************************************************************
* Space::moveDown()
*   Moves the player one space "Down" in the mapObjects 2D array
*******************************************************************************/
void Space::moveDown()
{
    if (playerRow + 1 < mapHeight)
    {
        //update new location with object
        mapObjects[playerRow + 1][playerCol] = mapObjects[playerRow][playerCol]; 
        
        //replace old location
        mapObjects[playerRow][playerCol] = nullptr; 

        //update player location
        playerRow++;
    }

    else
    {
        cout << endl << "Can't move down there." << endl;
    }
}

/*******************************************************************************
* Space::moveLeft()
*   Moves the player one space "Left" in the mapObjects 2D array
*******************************************************************************/
void Space::moveLeft()
{
    if (!playerCol - 1 < 0)
    {
        //update new location with object
        mapObjects[playerRow][playerCol - 1] = mapObjects[playerRow][playerCol]; 
        
        //replace old location
        mapObjects[playerRow][playerCol] = nullptr; 

        //update player location
        playerCol--;
    }
    
    else
    {
        cout << endl << "Can't move there." << endl;
    }
}

/*******************************************************************************
* Space::moveRight()
*   Moves the player one space "Right" in the mapObjects 2D array
*******************************************************************************/
void Space::moveRight()
{
    if (playerCol + 1 < mapWidth)
    {
        //update new location with object
        mapObjects[playerRow][playerCol + 1] = mapObjects[playerRow][playerCol]; 
        
        //replace old location
        mapObjects[playerRow][playerCol] = nullptr; 

        //update player location
        playerCol++;
    }
    
    else
    {
        cout << endl << "Can't move there." << endl;
    }
}

/*******************************************************************************
* Space::interact()
*   Checks all the adjecent spaces next to the character, and interacts with
*   the space, if appropriate.
*******************************************************************************/
void Space::interact()
{
 //   MapObjects *spaceAbove = mapObjects[playerRow - 1][playerCol]; 
 //   MapObjects *spaceBelow = mapObjects[playerRow + 1][playerCol]; 
 //   MapObjects *spaceLeft = mapObjects[playerRow][playerCol - 1]; 
 //   MapObjects *spaceRight = mapObjects[playerRow][playerCol + 1]; 

    if (!playerRow - 1 < 0)
    {
        if (mapObjects[playerRow - 1][playerCol] != nullptr)
        {
            mapObjects[playerRow - 1][playerCol]->interact();
        }
    }

    if (playerRow + 1 < mapHeight)
    {
        if (mapObjects[playerRow + 1][playerCol] != nullptr)
        {
            mapObjects[playerRow + 1][playerCol]->interact();
        }
    }
    
    if (!playerCol - 1 < 0)
    {
        if (mapObjects[playerRow][playerCol - 1] != nullptr)
        {
            mapObjects[playerRow][playerCol - 1]->interact();
        }
    }
        
    if (playerCol + 1 < mapWidth)
    {
        if (mapObjects[playerRow][playerCol + 1] != nullptr)
        {
            mapObjects[playerRow][playerCol + 1]->interact();
        }
    }

    else
    {
        //cout << "There's nothing there." << endl;
    }
}

/*******************************************************************************
* Space::setCurrentSpace()
*   Sets the currentSpace pointer
*******************************************************************************/
void Space::setCurrentSpace(Space *spaceIn)
{
    currentSpace = spaceIn;
}

/*******************************************************************************
* Space *Space::getCurrentSpace()
*   Gets the currentSpace pointer
*******************************************************************************/
Space *Space::getCurrentSpace()
{
    return currentSpace;
}

/*******************************************************************************
* Space *Space::getTop()
*   Gets the top pointer
*******************************************************************************/
Space *Space::getTop()
{
    return top;
}

/*******************************************************************************
* Space *Space::getBottom()
*   Gets the bottom pointer
*******************************************************************************/
Space *Space::getBottom()
{
    return bottom;
}

/*******************************************************************************
* Space *Space::getLeft()
*   Gets the left pointer
*******************************************************************************/
Space *Space::getLeft()
{
    return left;
}

/*******************************************************************************
* Space *Space::getRight()
*   Gets the right pointer
*******************************************************************************/
Space *Space::getRight()
{
    return right;
}

/*******************************************************************************
* void *Space::resetCurrentSpace()
*   Resets the currentSpace pointer to point to this space
*******************************************************************************/
void Space::resetCurrentSpace()
{
    currentSpace = this;
}

/*******************************************************************************
* void Space::linkSpaces()
*   Links the surrounding spaces
*******************************************************************************/
void Space::linkSpaces(Space *topIn, Space *bottomIn, Space *leftIn, Space *rightIn)
{
    top = topIn;
    bottom = bottomIn;
    left = leftIn;
    right = rightIn;
}

/*******************************************************************************
* void Space::displayName()
*   Displays the space's name
*******************************************************************************/
void Space::displayName()
{
    cout << name << endl;
}

/*******************************************************************************
* string Space::getName()
*   Returns the space's name
*******************************************************************************/
string Space::getName()
{
    return name;
}

/*******************************************************************************
* bool Space::getIfPlayed()
*   Returns if the cutscene boolean has been flipped or not.
*******************************************************************************/
bool Space::getIfPlayed()
{
    return cutscenePlayed;
}

/*******************************************************************************
* string Space::getCutscene()
*   Displays the cutscene for the space as a string
*******************************************************************************/
void Space::getCutscene()
{
    cout << cutscene;
}

/*******************************************************************************
* string Space::getDefDes()
*   Returns the space's default description as a string
*******************************************************************************/
void Space::getDefDes()
{
    cout << defaultDescription;
}

/*******************************************************************************
* void Space::setIfPlayed()
*   sets whether the cutscene has been played with a boolean
*******************************************************************************/
void Space::setIfPlayed(bool boolIn)
{
    cutscenePlayed = boolIn;
}

/*******************************************************************************
* void Space::setCutscene()
*   Sets the cutscent using a string parameter
*******************************************************************************/
void Space::setCutscene(string &stringIn)
{
    cutscene = stringIn;
}

/*******************************************************************************
* void Space::setDefDes()
*   Sets the default description using the string parameter
*******************************************************************************/
void Space::setDefDes(string &stringIn)
{
    defaultDescription = stringIn;
}

/*******************************************************************************
* bool Space::getEndGame()
*   Returns the endGame bool;
*******************************************************************************/
bool Space::getEndGame()
{
    return endGame;
}

/*******************************************************************************
* void Space::setEndGame()
*   Sets the endGame bool
*******************************************************************************/
void Space::setEndGame(bool endGameIn)
{
    endGame = endGameIn;
}
