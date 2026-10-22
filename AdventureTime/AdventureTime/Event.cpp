#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

void Event::GenerateEvent(Player& p)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 10;
	
	switch (i)
	{
	case 7:
		std::cout << "Keep Travelling" << std::endl;
		break;
	case 5:
		std::cout << "Puzzle Encountered" << std::endl;
		break;
	default:
		std::cout << "Enemy Encountered" << std::endl;
		EnemyEncounter(p);
		break;
	}
}

void Event::EnemyEncounter(Player& p)
{
	std::system("cls");
	int choice = 0;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	bool playerTurn = false;
	bool playerDefending = false;
	bool escape = false;
	int firstTurn = rand() % 100 + 1;
	
	if (firstTurn >= 50 - p.GetLuck())
		playerTurn = true;
	else
		playerTurn = false;

	std::cout << "------ New Enemy Encountered ------" << std::endl;

	int level = p.GetLevel();
	int hp = level * 10;
	int damageMin = (rand() % level + 1);
	int damageMax = (rand() % level + 1) * 2;
	int currentDamage = rand() / (damageMax - damageMin + 1);
	int defense = rand() % level;
	int exp = level * 10;
	baseEnemy = new Enemy("Oscarsulman", level, hp, exp, currentDamage, defense);

	while (!playerDefeated || enemyDefeated || escape)
	{
		if (playerTurn)
		{
			std::cout << "Choose your actrion" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Player Sheet" << std::endl;
			std::cout << "4: Show Enemy Stats" << std::endl;
			std::cout << "0: Escape" << std::endl;

			std::cin >> choice;
			int escapeRand = 0;
			int attackRoll = 0;
			switch (choice)
			{
			case 0: //Escape
				escapeRand = (rand() % 100) + p.GetLuck();
				if (escapeRand > 35)
				{
					std::cout << "Escaped...." << std::endl;
					escape = true;
				}
				break;
			case 1: //Attack
				std::system("cls");
				attackRoll = rand() % 20 + 1;
				if (attackRoll > (50 - p.GetDexterity() - p.GetAgiltiy()))
				{
					std::cout << "Player Hit Enemy" << std::endl;
					baseEnemy->TakeDamage(p.DoDamage());
				}
				break;
			case 2: //Defend
				playerDefending = true;
				break;
			case 3: //Player Stats
				p.PrintPlayerStats();
				break;
			case 4: //Enemy Stats
				baseEnemy->PrintEnemyStats();
				break;
			default:
				std::cout << "Invalid Choice, Pick Again..." << std::endl;
				break;
			}
			playerTurn = false;
		}
		else
		{
			std::cout << "------ ENEMY TURN ------" << std::endl;
			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "Enemy Defeated" << std::endl;
				std::cout << "EXP: " << baseEnemy->GetEXP() << std::endl;
			} 
			else
			{
				int enemyAttackRoll = rand() % 100;
				if (playerDefending)
				{
					if (enemyAttackRoll > 70)
					{
						std::cout << "Enemy Hit Player" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy Missed Player" << std::endl;
					} 
				}
				else 
				{
					if (enemyAttackRoll > 40)
					{
						std::cout << "Enemy Hit Player" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy Missed Player" << std::endl;
					}
				}
			}
		}
		playerTurn = true;
	}
}

void Event::PuzzleEncounter(Player& p)
{
}
