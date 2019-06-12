/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  Game class implementation file. Contains game logic to house
 *                  Spaces, link, declare, and create the scenes between them. 
 *                  Also contains logic to play the game until a Space returns 
 *                  a condition that ends it.
 * ** *************************************************************************/
#include <iostream>
#include <string>
#include "Game.hpp"
#include "displayMenu.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
* Game::Game()
*   Constructor. Takes no parameters and hardcodes the appropriate spaces
*   within the game. Also sets other game conditions.
*******************************************************************************/
Game::Game()
    : camp(),
        cabin(CABIN_WIDTH, CABIN_HEIGHT, "  CABIN"), 
        cabin2(CABIN_WIDTH, CABIN_HEIGHT, "  CABIN"),
        cabin3(CABIN_WIDTH, CABIN_HEIGHT, "  CABIN"), 
        forest(FOREST_WIDTH, FOREST_HEIGHT, "  FOREST III"), 
        forestBR(FOREST_WIDTH, FOREST_HEIGHT, "  FOREST IV"), 
        forestTR(FOREST_WIDTH, FOREST_HEIGHT, "  FOREST II"), 
        forestTL(FOREST_WIDTH, FOREST_HEIGHT, "  FOREST I") 
{
    steps = 350;
    solvedRiddle = false;
    checkEnd = false;
}

/*******************************************************************************
* void Game::initializeGame()
*   Method to initialize the game. Creats Spaces, links them, sets their 
*   transition scenes, and sets the starting space and player location.
*******************************************************************************/
void Game::initializeGame()
{
    //Create Spaces
    camp.createSpace();
    cabin.createSpace();
    cabin2.createSpace();
    cabin3.createSpace();
    forest.createSpace();
    forestBR.createSpace();
    forestTR.createSpace();
    forestTL.createSpace();

    //Link Spaces
    camp.linkSpaces(nullptr, nullptr, nullptr, &cabin);
    cabin.linkSpaces(nullptr, nullptr, nullptr, &cabin2);
    cabin2.linkSpaces(nullptr, nullptr, nullptr, &cabin3);
    cabin3.linkSpaces(nullptr, nullptr, nullptr, &forest);
    forest.linkSpaces(&forestTL, nullptr, nullptr, &forestBR);
    forestBR.linkSpaces(&forestTR, nullptr, &forest, nullptr);
    forestTR.linkSpaces(nullptr, &forestBR, &forestTL, nullptr);
    forestTL.linkSpaces(nullptr, &forest, nullptr, &forestTR);

    //Set Descriptions / Cutscenes
    setCampScene();
    setDefaultCamp();
    setCabinScene();
    setDefaultCabin();
    setForestScene();
    setDefaultForest();
    
    //Set Default Start
    currentSpace = &camp;
    camp.setPlayer(7, 5);
}
/*******************************************************************************
* void Game::mainGame()
*   Main game function. Contains logic for the Main Game: 
*******************************************************************************/
void Game::mainGame()
{
    initializeGame();

    playIntro();

    currentSpace->getCutscene();
    cout << endl;
    currentSpace->setIfPlayed(true);

    currentSpace->displaySpace();

    char move;

    do
    {
        move = movement();
        clearScreen();
        currentSpace->playerAction(move);
        currentSpace = currentSpace->getCurrentSpace();
        if(move != 'q')
        {

            if (!currentSpace->getIfPlayed())
            {
                currentSpace->getCutscene();
                currentSpace->setIfPlayed(true);
            }
            else
            {
                cout << endl;
                currentSpace->getDefDes();
            }

            if (currentSpace->getName() == "  FOREST III")
            {
                solvedRiddle = dynamic_cast<Forest *>(currentSpace)->getSolved();
            }

            checkEnd = currentSpace->getEndGame();

            cout << endl;
            currentSpace->displayName();
            currentSpace->displaySpace();
            steps--;
            cout << "Actions left: " << steps << endl << endl;
        }
    }while(steps != 0 && move != 'q' && checkEnd == false);

    if (steps == 0)
    {
        badEnding1();
    }

    else if (move == 'q')
    {
        cout << " " << endl;
    }

    else if (solvedRiddle == true && currentSpace->getPlayer()->checkInvSize() == 6)
    {
        goodEnding();
    }

    else if (solvedRiddle == true && currentSpace->getPlayer()->checkInvSize() <  6)
    {
        neutralEnding1();
    }
    
    else if (solvedRiddle == false && currentSpace->getPlayer()->checkInvSize() ==  6)
    {
        neutralEnding2();
    }

    else
    {
        badEnding2();
    }
        
}

