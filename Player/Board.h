#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <map>

class Board 
{
private:
    std::map<int, int> snakes;
    std::map<int, int> ladders;

public:
    Board();

    int checkPosition(int pos);
};

#endif