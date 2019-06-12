/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Main file. Contains main logic to create the Game class 
 *                  and run the game. Also seeds the random number generator
 *                  here because seeding rand() every time we call the function
 *                  would result in errors. 
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include "displayMenu.hpp"
#include "Game.hpp"

int main()
{
    int choice;

    do
    {
        choice = displayMenu();

        if (choice == 1)
        {
            Game finalProject;
            finalProject.mainGame();
        }

        //finalProject.~Game(); //deallocate in case want to play again

    }while (choice != 2);

    return 0;
}
