#include "RookState.h"

#include "../boards/BoardBase.h"

#include "../Constants.h"

std::bitset<CELLS> RookState::getCellsToAttack(int row, int col, const BoardBase &board) const
{
    return getCellsToMove(row, col, board);
}

std::bitset<CELLS> RookState::getCellsToMove(int row, int col, const BoardBase &board) const
{
    std::bitset<CELLS> moves;

    for(int i = row - 1; i >= 0; i--)
    {
        setBit(INDEX(i, col), moves);

        if(board.getPieceTypeAt(i) != PieceType::NONE)
        {
            break;
        }
    }

    for(int i = row + 1; i < ROWS; i++)
    {
        setBit(INDEX(i, col), moves);

        if(board.getPieceTypeAt(i) != PieceType::NONE)
        {
            break;
        }
    }

    for(int i = col - 1; i >= 0; i--)
    {
        setBit(INDEX(row, i), moves);

        if(board.getPieceTypeAt(i) != PieceType::NONE)
        {
            break;
        }
    }

    for(int i = col + 1; i < COLS; i++)
    {
        setBit(INDEX(row, i), moves);

        if(board.getPieceTypeAt(i) != PieceType::NONE)
        {
            break;
        }
    }


    return moves;
}
