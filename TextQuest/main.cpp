#include"Game.h"



int main()
{
	SetConsoleTitle("TextQuest");

	Game* game = new Game;
	game->run();

	delete game;
	return 0;
}