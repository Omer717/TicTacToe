#pragma once
#include <iostream>

class Turn
{
public:
	virtual std::pair<int, int> doTurn(char symbol, char board[3][3]) = 0;
};

//Strategy Pattern