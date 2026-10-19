#include "Game.h"

Game::Game()
{
	this->playing = true;
}

Game::~Game()
{
}

void Game::InitGame()
{
	std::cout << "Starting the Game..." << std::endl;
	NewPlayer();
}

void Game::mainMenu()
{
	std::cout << "------MAIN MENU------" << std::endl;
	std::cout << "0: Exit Game" << std::endl;
	std::cout << "1: Player Stats" << std::endl;
	std::cout << "2: Fight" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		this->playing = false;
		break;
	case 1:
		std::cout << "Displaying player stats..." << std::endl;
		PrintPlayerStats();
		break;
	case 2:
		std::cout << "Displaying enemy stats..." << std::endl;
		NewEnemy();
		break;
	default:
		std::cout << "Invalid choice. Please try again." << std::endl;
		break;
	}
}

void Game::SavePlayerData()
{
}

void Game::LoadPlayerData()
{
}

void Game::NewPlayer()
{
	player.InitPlayer("Sebarchangel");
}

void Game::PrintPlayerStats()
{
	player.PrintPlayerStats();
}

void Game::NewEnemy()
{
	std::string name = "slime";
	srand(time(0));
	int l = rand() % 4 + 1;
	int hp = (rand() % 9 * l + 1);
	int exp = (rand() % 49 * l + 1);
	int damage = (rand() % 9 * l + 1);
	int defense = (rand() % 14 * l + 1);
	enemy = new Enemy(name, l, hp, exp, damage, defense);
	enemy->PrintEnemyStats();
}

bool Game::GetPlaying()
{
	return this->playing;
}


