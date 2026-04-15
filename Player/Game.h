#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Board.h"

class Game 
{
private:
    std::vector<Player> players;
    Board board;

public:
    Game();
    void setup();
    void play();
    int rollDice();
};

#endif