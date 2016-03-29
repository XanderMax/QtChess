#ifndef KNIGHT_STATE_H
#define KNIGHT_STATE_H

#include "PieceState.h"

#include "../Constants.h"

class KnightState : public PieceState
{
private:
protected:

    std::bitset<CELLS> getCellsToAttack(int row, int col, const BoardBase&) const;
    std::bitset<CELLS> getCellsToMove(int row, int col, const BoardBase&) const;

public:

    KnightState(PieceParty::Enum party, int moves) : PieceState(PieceType::KNIGHT, party, moves) {}

    ~KnightState() {}
};





#endif //KNIGHT_STATE_H
