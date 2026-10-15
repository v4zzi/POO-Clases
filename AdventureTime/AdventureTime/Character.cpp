#include "Character.h"

Character::Character()
{
	this->name = "";
	this->level = 1;
	this->hp = 100;
	this->exp = 0;
	this->damageMin = 5;
	this->damageMax = 10;
	this->defense = 2;
}

Character::~Character()
{
}

void Character::InitCharacter(std::string N)
{
	this->name = N;
}

void Character::PrintStats()
{
	std::system("cls");
	std::cout << "------" << this->name << "------" << std::endl;
	std::cout << "Level: " << this->level << std::endl;
	std::cout << "HP: " << this->hp << std::endl;
	std::cout << "EXP: " << this->exp << std::endl;
	std::cout << "Damage: " << this->damageMin << " - " << this->damageMax << std::endl;
	std::cout << "Defense: " << this->defense << std::endl;
	std::cout << "--------------------" << std::endl;
}