/*******************************************************************************
* Game::setCurrentSpace()
*   Sets the currentSpace pointer
*******************************************************************************/
void Game::setCurrentSpace(Space *spaceIn)
{
    currentSpace = spaceIn;
}

/*******************************************************************************
* Game::playIntro()
*   Plays game intro
*******************************************************************************/
void Game::playIntro()
{
    clearScreen();

    string Intro = " PRELUDE: You are a Pacific Crest Trail thru-hiker,\n";
    Intro += " hiking from Mexico to Canada in a 5 month journey to 'find yourself.'\n";
    Intro += " Along the way, you've joined three others. You don't know their\n";
    Intro += " real names, but their trail names are Pepperoni, Sparrow, and Pina Colada.\n";
    Intro += " The goal of this game will be to play out the ensuing events, gather items,\n";
    Intro += " solve puzzles, and escape alive...\n";

    cout << Intro << endl << endl;
    
    enterToCont();

    cout << endl;

    string symbExplanation = " The game is represented by ASCII characters: \n";
    symbExplanation += " 'A': You 'R': Pepperoni 'S': Sparrow 'P': Pina Colada\n";
    symbExplanation += " 'o': An item 'X':A door to another area\n";
    symbExplanation += "\n Everything else is just cosmetic. Good luck.";

    cout << symbExplanation << endl << endl;
    
    enterToCont();
    
    clearScreen();
}

/*******************************************************************************
* Game::setCampScene()
*   Sets the Camp scene
*******************************************************************************/
void Game::setCampScene()
{
    string campScene = " ACT I\n";
    campScene += " -----\n";
    campScene += "\n";
    campScene += " Another 5AM wake-up. You can hear Roni outside your tent\n";
    campScene += " yelling, 'Wakey wakey, eggs and bakey!'\n\n If only. You haven't";
    campScene += " had eggs and bacons for weeks. Anyway, it's time for you to \n";
    campScene += " get out of bed and pack up. Time to get moving.\n";

    camp.setCutscene(campScene);
}

/*******************************************************************************
* Game::setDefaultCamp()
*   Sets the default camp message
*******************************************************************************/
void Game::setDefaultCamp()
{
    string defaultScene = " Better pack up and get moving.\n";

    camp.setDefDes(defaultScene);
}

/*******************************************************************************
* Game::setCabinScene()
*   Sets the Cabin scene
*******************************************************************************/
void Game::setCabinScene()
{
    string cabinScene = " ACT II\n";
    cabinScene += " ------\n";
    cabinScene += "\n";
    cabinScene += " Rain and Thunder! The moment you began hiking, it began to pour.\n";
    cabinScene += " One bolt struck so close, you could feel the hairs on the back\n";
    cabinScene += " of your neck standing up from the static. What's worse, that\n";
    cabinScene += " strike must have had some weird, EMP-Like effects because all\n";
    cabinScene += " your electronics are out. Including your group's headlamps.\n";
    cabinScene += "\n";
    cabinScene += " Luckily, Pina had paper maps with him and found a cabin not\n";
    cabinScene += " too far off trail...\n";
    cabinScene += "\n";
    cabinScene += " That's where our luck seems to end, though. On the inside of\n";
    cabinScene += " the cabin door reads: 'Come and stay as you like, but do NOT\n";
    cabinScene += " fall asleep. Else, it will find you. And you will die.'\n";
    cabinScene += "\n";
    cabinScene += " Your fellow travelors seem pretty superstitious, so they've\n";
    cabinScene += " resolved themselves to staying awake for the night while we\n";
    cabinScene += " wait out the storm. The cabin's pitch black, and you can \n";
    cabinScene += " barely see your own hand in front of your face. The current\n";
    cabinScene += " plan is to have one of each of the group stand in a corner,\n";
    cabinScene += " and have one person walk from one corner along the wall to \n";
    cabinScene += " the next, tapping the next person to make sure they're awake.\n";
    cabinScene += "\n";
    cabinScene += " You're going to be doing this all night. Better get started...\n";
    

    cabin.setCutscene(cabinScene);
}

