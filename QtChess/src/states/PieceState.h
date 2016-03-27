#ifndef PIECE_STATE_H
#define PIECE_STATE_H

#include <bitset>

#include "../Enums.h"

class BoardBase;

class PieceState
{
private:

    PieceType::Enum pieceType;

    PieceParty::Enum pieceParty;

    int moveCount;

protected:

    PieceState(PieceType::Enum type, PieceParty::Enum party, int _moveCount = 0) : pieceType(type), pieceParty(party), moveCount(_moveCount){}

    virtual std::bitset<64> getCellsToAttack(int row, int col, const BoardBase&) const = 0;
    virtual std::bitset<64> getCellsToMove(int row, int col, const BoardBase&) const = 0;

public:

    virtual ~PieceState() {}

    std::bitset<64> getCells(int index, const BoardBase&, int action = PieceAction::ALL, int policy = CellOccupyPolicy::POSSIBLE) const;

    PieceType::Enum getPieceType() const;

    PieceParty::Enum getPieceParty() const;

    bool isMoved() const;

    int getMoveCount() const;

    static PieceState *createPieceState(PieceType::Enum, PieceParty::Enum, int moveCount = 0);



};


#endif //PIECE_STATE
