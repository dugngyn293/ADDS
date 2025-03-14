#include "Player.h"

Player::Player() {}

std::string Player::getName() { return player_name; }

Player::Player(std::string player_name) { this->player_name = player_name; }