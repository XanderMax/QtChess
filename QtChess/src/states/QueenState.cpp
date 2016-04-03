#include "QueenState.h"

#include "../boards/BoardBase.h"


std::bitset<CELLS> QueenState::getCellsToAttack(int row, int col, const BoardBase &board) const
{
    return getCellsToMove(row, col, board);
}

std::bitset<CELLS> QueenState::getCellsToMove(int row, int col, const BoardBase &) const
{
    std::bitset<CELLS> moves;

    return moves;
}
