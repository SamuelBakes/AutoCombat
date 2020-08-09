#include "BaseChar.h"
/************************************************************
* Class: BaseChar (Base Character)
* Author: Samuel Bakes
* Description: This is the base "charachter". Both friends and foes
* are just base characters. This class will someday be an
* inherited class from which other classes derive.
************************************************************/
BaseChar::BaseChar() {
	stats[0] = 3;
	stats[1] = 4; 
	stats[2] = 4;
	stats[3] = 4;
	stats[4] = 4;
	stats[5] = 5;
	name = "No name";
	type = "Type not declared";
	size = 1;
	ac = 15;
	hp = 15;
	x = 1;
	y = 1;
	id = 0;
	// Unless you're supposed to be pointing to something else
	// Your pointers should point to NULL.
	target = NULL;
	movement = 5;
}
BaseChar::BaseChar(int Str, int Dex, int Con, int Int, int Wis, int Cha,std::string name,std::string type,
					int size, int ac, int hp, int x, int y, int id, int movement) {
	this->stats[0] = Str;
	this->stats[1] = Dex;
	this->stats[2] = Con;
	this->stats[3] = Int;
	this->stats[4] = Wis;
	this->stats[5] = Cha;
	this->name = name;
	this->type = type;
	this->size = size;
	this->ac = ac;
	this->hp = hp;
	this->x = x;
	this->y = y;
	this->id = id;
	this->target = NULL;
	this->movement = movement;
}
// Getters and Setters can run amuck so it's best to keep them *inline*...
int BaseChar::getStr() { return stats[0]; }
int BaseChar::getDex() { return stats[1]; }
int BaseChar::getCon() { return stats[2]; }
int BaseChar::getInt() { return stats[3]; }
int BaseChar::getWis() { return stats[4]; }
int BaseChar::getCha() { return stats[5]; }
int BaseChar::getAc() { return ac; }
int BaseChar::getHp() { return hp; }
int BaseChar::getID() { return id; }
std::string BaseChar::getName() { return name; }
std::string BaseChar::getType() { return type; }
int BaseChar::getX() { return x; }
int BaseChar::getY() { return y; }
void BaseChar::setStr(int Str) { this->stats[0] = Str; }
void BaseChar::setDex(int Dex) { this->stats[1] = Dex; }
void BaseChar::setCon(int Con) { this->stats[2] = Con; }
void BaseChar::setInt(int Int) { this->stats[3] = Int; }
void BaseChar::setWis(int Wis) { this->stats[4] = Wis; }
void BaseChar::setCha(int Cha) { this->stats[5] = Cha; }
void BaseChar::setName(std::string name) { this->name = name; }
void BaseChar::setType(std::string type) { this->type = type; }
void BaseChar::setAc(int ac) { this->ac = ac; }
void BaseChar::setHp(int hp) { this->hp = hp; }
void BaseChar::setID(int id) { this->id = id; }

// Complex Functions

// This is a simple attack that all base characters will have.
// As the project is developed, it will be crucial to edit 
// attack and damage dice for each character.  
void BaseChar::attack(std::list<BaseChar>::iterator it) {
	// Roll to attack
	int attackRoll = rand() % 20 + 1;
	std::cout << "The attack roll is: " << attackRoll << std::endl;
	// add modifier
	int attack = attackRoll + this->stats[0];
	// compare attack to ac
	if (attack >= it->getAc())
	{
		// roll damage
		int damage = rand() % 6 + 1;
		if (damage == 6)
		{
			std::cout << "That's a Lot of Damage!\n"; // *Display GIF of Phil Swift*
		}
		it->setHp(it->getHp() - damage); 
		std::cout << "The damage is:" << damage << std::endl;
		std::cout << "The victim's hp is:" << it->getHp() << std::endl;
		// In war they allways tell you the other guy's the bad guy.
		// Usually the truth is that both sides are victims.
	}
}
void BaseChar::findTarget(std::list<BaseChar>* enemies) {
	int fDist = 5000;  // LOOK HERE: This may be a problem later on
	// For now I set fDist to a "relativly high number"
	//but longer distances may break the application.
	int fID = 0;
	//Iterate through once to find a target.
	for (std::list<BaseChar>::iterator it = enemies->begin(); it != enemies->end(); it++) {
		if (it->findDistance(this) < fDist)
		{
			fDist = it->findDistance(this);
			fID = it->id;
		}
	}
	// When the target is found, approach and if possible, attack.
	for (std::list<BaseChar>::iterator it = enemies->begin(); it != enemies->end(); it++) {
		if (fID == it->id)
		{
			approachCombatent(it);
			if (it->findDistance(this) <= 2)
			attack(it);
		}
	}
}
/****************************************************
* Find's the relative distance between two combatents. 
* I use an alteration of pythagerean theorem to find distance
* Because I don't need actual distance I don't need to sqrt.
*******************************************************/
int BaseChar::findDistance(BaseChar* target) {
	int xDistance = x - target->x;
	int yDistance = y - target->y;
	int xDSquared = xDistance * xDistance;
	int yDSquared = yDistance * yDistance;
	return xDSquared + yDSquared;
}
// On the charachters turn, they will try to move into striking distance
// I haven't thourghly tested this code, but I tried to ensure
// that charachters would not stand on top of each other.
void BaseChar::approachCombatent(std::list<BaseChar>::iterator it) {
	int tempMove = movement;
	while (tempMove > 0)
	{
		if (x > it->getX() && tempMove > 0) {
			x = x--;
			tempMove = tempMove--;
			std::cout << name << " has moved left\n";
			std::cout << name << " is at " << x << ", " << y << std::endl;
		}
		if (x < it->getX() && tempMove > 0) {
			x = x++;
			tempMove = tempMove--;
			std::cout << name << " has moved right\n";
			std::cout << name << " is at " << x << ", " << y << std::endl;
		}
		if (y > it->getY() && tempMove > 0) {
			y = y--;
			tempMove = tempMove--;
			std::cout << name << " has moved down\n";
			std::cout << name << " is at " << x << ", " << y << std::endl;
		}
		if (y < it->getY() && tempMove > 0) {
			y = y++;
			tempMove = tempMove--;
			std::cout << name << " has moved up\n";
			std::cout << name << " is at " << x << ", " << y << std::endl;
		}
		if (it->findDistance(this) <= 2)
		{
			return;
		}
	}
	return;
}