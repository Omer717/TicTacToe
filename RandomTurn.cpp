#include "TurnAction.h"

#include <vector>

class RandomTurn : public Turn
{
public:
	std::pair<int, int> doTurn(char symbol, char board[3][3]) override {
		std::vector<std::pair<int, int>> possibleOptions;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == '-') {
					possibleOptions.push_back(std::make_pair(i, j));
				}
			}
		}
		return possibleOptions[rand() % possibleOptions.size()];
	}
};
