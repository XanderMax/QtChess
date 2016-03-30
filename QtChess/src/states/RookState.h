#ifndef ROOK_STATE_H
#define ROOK_STATE_H

#include "PieceState.h"

class RookState : public PieceState
{
private:
protected:

    std::bitset<64> getCellsToAttack(int row, int col, const BoardBase&) const;
    std::bitset<64> getCellsToMove(int row, int col, const BoardBase&) const;

public:

    RookState(PieceParty::Enum party, int moves) : PieceState(PieceType::ROOK, party, moves) {}

};




#endif //ROOK_STATE_H
