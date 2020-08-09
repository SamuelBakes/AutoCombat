#include "World.h"
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
World::World() {
	// ans is a char because it can be converted to a number
	// for the switch statement.
	char ans; // The users response will be stored here.
	do {
		std::cout << "Please select an option\n"
			<< "A - Begin adding characters to the Ally's team.\n"
			<< "B - Begin adding characters to the Enemies team.\n"
			<< "C - Initiate Combat.\n"
			<< "D - quit\n";
		std::cin >> ans;
		switch (ans)
		{
		case 'A':
			allys.push_front(createChar());
			break;
		case 'B':
			enemies.push_front(createChar());
			break;
		case 'C':
			// The enemies strike first.
			for (std::list<BaseChar>::iterator it = enemies.begin(); it != enemies.end(); it++)
			{
				it->findTarget(&allys);
			}
			//Then the allys strike back.
			for (std::list<BaseChar>::iterator it = allys.begin(); it != allys.end(); it++)
			{
				it->findTarget(&enemies);
			}
			break;
		case 'D':
			std::cout << "Thank you\n";
			return;
			break;
		}
	} 
	while (ans != (char)"D");
	return; // Case "D" should return, but if it doesn't we make sure
	// To return here.
}
// This function gathers all relevent information for a new character
// on either side and does some basic validation. No characters will
// share ID numbers or be on the same x and y coordinate.
BaseChar World::createChar() {
	std::string name;
	std::string type;
	int size;
	int ac;
	int hp;
	int Str;
	int Dex;
	int Con;
	int Int;
	int Wis;
	int Cha;
	int id;
	int x;
	int y;
	int movement;
	std::cout << "Name: \n";
	std::cin >> name;
	std::cout << "Type: \n";
	std::cin >> type;
	std::cout << "Movement: \n";
	std::cin >> movement;
	std::cout << "Size(number): \n";
	std::cin >> size;
	std::cout << "ID: \n";
	std::cin >> id;
	while (!checkID(id)) {
		std::cout << "The ID you selected has been chosen, please select a different ID.\n";
		std::cin >> id;
	}
	std::cout << "Str: \n";
	std::cin >> Str;
	std::cout << "Dex: \n";
	std::cin >> Dex;
	std::cout << "Con: \n";
	std::cin >> Con;
	std::cout << "Int: \n";
	std::cin >> Int;
	std::cout << "Wis: \n";
	std::cin >> Wis;
	std::cout << "Cha: \n";
	std::cin >> Cha;
	std::cout << "AC: \n";
	std::cin >> ac;
	std::cout << "HP: \n";
	std::cin >> hp;
	std::cout << "X-coordinate: \n";
	std::cin >> x;
	std::cout << "Y-coordinate: \n";
	std::cin >> y;
	while (!checkPosition(x, y)) {
		std::cout << "The position: " << x << ", " << y
			<< " is taken please choose again.\n"
			<< "X-coordinate: ";
		std::cin >> x;
		std::cout << "Y-coordinate: ";
		std::cin >> y;
	}
	return BaseChar(Str, Dex, Con, Int, Wis, Cha, name, type, size, ac, hp, x, y, id, movement);
}
// This is a validation function used by createChar();
bool World::checkID(int id) {
	for (std::list<BaseChar>::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		if (id == it->getID()){
			std::cout << "getID: " << it->getID() << std::endl;
			return false;
	}
}
	for (std::list<BaseChar>::iterator it = allys.begin(); it != allys.end(); it++)
	{
		if (id == it->getID()) {
			std::cout << "getID: " << it->getID() << std::endl;
			return false;
		}
	}
	return true;
}
// This is a validation function used by createChar();
bool World::checkPosition(int x, int y) {
		for (std::list<BaseChar>::iterator it = enemies.begin(); it != enemies.end(); it++)
		{
			if (x == it->getX()&&y==it->getY()) {
				return false;
			}
		}
		for (std::list<BaseChar>::iterator it = allys.begin(); it != allys.end(); it++)
		{
			if (x == it->getX()&&y==it->getY()) {
				return false;
			}
		}
		return true;
}