#include "TurnAction.h"
#include "Player.h"


Player::Player(char symbol, Turn* actionOnTurn) : symbol_(symbol), action_(actionOnTurn) {}

std::pair<int, int> Player::doTurn(char board[][3]) {
	return action_->doTurn(symbol_, board);
}

char Player::getSymbol() {
	return symbol_;
}