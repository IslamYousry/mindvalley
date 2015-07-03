#include "Player.h"

Player::Player() {
	name = "newPlayer";
	currentScore = 0;

}
Player::Player(string n) {
	name = n;
	currentScore = 0;

}
void Player::setPlayerName(string n) {
	name = n;
}
string Player::getPlayerName() {
	return name;
}

void Player::setPlayerScore(int s) {
	currentScore = s;
}
int Player::getPlayerScore() {
	return currentScore;
}
