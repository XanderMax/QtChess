#include "QueenState.h"

#include "../boards/BoardBase.h"
#include "RookState.h"
#include "BishopState.h"


std::bitset<CELLS> QueenState::getCellsToAttack(int row, int col, const BoardBase &board) const
{
    std::bitset<CELLS> moves;

    moves |= (RookState(getPieceParty(), getMoveCount())).getCells(INDEX(row, col), board, PieceAction::ATTACK, CellOccupyPolicy::ALL);
    moves |= (BishopState(getPieceParty(), getMoveCount())).getCells(INDEX(row, col), board, PieceAction::ATTACK, CellOccupyPolicy::ALL);

    return moves;
}

std::bitset<CELLS> QueenState::getCellsToMove(int row, int col, const BoardBase &board) const
{
    std::bitset<CELLS> moves;

    moves |= (RookState(getPieceParty(), getMoveCount())).getCells(INDEX(row, col), board, PieceAction::MOVE, CellOccupyPolicy::ALL);
    moves |= (BishopState(getPieceParty(), getMoveCount())).getCells(INDEX(row, col), board, PieceAction::MOVE, CellOccupyPolicy::ALL);

    return moves;
}
