#pragma once
#include "GameMode.h"
#include "Player.h"
#include <iostream>

class TicTacToe {
private:
    char board_[3][3];
    Player p1_, p2_;
    Player* currentPlayer_;
    GameMode mode_;

    void printBoard();
    bool checkWin(char player);
    bool isBoardFull();

public:
    TicTacToe(Player p1, Player p2);
    void play();
    void setGameMode(GameMode gm);
    void setPlayer(Player playerToReplace);
    void setPlayer(int playerNumber, Player playerToReplace);
};
