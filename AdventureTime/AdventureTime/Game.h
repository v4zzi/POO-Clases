#pragma once
#include <iostream>
#include "Character.h"
class Game
{
private:
	Character player;
	int choice;
	bool playing;

public:
	Game();
	virtual ~Game();
	void InitGame();
	void mainMenu();

	void SavePlayerData();
	void LoadPlayerData();
	void NewPlayer();
	void PrintPlayerStats();

	bool GetPlaying();
};

