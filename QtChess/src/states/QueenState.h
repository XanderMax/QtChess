#ifndef QUEEN_STATE_H
#define QUEEN_STATE_H

#include "PieceState.h"

class QueenState : public PieceState
{
private:
protected:

    std::bitset<CELLS> getCellsToAttack(int row, int col, const BoardBase&) const;
    std::bitset<CELLS> getCellsToMove(int row, int col, const BoardBase&) const;

public:

    QueenState(PieceParty::Enum party, int moves) : PieceState(PieceType::QUEEN, party, moves) {}

    ~QueenState() {}
};




#endif //QUEEN_STATE_H
