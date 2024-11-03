#include <iostream>
#include <vector>

enum GameMode {
    Multiplayer,
    EasyAI
};

class TicTacToe {
public: 
    TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = '-';
            }
        }
        currentPlayer = 'X';

        mode = Multiplayer;
    }

    void play() {
        bool gameOver = false;
        while (!gameOver) {
            printBoard();

            std::pair<int, int> place;

            if (mode == EasyAI && currentPlayer == 'O') {
                place = randomPlace();
            }
            else {
                place = playerTurn(currentPlayer);
            }


            board[place.first][place.second] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameOver = true;
            }
            else if (isBoardFull()) {
                printBoard();
                std::cout << "It's a tie!" << std::endl;
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    void setGameMode(GameMode gm) {
        mode = gm;
    }

private:
    char board[3][3];
    char currentPlayer;
    GameMode mode;

    void printBoard() {
        std::cout << std::endl;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << " " << board[i][j] << " " << (j != 2 ? "|" : "");
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
            if (board[i][0] == player &&
                board[i][1] == player &&
                board[i][2] == player) {
                return true;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (board[0][j] == player &&
                board[1][j] == player &&
                board[2][j] == player) {
                return true;
            }
        }

        if (board[0][0] == player &&
            board[1][1] == player &&
            board[2][2] == player) {
            return true;
        }

        if (board[0][2] == player &&
            board[1][1] == player &&
            board[2][0] == player) {
            return true;
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
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
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
                std::cout << "Invalid move. Try again." << std::endl;
            }
        } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-');
        return std::make_pair(row, col);
    }

    std::pair<int, int> randomPlace() {
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


int main(int argc, char* argv[]) {
    int gamemode;
    TicTacToe game;

    std::cout << "Welcome to TicTacToe! Please choose a gamemode:" << std::endl << "1. Multiplayer" << std::endl << "2. EasyAI" << std::endl;
    std::cin >> gamemode;

    switch (gamemode)
    {

    case 1:
        game.setGameMode(Multiplayer);
        break;

    case 2:
        game.setGameMode(EasyAI);
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