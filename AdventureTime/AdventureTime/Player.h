#pragma once
#include "Character.h"
class Player :
    public Character
{
private:
	int strength;
	int agility;
	int intelligence;
	int luck;
	int dexterity;
public:
    Player();
	void InitPlayer(std::string name);
	void PrintPlayerStats();
	~Player();

	//Gets
	int GetStrength() { return strength; }
	int GetAgiltiy() { return agility; }
	int GetIntelligence() { return intelligence; }
	int GetLuck() { return luck; }
	int GetDexterity() { return dexterity; }
	//Sets
	void SetStrength(int s) { strength = s; }
	void SetAgility(int a) { agility = a; }
	void SetIntelligence(int i) { intelligence = i; }
	void SetLuck(int l) { luck = l; }
	void SetDexterity(int d) { dexterity = d; }
};

