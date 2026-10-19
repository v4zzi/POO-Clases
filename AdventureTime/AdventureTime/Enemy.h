#pragma once
#include "Character.h"
class Enemy :
    public Character
{
private:
public:
    Enemy(std::string name, 
        int l, int hp, int exp, int damage,
        int defense);
    ~Enemy();
    void InitEnemy();
    void PrintEnemyStats();
};

