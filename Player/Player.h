#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player 
{
private:
    std::string name;
    int position;

public:
    Player(std::string name);

    std::string getName() const;
    int getPosition() const;

    void setPosition(int pos);
    void move(int steps);
};

#endif