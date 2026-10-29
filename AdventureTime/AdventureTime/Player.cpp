#include "Player.h"
#include "Game.h"

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

void Player::LevelUp()
{
	while (GetEXP() >= MaxXp)
	{
		SetEXP(GetEXP() - MaxXp);
		SetLevel(GetLevel() + 1);
		MaxXp = GetLevel() * 10;
		skillPoints++;
	}
}


void Player::AddStats(int stat, int value)
{
}

void Player::UpdateValues()
{
	SetHP((this->intelligence * 2) / (this->dexterity - 2));
	SetDamageMin(this->strength - 2);
	SetDamageMax(this->strength * 2);
	SetDefense((this->agility * 2) / (this->luck - 3));
}

void Player::LoadStats(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "ERROR: Cant open file" << filename
			<< std::endl;
		return;
	}
	std::string name = "";
	int l;
	int hp;
	int xp;
	int maxXp;
	int dmin;
	int dmax;
	int d;
	//std::getline(inFile, name);
	inFile >> name
		>> l
		>> xp
		>> MaxXp
		>> skillPoints
		>> hp
		>> dmin
		>> dmax
		>> d
		>> strength
		>> agility
		>> luck
		>> dexterity;
	inFile.close();

	SetName(name);
	SetLevel(l);
	SetHP(hp);
	SetEXP(xp);
	SetDamageMin(dmin);
	SetDamageMax(dmax);
	SetDefense(d);

std::string Player::SaveStats()
{
	return this->GetName() + " " +
		std::to_string(this->GetLevel()) + " " +
		std::to_string(this->GetEXP()) + " " +
		std::to_string(this->GetHP()) + " " +
		std::to_string(this->GetDamageMin()) + " " +
		std::to_string(this->GetDamageMax()) + " " +
		std::to_string(this->GetDefense()) + " " +
		std::to_string(this->GetStrength()) + " " +
		std::to_string(this->GetAgility()) + " " +
		std::to_string(this->GetLuck()) + " " +
		std::to_string(this->GetDexterity()) + " " +
	return std::string();
}
