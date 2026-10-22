#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Event.h"

class Game
{
private:
	Player player;
	Enemy* enemy;
	Event v;
	int choice;
	bool playing;

public:
	Game();
	virtual ~Game();
	void InitGame();
	void mainMenu();

	void Travel();

	void SavePlayerData();
	void LoadPlayerData();
	void NewPlayer();
	void PrintPlayerStats();
	void NewEnemy();
	void PrintEnemyStats();

	bool GetPlaying();
};

