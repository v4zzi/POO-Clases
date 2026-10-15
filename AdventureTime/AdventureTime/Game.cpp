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
}

void Game::mainMenu()
{
	std::cout << "------MAIN MENU------" << std::endl;
	std::cout << "0: Exit Game" << std::endl;
	std::cout << "1: Player Stats" << std::endl;
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
	player.InitCharacter("Sebarchangel");
}

void Game::PrintPlayerStats()
{
	player.PrintStats();
}

bool Game::GetPlaying()
{
	return this->playing;
}
