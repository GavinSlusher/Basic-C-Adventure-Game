/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Game class Specification file. Contains game logic to house
 *                  Spaces, link, declare, and create the scenes between them. 
 *                  Also contains logic to play the game until a Space returns 
 *                  a condition that ends it.
 * ** *************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP 

#include "Space.hpp"
#include "Camp.hpp"
#include "Cabin.hpp"
#include "Forest.hpp"

const int CABIN_WIDTH = 7;
const int CABIN_HEIGHT = 5;
const int FOREST_WIDTH = 14;
const int FOREST_HEIGHT = 7;

class Game 
{
    protected:
        //Spaces
        Camp camp;
        Cabin cabin;
        Cabin2 cabin2;
        Cabin3 cabin3;
        Forest forest;
        ForestBR forestBR;
        ForestTR forestTR;
        ForestTL forestTL;

        Space *currentSpace;

        bool solvedRiddle;
        bool checkEnd;


        //Game variables
        int steps;

    public:
        Game();
        //~Game();
        void mainGame();
        void initializeGame();

        void setCurrentSpace(Space *);

        //Scenes / Descriptors
        void playIntro();
        void setCampScene();
        void setDefaultCamp();
        void setCabinScene();
        void setDefaultCabin();
        void setForestScene();
        void setDefaultForest();

        //Ending Screens
        void goodEnding();
        void neutralEnding1();
        void neutralEnding2();
        void badEnding1();
        void badEnding2();

};

#endif
