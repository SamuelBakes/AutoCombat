#pragma once
#include <list>
#include "BaseChar.h"
/*******************************************************
* Class: World
* Author: Samuel Bakes 
* Description: The World contains all the functionality of 
* the application. On a whim I made all of the functionality 
* in the constructor.This would be considered bad form most
* of the time, but for some reason at the start of the project
* I thought it would be humourous to put everything I possibly could
* into the constructor.
*********************************************************/

class World
{
private:
	std::list<BaseChar> allys;
	std::list<BaseChar> enemies;
public:
	World();
	bool checkID(int id);
	bool checkPosition(int x, int y);
	BaseChar createChar();
};

