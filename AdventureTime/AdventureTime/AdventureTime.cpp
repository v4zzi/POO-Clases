#include "Game.h"
#include "Character.h"

int main()
{
	Game game;
	game.InitGame();
	while (game.GetPlaying())
	{
		game.mainMenu();
	}
	return 0;

	Character player;
	player.PrintStats();
	
}