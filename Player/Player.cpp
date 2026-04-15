#include "Player.h"

Player::Player(std::string name) 
{
    this->name = name;
    this->position = 0;
}

std::string Player::getName() const 
{
    return name;
}

int Player::getPosition() const 
{
    return position;
}

void Player::setPosition(int pos) 
{
    position = pos;
}

void Player::move(int steps) 
{
    position += steps;
}