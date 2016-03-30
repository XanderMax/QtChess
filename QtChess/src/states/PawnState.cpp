#include "PawnState.h"

#include "../boards/BoardBase.h"

std::bitset<CELLS> PawnState::getCellsToMove(int row, int col, const BoardBase &) const
{
    std::bitset<CELLS> moves;

    if(getPieceParty() == PieceParty::BLACK)
    {
        if(!isMoved())
        {
            setBit(INDEX(row + 2, col), moves);
        }

        setBit(INDEX(row + 1, col), moves);
    }
    else if(getPieceParty() == PieceParty::WHITE)
    {
        if(!isMoved())
        {
            setBit(INDEX(row - 2, col), moves);
        }

        setBit(INDEX(row - 1, col), moves);
    }

    return moves;
}


std::bitset<CELLS> PawnState::getCellsToAttack(int row, int col, const BoardBase &) const
{
    std::bitset<CELLS> moves;

    if(getPieceParty() == PieceParty::BLACK)
    {
        setBit(INDEX(row + 1, col - 1), moves);

        setBit(INDEX(row + 1, col + 1), moves);
    }
    else if(getPieceParty() == PieceParty::WHITE)
    {
        setBit(INDEX(row - 1, col - 1), moves);

        setBit(INDEX(row - 1, col + 1), moves);
    }

    return moves;
}
