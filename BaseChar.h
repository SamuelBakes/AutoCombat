#pragma once
#include <string>
#include <iostream>
#include <list>
/************************************************************
* Class: BaseChar (Base Character)
* Author: Samuel Bakes
* Description: This is the base "charachter". Both friends and foes
* are just base characters. This class will someday be an
* inherited class from which other classes derive. 
************************************************************/
class BaseChar
{
private:
	// Stats will be Str, Dex, Con, Int, Wis, Cha
	int stats[6];
	// Size will play a larger part as the project unfolds.
	int size;
	// Type will play a larger part as the project unfolds.
	// It is akin to the race of the creature.
	std::string type;
	// Armor Class: How high does the other character need to role to hit?
	int ac;
	// Hit Points: How many knocks can the character take before they
	// are knocked out?
	int hp;
	// Name: name of the characters
	std::string name;
	// Target: a pointer to the nearest target. The pointer is initialised to NULL.
	BaseChar *target;
	// x and y are for location on a grid board.
	int x;
	int y;
	// ID is for identification purposes. In the future it may be prudent to make
	// this a random number that is different from all other ID's.
	int id;
	//Movement dictates how fast a character can move.
	int movement;

public:
	//Constructor - seldom if ever used.
	BaseChar();
	// This constructor is used by createChar in the World class.
	BaseChar(int Str, int Dex, int Con, int Int, int Wis, int Cha, std::string name, std::string type,
		int size, int ac, int hp, int x, int y, int id, int movement);
	// Getters and Setters
	int  getStr();
	int  getDex();
	int  getCon();
	int  getInt();
	int  getWis();
	int  getCha();
	int  getAc();
	int  getHp();
	int getID();
	std::string getName();
	std::string getType();
	int getX();
	int getY();
	void setStr(int Str);
	void setDex(int Dex);
	void setCon(int Con);
	void setInt(int Int);
	void setWis(int Wis);
	void setCha(int Cha);
	void setName(std::string name);
	void setType(std::string type);
	void setAc(int ac);
	void setHp(int hp);
	void setID(int id);

	// Complex Functions
	void approachCombatent(std::list<BaseChar>::iterator it);
	int findDistance(BaseChar * target);
	void findTarget(std::list<BaseChar> *enemies);
	void attack(std::list<BaseChar>::iterator it);
};

