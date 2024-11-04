#include "TicTacToe.h"

int main(int argc, char* argv[]) {
	int gamemode;
	TicTacToe game;

	std::cout << "Welcome to TicTacToe! Please choose a gamemode:" << std::endl << "1. Multiplayer" << std::endl << "2. EasyAI" << std::endl;
	std::cin >> gamemode;

	switch (gamemode)
	{

	case 1:
		game.setGameMode(GameMode::Multiplayer);
		break;

	case 2:
		game.setGameMode(GameMode::EasyAI);
		break;

	default:
		std::cout << "Unknown gamemode, Choosing Multiplayer" << std::endl;
		break;
	}

	game.play();

	return 0;
}