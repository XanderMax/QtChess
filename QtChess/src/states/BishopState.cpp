#include "BishopState.h"

#include "../boards/BoardBase.h"

std::bitset<CELLS> BishopState::getCellsToAttack(int row, int col, const BoardBase &board) const
{
    return getCellsToMove(row, col, board);
}

std::bitset<CELLS> BishopState::getCellsToMove(int row, int col, const BoardBase &board) const
{
    std::bitset<CELLS> moves;

    int begin = (row - col >= 0 ? row - col : 0);
    int end = (col - row >= 0 ? col - row : 0);

    for(int r = begin, c = end; r < ROWS && c < COLS; r++,c++)
    {
        if(r == row && c == col)
        {
            continue;
        }

        int index = INDEX(r, c);

        setBit(index, moves);

        if(board.getPieceTypeAt(index) != PieceType::NONE)
        {
            break;
        }
    }

    for(int r = end, c = begin; r < ROWS && c < COLS; r++,c++)
    {
        if(r == row && c == col)
        {
            continue;
        }

        int index = INDEX(r, c);

        setBit(index, moves);

        if(board.getPieceTypeAt(index) != PieceType::NONE)
        {
            break;
        }
    }

    return moves;
}