/*******************************************************************************
* Game::setDefaultCamp()
*   Sets the default cabin message
*******************************************************************************/
void Game::setDefaultCabin()
{
    string defaultScene = " I have to tap Sparrow's shoulder to make sure we\n";
    defaultScene += " all stay awake.\n";

    cabin.setDefDes(defaultScene);

    cabin2.setCutscene(defaultScene);
    cabin2.setDefDes(defaultScene);

    cabin3.setCutscene(defaultScene);
    cabin3.setDefDes(defaultScene);
}

/*******************************************************************************
* Game::setForestScene()
*   Sets the Forest Scene
*******************************************************************************/
void Game::setForestScene()
{
    string forestScene = " ACT III\n";
    forestScene += " -------\n";
    forestScene += "\n";
    forestScene += " The four of you scramble over each other towards the cabin entrance\n";
    forestScene += " Hands over elbows, you can't tell who you pushed out of the\n";
    forestScene += " way, but you're the second one out the door. Outside now, you can see dawn \n";
    forestScene += " breaking in the distance into a blood-red sunrise. The four of you\n";
    forestScene += " scatter into the surrounding woods. And not far behind, a shadow\n";
    forestScene += " follows too...\n";
    

    forest.setCutscene(forestScene);
}

/*******************************************************************************
* Game::setDefaultCamp()
*   Sets the default forest message
*******************************************************************************/
void Game::setDefaultForest()
{
    string defaultScene = " We have to find some way to get out of here.\n";

    forest.setDefDes(defaultScene);

    forestBR.setCutscene(defaultScene);
    forestBR.setDefDes(defaultScene);

    forestTR.setCutscene(defaultScene);
    forestTR.setDefDes(defaultScene);
    
    forestTL.setCutscene(defaultScene);
    forestTL.setDefDes(defaultScene);
}

/*******************************************************************************
* Game::goodEnding()
*   Sets the good ending for the game.
*******************************************************************************/
void Game::goodEnding()
{
    clearScreen();

    cout << " The four of you sprint to the trailhead parking lot Pina mentioned." << endl;
    cout << " Thank god for his maps!! You get there, and you can still hear the faint" << endl;
    cout << " whirring of helicopter blades. You guess it must be out here scouting for" << endl;
    cout << " wildfires from the storm." << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " Roni gets an idea." << endl;
    cout << endl;
    cout << " 'Everyone, empty your pockets!' he says." << endl;
    cout << endl;
    cout << " You do so. You've got medical tape, matches, a ratty shirt, a ziplock bag of" << endl;
    cout << " sugar, the oil pastels from Sparrow, and the stump remover from the cabin." << endl;
    cout << endl;
    cout << " 'Yes!' Roni says as if he knows something you don't, and he gets to work." << endl;
    cout << endl;
    cout << " Roni tapes the matches into a bundle and stuffs a strip of the ratty shirt" << endl;
    cout << " into the head to make a fuse. Putting that aside, he then takes his camp " << endl;
    cout << " stove and begins melting all the yellow and orange oil pastels down." << endl;
    cout << endl;
    cout << " 'Keep an eye on this!' he says to you, 'Once melted, I'm going to give you" << endl;
    cout << " a mixture of this sugar and the stump remover... also known as potasium" << endl;
    cout << " nitrate.'" << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " He smiles. And for the first time since the cabin, you smile too. The pastels" << endl;
    cout << " are melted now, and Roni starts pouring a white powder mixture into the" << endl;
    cout << " pan." << endl;
    cout << endl;
    cout << " Once cooled, you help pack the resulting crumbly, clay-like mixture into an empty" << endl;
    cout << " can (salvaged from Sparrow's dinner two days ago). While you can't see it," << endl;
    cout << " you swear can feel the 'whop whop whop' of the helicopter in your chest- " << endl;
    cout << " it's so close. You stuff the make-shift fuse into the can and light" << endl;
    cout << " the shirt..." << endl;
    cout << endl;
    
    enterToCont();
    clearScreen();
    
    cout << " A brilliant orange-red smoke begins pouring out of the old can." << endl;
    cout << " A smoke flare. Amazing that Roni could measure the ingedients out just right." << endl;
    cout << " It's good that you're in an open lot, because even though the smoke" << endl;
    cout << " dissipates a bit as it rises, it's able to break the treeline just fine." << endl;
    cout << endl;
    cout << " And you see it! The helicopter flies over head, and makes a clear circle" << endl;
    cout << " around your location. You're saved!" << endl;
    cout << endl;
    cout << " The End." << endl;
}

