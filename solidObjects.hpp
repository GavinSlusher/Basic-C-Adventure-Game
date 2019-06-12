/******************************************************************************* 
 * ** Author:       Gavin Slusher
 * ** Date:         6/2/2019
 * ** Description:  File to store all "solid objects" as defined by a boolean
 *                  set by the MabObjects class. This is the specification file.  
 * ** *************************************************************************/
#include "displayMenu.hpp"
#include "inputValidation.hpp"
#include "MapObjects.hpp"
#include "Items.hpp"
#include "Space.hpp"
#include "Forest.hpp"

#ifndef SOLIDOBJECTS_HPP
#define SOLIDOBJECTS_HPP 

const char ITEM = 'o';
const char RTENT  = '\\';
const char LTENT  = '/';
const char EXIT  = 'X';
const char NPC_EXIT  = 'S';
const char NPC_ADD_ITEM  = 'S';
const char RIDDLE_NPC  = 'P';
const char END_NPC  = 'R';
const char ROCK  = '*';
const char TREE  = 'T';

class rTent: public MapObjects 
{
    protected:
        
    public:
        rTent();

};

class lTent: public MapObjects 
{
    protected:
        
    public:
        lTent();

};

class Rock: public MapObjects 
{
    protected:
        
    public:
        Rock();

};

class Tree: public MapObjects 
{
    protected:
        
    public:
        Tree();

};

class rExit: public MapObjects 
{
    protected:
        Space *thisSpace;
        int exitRow;
        int exitCol;
        
    public:
        rExit(Space *, int, int);
        virtual void interact();

};

class npcExit: public MapObjects 
{
    protected:
        Space *thisSpace;
        int exitRow;
        int exitCol;
        
    public:
        npcExit(Space *, int, int);
        virtual void interact();

};

class sAddItem: public MapObjects 
{
    protected:
        Space *thisSpace;
        
    public:
        sAddItem(Space *);
        virtual void interact();

};

class endNPC: public MapObjects 
{
    protected:
        Space *thisSpace;
        
    public:
        endNPC(Space *);
        virtual void interact();

};

class riddleNPC: public MapObjects 
{
    protected:
        Forest *thisSpace;
        
    public:
        riddleNPC(Forest *);
        virtual void interact();

};

class lExit: public MapObjects 
{
    protected:
        Space *thisSpace;
        int exitRow;
        int exitCol;
        
    public:
        lExit(Space *, int, int);
        virtual void interact();

};

class tExit: public MapObjects 
{
    protected:
        Space *thisSpace;
        int exitRow;
        int exitCol;
        
    public:
        tExit(Space *, int, int);
        virtual void interact();

};

class dExit: public MapObjects 
{
    protected:
        Space *thisSpace;
        int exitRow;
        int exitCol;
        
    public:
        dExit(Space *, int, int);
        virtual void interact();

};
#endif

