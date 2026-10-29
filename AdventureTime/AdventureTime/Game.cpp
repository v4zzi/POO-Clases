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
	std::cout << "3: Travel" << std::endl;
	std::cout << "4: Level Up" << std::endl;
	std::cout << "5: Skill Up" << std::endl;
	std::cout << "6: Save" << std::endl;
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
	case 3:
		std::cout << "Travelling" << std::endl;
		Travel();
		break;
	case 4:
		LevelUp();
		break;
	case 5:
		SkillUp();
		break;
	case 6:
		SavePlayer();
		break;
	case 7:
		LoadPlayer();
		break;
	default:
		std::cout << "Invalid choice. Please try again." << std::endl;
		break;
	}
}

void Game::Travel()
{
	v.GenerateEvent(player);
}

void Game::SavePlayer()
{
	std::string fileName = "savePlayer.txt";
	std::ofstream outFile(fileName);
	if (outFile.is_open())
	{
		outFile << player.SaveStats() << " ";
	}
	else
	{
		std::cout << "Cant save Game" << std::endl;
	}
	outFile.close();
	std::cout << "Saved" << std::endl;
}

void Game::LoadPlayer()
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

void Game::LevelUp()
{
	player.LevelUp();
}

void Game::SkillUp()
{
	while (player.GetSkillPoints() > 0)
	{
		std::cout << "You have " << player.GetSkillPoints() << " Skill points yo use" << std::endl;
		std::cout << "----------Stats----------" << std::endl;
		std::cout << "1: Strength" << std::endl;
		std::cout << "2: Agility" << std::endl;
		std::cout << "3: Dexterity" << std::endl;
		std::cout << "4: Intelligence" << std::endl;
		std::cout << "5: Luck" << std::endl;
		std::cin >> choice;
		player.AddStats(choice, 1);
	}	
	if (player.GetSkillPoints() <= 0)
	{
		std::cout << "Not enough Skill points" << std::endl;
	}
	
}


