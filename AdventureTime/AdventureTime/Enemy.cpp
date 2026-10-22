#include "Enemy.h"

Enemy::Enemy(std::string name, int l, int hp, int exp, int damage, int defense) : Character ()
{
	InitCharacter(name);
	SetLevel(l);
	SetHP(hp);
	SetEXP(exp);
	SetDamageMax(damage * 2);
	SetDamageMin(damage / 2);
	SetDefense(defense);
}

Enemy::Enemy()
{
}

void Enemy::InitEnemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::PrintEnemyStats()
{
	PrintStats();
}
