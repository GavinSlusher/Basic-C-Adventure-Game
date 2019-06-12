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
#ifndef SPACE_HPP
#define SPACE_HPP 

#include <iostream>
#include <vector>
//#include "Game.hpp"
#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "MapObjects.hpp"
#include "Player.hpp"

//class Game; //forward declaration

class Space 
{
    protected:

        //map variables
        std::vector<std::vector <MapObjects *> > mapObjects;
        int mapWidth;
        int mapHeight;
        const char FLOOR = ',';

        //Space Features
        std::string name;
        std::string cutscene;
        std::string defaultDescription;
        bool cutscenePlayed;
        bool endGame;


        //Player variables
        int playerRow;
        int playerCol;

        //Pointers
        Space *top;
        Space *bottom;
        Space *left;
        Space *right;

        Space *currentSpace;

    public:
        Space();
        Space(int, int, std::string);
        ~Space();

        //map Methods
        virtual void displaySpace();
        virtual void createSpace() = 0;
        void setPlayer(int row, int col);
        void setPlayer(Player *, int, int);

        //Player methods
        void playerAction(char); 
        void moveUp(); 
        void moveDown(); 
        void moveLeft(); 
        void moveRight(); 
        void interact(); 
        Player *getPlayer();
        void setPlayerNull();
        
        //Space Methods
        void linkSpaces(Space *, Space *, Space *, Space *);  
        void setCurrentSpace(Space *);
        Space *getCurrentSpace();
        void resetCurrentSpace();
        void displayName();
        std::string getName();

        //Space Pointers
        Space *getTop();
        Space *getBottom();
        Space *getLeft();
        Space *getRight();

        //Cutscene Methods
        bool getIfPlayed();
        virtual void getCutscene();
        void getDefDes();
        void setIfPlayed(bool);
        void setCutscene(std::string &);
        void setDefDes(std::string &);

        //EndGame
        bool getEndGame();
        void setEndGame(bool);
};

#endif