/*******************************************************************************
* Game::neutralEnding1()
*   Sets the neutral ending if riddle is solved
*******************************************************************************/
void Game::neutralEnding1()
{
    clearScreen();

    cout << " The four of you sprint to the trailhead parking lot Pina mentioned." << endl;
    cout << " Thank god for his maps!! You get there, and you can still hear the faint" << endl;
    cout << " whirring of helicopter blades. You guess it must be out here scouting for" << endl;
    cout << " wildfires from the storm." << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " Roni gets an idea." << endl;
    cout << endl;
    cout << " 'Everyone, empty your pockets!' he says." << endl;
    cout << endl;
    cout << " You do so, but you don't have much." << endl;
    cout << endl;
    cout << " 'Hmmm...' Roni says, 'We're so close, but there's not much I can do with this..." << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " You see it! The helicopter flies overhead... but it just flies over." << endl;
    cout << " Without signaling it somehow, you suppose that the four of you look just" << endl;
    cout << " like regular hikers. You look back at the forest and being to feel a certain" << endl;
    cout << " tightness in your chest." << endl;
    cout << endl;
    
    enterToCont();
    clearScreen();
    
    cout << " You have no choice but to move forward. The lot opens up into what must be" << endl;
    cout << " a logging road. Hopefully it leads to a highway or something." << endl;
    cout << " Though the sun is high in the sky, the shadows of the trees around you" << endl;
    cout << " seem to cast long, reaching shadows." << endl;
    cout << endl;
    cout << " The four of you begin walking..." << endl; 
    cout << endl;
    cout << " The End." << endl;
}

