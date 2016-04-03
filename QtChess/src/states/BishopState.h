#ifndef BISHOP_STATE_H
#define BISHOP_STATE_H

#include "PieceState.h"

class BishopState : public PieceState
{
private:
protected:

    virtual std::bitset<64> getCellsToAttack(int row, int col, const BoardBase&) const;
    virtual std::bitset<64> getCellsToMove(int row, int col, const BoardBase&) const;

public:

    BishopState(PieceParty::Enum party, int moves) : PieceState(PieceType::BISHOP, party, moves) {}
    ~BishopState() {}
};




#endif //BISHOP_STATE_H
