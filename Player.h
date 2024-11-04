#pragma once
#include "TurnAction.h"

class Player
{
public:
	Player(char symbol, Turn* actionOnTurn);
	std::pair<int, int> doTurn(char board[][3]);
	char getSymbol();
private:
	char symbol_;
	Turn* action_;
};