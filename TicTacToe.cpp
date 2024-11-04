#include <iostream>
#include <vector>
#include "GameMode.h"
#include "TicTacToe.h"


TicTacToe::TicTacToe(Player p1, Player p2): p1_(p1), p2_(p2) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board_[i][j] = '-';
		}
	}
	currentPlayer_ = &p1_;

	mode_ = GameMode::Multiplayer;
}

void TicTacToe::play() {
	bool gameOver = false;
	while (!gameOver) {
		printBoard();

		std::pair<int, int> place = currentPlayer_->doTurn(board_);

		board_[place.first][place.second] = currentPlayer_->getSymbol();

		if (checkWin(currentPlayer_->getSymbol())) {
			printBoard();
			std::cout << "Player " << currentPlayer_->getSymbol() << " wins!" << std::endl;
			gameOver = true;
		}
		else if (isBoardFull()) {
			printBoard();
			std::cout << "It's a tie!" << std::endl;
			gameOver = true;
		}

		currentPlayer_ = (currentPlayer_ == &p1_) ? &p2_ : &p1_;
	}
}

void TicTacToe::setGameMode(GameMode gm) {
	mode_ = gm;
}

void TicTacToe::printBoard() {
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

bool TicTacToe::checkWin(char player) {
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

bool TicTacToe::isBoardFull() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board_[i][j] == '-') {
				return false;
			}
		}
	}

	return true;
}

void TicTacToe::setPlayer(Player playerToReplace) {
	p2_ = playerToReplace;
}

void TicTacToe::setPlayer(int playerNumber, Player playerToReplace) {
	switch (playerNumber) {

	case 1:
		p1_ = playerToReplace;
		break;

	default:
		p2_ = playerToReplace;
		break;
	}
}

// What did I learn?
// Ternary operator in C++
// STACK vs HEAP memory, When to use which
// OOP In C++ (Classes, Private, Public)
// Headerfiles vs CPP files Scope