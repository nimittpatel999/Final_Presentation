#include "Board.h"

Board::Board() 
{
    // Snakes
    snakes[99] = 54;
    snakes[70] = 55;
    snakes[52] = 42;
    snakes[25] = 2;

    // Ladders
    ladders[6] = 25;
    ladders[11] = 40;
    ladders[60] = 85;
    ladders[46] = 90;
}

int Board::checkPosition(int pos) 
{
    if (snakes.count(pos)) 
    {
        return snakes[pos];
    }
    if (ladders.count(pos)) 
    {
        return ladders[pos];
    }
    return pos;
}