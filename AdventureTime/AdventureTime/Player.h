#pragma once
#include "Character.h"
#include <string>
#include <fstream>
class Player :
    public Character
{
private:
	int strength;
	int agility;
	int intelligence;
	int luck;
	int dexterity;

	int MaxXp;
	int skillPoints;
public:
    Player();
	void InitPlayer(std::string name);
	void PrintPlayerStats();
	void LevelUp();
	void AddStats(int stat, int value);
	void UpdateValues();
	void LoadStats(const std::string& filename);
	std::string SaveStats();
	~Player();

	//Gets
	int GetStrength() { return strength; }
	int GetAgility() { return agility; }
	int GetIntelligence() { return intelligence; }
	int GetLuck() { return luck; }
	int GetDexterity() { return dexterity; }
	int GetSkillPoints() { return skillPoints; }

	//Sets
	void SetStrength(int s) { strength = s; }
	void SetAgility(int a) { agility = a; }
	void SetIntelligence(int i) { intelligence = i; }
	void SetLuck(int l) { luck = l; }
	void SetDexterity(int d) { dexterity = d; }
};

