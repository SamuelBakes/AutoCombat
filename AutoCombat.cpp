/******************************************
* Project Name: Autonomous Combat for Abnormaly Large Encounters (ACALE)
* Author: Samuel Bakes (like you Bakes the Cakes)
*
* Project Start Date: 4/8/2020 (4/7/2020 if you count conceptual designs and prep work)
* Most recent update: 4/8/2020
*
* Purpose: The purpose of this project is to provide a tool for Game masters
* that wish to maintain the combat system for exceptionally large encounters,
* but don't want to waste time rolling dice which could be spent roleplaying
* with the other players.  No longer will dungeon masters spend 15 minutes rolling dice
* behind the screen and moving the plethora of npc's in combat with each other!
*
*********************************************/

#include <iostream>
#include <string>
#include "BaseChar.h"
#include <time.h>
#include <list>
#include "World.h"
int main()
{
    // srand is neccesary to make the rand() function act psudo randomly.
    srand(time(NULL));
    // Almost everything functions in the constructor of the world.
    // Typically it would be considered bad form to force the constructor 
    // to do more than construct. But given this project is for fun
    // I felt like I could evoke poetic imagery or something by putting 
    // all the functionallity in the constructor.Once the world is "constructed",
    // the programm ends. And the labors of the constructor destructed just a moment
    // after completion.
    World j;
}