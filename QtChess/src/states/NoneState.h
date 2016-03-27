#ifndef NONE_STATE_H
#define NONE_STATE_H

#include "PieceState.h"

class NoneState : public PieceState
{
private:
protected:
public:

    NoneState():PieceState(PieceType::NONE, PieceParty::BLACK, 0) {}
    ~NoneState(){}

    std::bitset<64> getCellsToAttack(int, int, const BoardBase&) const {return std::bitset<64>();}

    std::bitset<64> getCellsToMove(int, int, const BoardBase&) const {return std::bitset<64>();}
};


#endif //NONE_STATE_H
