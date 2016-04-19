#include "BishopState.h"

#include "../boards/BoardBase.h"

std::bitset<CELLS> BishopState::getCellsToAttack(int row, int col, const BoardBase &board) const
{
    return getCellsToMove(row, col, board);
}

std::bitset<CELLS> BishopState::getCellsToMove(int row, int col, const BoardBase &board) const
{
    std::bitset<CELLS> moves;

    int r = row;
    int c = col;

    for(int index = INDEX(r - 1, c - 1); index != -1; --r,--c,index = INDEX(r, c))
    {
        setBit(index, moves);
        if(board.getPieceTypeAt(index) != PieceType::NONE)
        {
            break;
        }
    }

    r = row;
    c = col;

    for(int index = INDEX(r + 1, c + 1); index != -1; ++r,++c,index = INDEX(r, c))
    {
        setBit(index, moves);
        if(board.getPieceTypeAt(index) != PieceType::NONE)
        {
            break;
        }
    }

    r = row;
    c = col;

    for(int index = INDEX(r + 1, c - 1); index != -1; ++r,--c,index = INDEX(r, c))
    {
        setBit(index, moves);
        if(board.getPieceTypeAt(index) != PieceType::NONE)
        {
            break;
        }
    }

    r = row;
    c = col;

    for(int index = INDEX(r - 1, c + 1); index != -1; --r,++c,index = INDEX(r, c))
    {
        setBit(index, moves);
        if(board.getPieceTypeAt(index) != PieceType::NONE)
        {
            break;
        }
    }

    return moves;
}
