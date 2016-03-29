#include "KnightState.h"

#include <iostream>

#include "../boards/BoardBase.h"



std::bitset<CELLS> KnightState::getCellsToAttack(int row, int col, const BoardBase &board) const
{
    return getCellsToMove(row, col, board);
}

std::bitset<CELLS> KnightState::getCellsToMove(int row, int col, const BoardBase &) const
{
    std::bitset<CELLS> moves;


    //TODO: change it. this is incorrect. For position (0, 0) it will produce incorrect result
    setBit(INDEX(row - 2, col - 1), moves);
    setBit(INDEX(row + 2, col - 1), moves);

    setBit(INDEX(row - 1, col - 2), moves);
    setBit(INDEX(row + 1, col - 2), moves);

    setBit(INDEX(row + 2, col - 1), moves);
    setBit(INDEX(row + 2, col + 1), moves);

    setBit(INDEX(row - 1, col + 2), moves);
    setBit(INDEX(row + 1, col + 2), moves);


    return moves;
}
