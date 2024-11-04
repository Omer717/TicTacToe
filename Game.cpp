#include "TicTacToe.h"
#include "HumanTurn.cpp"
#include "RandomTurn.cpp"

int main(int argc, char* argv[]) {
	int gamemode;

	HumanTurn humanTurn;
	RandomTurn randTurn;

	Player p1('X', &humanTurn);
	Player p2('O', &humanTurn);

	TicTacToe game(p1, p2);

	std::cout << "Welcome to TicTacToe! Please choose a gamemode:" << std::endl << "1. Multiplayer" << std::endl << "2. EasyAI" << std::endl;
	std::cin >> gamemode;

	switch (gamemode)
	{

	case 1:
		break;

	case 2:
		game.setPlayer(Player('O', &randTurn));
		break;

	default:
		std::cout << "Unknown gamemode, Choosing Multiplayer" << std::endl;
		break;
	}

	game.play();

	return 0;
}