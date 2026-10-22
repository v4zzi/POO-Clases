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
	void TakeDamage(int d);
	const int DoDamage();
	bool IsAlive();

	//Gets
	std::string GetName() { return name; }
	int GetLevel() { return level; }
	int GetHP() { return hp; }
	int GetEXP() { return exp; }
	int GetDamageMin() { return damageMin; }
	int GetDamageMax() { return damageMax; }
	int GetDefense() { return defense; }

	//Sets
	void SetLevel(int L) { level = L; }
	void SetHP(int H) { hp = H; }
	void SetEXP(int E) { exp = E; }
	void SetDamageMin(int DM) { damageMin = DM; }
	void SetDamageMax(int DM) { damageMax = DM; }
	void SetDefense(int D) { defense = D; }
};

