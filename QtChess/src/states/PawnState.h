#ifndef PAWN_STATE_H
#define PAWN_STATE_H

#include "PieceState.h"

class PawnState : public PieceState
{
private:
protected:

    std::bitset<64> getCellsToAttack(int row, int col, const BoardBase&) const;
    std::bitset<64> getCellsToMove(int row, int col, const BoardBase&) const;

public:

    PawnState(PieceParty::Enum party, int moves) : PieceState(PieceType::PAWN, party, moves) {}
    ~PawnState() {}

};




#endif //PAWN_STATE_H
