#ifndef KING_STATE_H
#define KING_STATE_H

#include "PieceState.h"

#include "../Constants.h"

class KingState : public PieceState
{
private:

    std::bitset<CELLS> getRegularMoves(int row, int col, const BoardBase&) const;
protected:

    std::bitset<CELLS> getCellsToAttack(int row, int col, const BoardBase&) const;
    std::bitset<CELLS> getCellsToMove(int row, int col, const BoardBase&) const;

public:

    KingState(PieceParty::Enum party, int moveCount) : PieceState(PieceType::KING, party, moveCount) {}

    ~KingState() {}




};



#endif //KING_STATE_H
