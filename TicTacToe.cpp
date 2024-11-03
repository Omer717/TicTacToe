#include <iostream>
#include <vector>
#include "GameMode.h"

class TicTacToe {
public: 
    TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board_[i][j] = '-';
            }
        }
        currentPlayer_ = 'X';

        mode_ = GameMode::Multiplayer;
    }

    void play() {
        bool gameOver = false;
        while (!gameOver) {
            printBoard();

            std::pair<int, int> place;

            if (mode_ == GameMode::EasyAI && currentPlayer_ == 'O') {
                place = randomPlace();
            }
            else {
                place = playerTurn(currentPlayer_);
            }


            board_[place.first][place.second] = currentPlayer_;

            if (checkWin(currentPlayer_)) {
                printBoard();
                std::cout << "Player " << currentPlayer_ << " wins!" << std::endl;
                gameOver = true;
            }
            else if (isBoardFull()) {
                printBoard();
                std::cout << "It's a tie!" << std::endl;
                gameOver = true;
            }

            currentPlayer_ = (currentPlayer_ == 'X') ? 'O' : 'X';
        }
    }

    void setGameMode(GameMode gm) {
        mode_ = gm;
    }

private:
    char board_[3][3];
    char currentPlayer_;
    GameMode mode_;

    void printBoard() {
        std::cout << std::endl;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << " " << board_[i][j] << " " << (j != 2 ? "|" : "");
            }
            std::cout << std::endl;
            if (i != 2) {
                std::cout << "-----------" << std::endl;
            }
        }

        std::cout << std::endl;
    }

    bool checkWin(char player) {
        for (int i = 0; i < 3; i++) {
            if (board_[i][0] == player &&
                board_[i][1] == player &&
                board_[i][2] == player) {
                return true;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (board_[0][j] == player &&
                board_[1][j] == player &&
                board_[2][j] == player) {
                return true;
            }
        }

        if (board_[0][0] == player &&
            board_[1][1] == player &&
            board_[2][2] == player) {
            return true;
        }

        if (board_[0][2] == player &&
            board_[1][1] == player &&
            board_[2][0] == player) {
            return true;
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board_[i][j] == '-') {
                    return false;
                }
            }
        }

        return true;
    }

    std::pair<int, int> playerTurn(char player) {
        int row, col;
        do {
            std::cout << "Player " << player << ", enter your move (row, col): ";
            std::cin >> row >> col;
            if (row < 0 || row > 2 || col < 0 || col > 2 || board_[row][col] != '-') {
                std::cout << "Invalid move. Try again." << std::endl;
            }
        } while (row < 0 || row > 2 || col < 0 || col > 2 || board_[row][col] != '-');
        return std::make_pair(row, col);
    }

    std::pair<int, int> randomPlace() {
        std::vector<std::pair<int, int>> possibleOptions;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board_[i][j] == '-') {
                    possibleOptions.push_back(std::make_pair(i, j));
                }
            }
        }
        return possibleOptions[rand() % possibleOptions.size()];
    }
};


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

// What did I learn?
// Ternary operator in C++
// STACK vs HEAP memory, When to use which
// OOP In C++ (Classes, Private, Public)
// Headerfiles vs CPP files Scope