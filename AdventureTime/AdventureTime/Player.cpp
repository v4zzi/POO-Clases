#include "Player.h"

Player::Player() :Character()
{
	this->strength = 5;
	this->agility = 5;
	this->intelligence = 5;
	this->luck = 5;
	this->dexterity = 5;
}

void Player::InitPlayer(std::string name)
{
	InitCharacter(name);
	SetLevel(1);
	SetEXP(0);
	SetHP((this->intelligence * 2) / (dexterity - 2));
	SetDamageMax(this->strength - 2);
	SetDamageMin(this-> strength * 2);
	SetDefense((this->agility * 2) / (this->luck - 3));
}

Player::~Player()
{
}

void Player::PrintPlayerStats()
{
	PrintStats();
	std::cout << "-------------------------" << std::endl;
	std::cout << "Strength: " << this->strength << std::endl;
	std::cout << "Agilty: " << this->agility << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "Luck: " << this->luck << std::endl;
	std::cout << "Dexterity: " << this->dexterity << std::endl;
	std::cout << "-------------------------" << std::endl;

}