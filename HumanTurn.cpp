#include "TurnAction.h"

class HumanTurn : public Turn
{
public:
	std::pair<int, int> doTurn(char symbol, char board[3][3]) override {
		int row, col;
		do {
			std::cout << "Player " << symbol << ", enter your move (row, col): ";
			std::cin >> row >> col;
			if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
				std::cout << "Invalid move. Try again." << std::endl;
			}
		} while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-');
		return std::make_pair(row, col);
	}
};
