#pragma once
#include "GameMode.h"
#include <iostream>

class TicTacToe {
private:
    char board_[3][3];
    char currentPlayer_;
    GameMode mode_;

    void printBoard();
    bool checkWin(char player);
    bool isBoardFull();
    std::pair<int, int> playerTurn(char player);
    std::pair<int, int> randomPlace();

public:
    TicTacToe();
    void play();
    void setGameMode(GameMode gm);
};