/*******************************************************************************
* Game::neutralEnding2()
*   Sets the neutral ending if the riddle is not solved, but has all items
*******************************************************************************/
void Game::neutralEnding2()
{
    clearScreen();

    cout << " The three of you sprint through the forest, not knowing which direction" << endl;
    cout << " to take. Your mind reflects briefly on Pina, but you push it away. You" << endl;
    cout << " don't want to think about that mess you encountered after leaving the cabin." << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " Roni gets an idea." << endl;
    cout << endl;
    cout << " 'Everyone, empty your pockets!' he says." << endl;
    cout << endl;
    cout << " You do so. You've got medical tape, matches, a ratty shirt, a ziplock bag of" << endl;
    cout << " sugar, the oil pastels from Sparrow, and the stump remover from the cabin." << endl;
    cout << endl;
    cout << " 'Yes!' Roni says as if he knows something you don't, and he gets to work." << endl;
    cout << endl;
    cout << " Roni tapes the matches into a bundle and stuffs a strip of the ratty shirt" << endl;
    cout << " into the head to make a fuse. Putting that aside, he then takes his camp " << endl;
    cout << " stove and begins melting all the yellow and orange oil pastels down." << endl;
    cout << endl;
    cout << " 'Keep an eye on this!' he says to you, 'Once melted, I'm going to give you" << endl;
    cout << " a mixture of this sugar and the stump remover... also known as potasium" << endl;
    cout << " nitrate.'" << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " He smiles. And for the first time since the cabin, you smile too. The pastels" << endl;
    cout << " are melted now, and Roni starts pouring a white powder mixture into the" << endl;
    cout << " pan." << endl;
    cout << endl;
    cout << " Once cooled, you help pack the resulting crumbly, clay-like mixture into an empty" << endl;
    cout << " can (salvaged from Sparrow's dinner two days ago). While you can't see it," << endl;
    cout << " you swear can feel the 'whop whop whop' of the helicopter in your chest- " << endl;
    cout << " it's so close. You stuff the make-shift fuse into the can and light" << endl;
    cout << " the shirt..." << endl;
    cout << endl;
    
    enterToCont();
    clearScreen();
    
    cout << " A brilliant orange-red smoke begins pouring out of the old can." << endl;
    cout << " A smoke flare. Amazing that Roni could measure the ingedients out just right." << endl;
    cout << " But while a bright orange hue at ground level, the smoke dissipates as" << endl;
    cout << " it rises. When the smoke hits the treeline, it's like the color scatters," << endl;
    cout << " and from a bird's-eye-view the smoke is barely noticeable." << endl;
    cout << endl;
    cout << " The helicopter passes overhead. You're stuck in the forest now." << endl;
    cout << " You'll just have to find another way to escape." << endl;
    cout << endl;
    cout << " Though the sun is high in the sky, the shadows of the trees around you" << endl;
    cout << " seem to cast long, reaching shadows." << endl;
    cout << endl;
    cout << " The three of you begin walking..." << endl; 
    cout << endl;
    cout << " The End." << endl;
}

/*******************************************************************************
* Game::badEnding()
*   Sets the bad ending if you run out of steps
*******************************************************************************/
void Game::badEnding1()
{
    clearScreen();

    cout << " You stop, gasping for breath. Falling to your knees, you would" << endl;
    cout << " give anything for a deep gulp of fresh air. Instead, the it" << endl;
    cout << " comes in thick, almost sticky. You don't notice the shadows" << endl;
    cout << " around you beginning to twist, but you do feel the deep cold" << endl;
    cout << " envelop you." << endl;
    cout << endl;
    cout << " Everything goes dark." << endl;
    cout << endl;
    cout << " The End." << endl;
}

/*******************************************************************************
* Game::badEnding()
*   Sets the bad ending if the player neither solves the riddle nor has all the
*   items
*******************************************************************************/
void Game::badEnding2()
{
    clearScreen();

    cout << " The three of you sprint through the forest, not knowing which direction" << endl;
    cout << " to take. Your mind reflects briefly on Pina, but you push it away. You" << endl;
    cout << " don't want to think about that mess you encountered after leaving the cabin." << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " Roni gets an idea." << endl;
    cout << endl;
    cout << " 'Everyone, empty your pockets!' he says." << endl;
    cout << endl;
    cout << " You do so, but you don't have much." << endl;
    cout << endl;
    cout << " 'Hmmm...' Roni says, 'We're so close, but there's not much I can do with this..." << endl;
    cout << endl;

    enterToCont();
    clearScreen();

    cout << " You see it! The helicopter flies overhead... but it just flies over." << endl;
    cout << " Without signaling it somehow, you suppose that the four of you look just" << endl;
    cout << " like regular hikers. You look back into the forest and being to feel a certain" << endl;
    cout << " tightness in your chest." << endl;
    cout << endl;
    
    enterToCont();
    clearScreen();
    
    cout << " Though the sun is high in the sky, the shadows of the trees around you" << endl;
    cout << " seem to cast long, reaching shadows." << endl;
    cout << endl;
    cout << " The three of you begin walking..." << endl; 
    cout << endl;
    cout << " The End." << endl;
}
