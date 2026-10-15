#pragma once
#include <iostream>
class Character
{
private:
	std::string name;
	int level;
	int hp;
	int exp;
	int damageMin;
	int damageMax;
	int defense;

protected:

public:
	Character();
	virtual ~Character();
	void InitCharacter(std::string N);
	void PrintStats();
};

