#ifndef PIECE_STATE_H
#define PIECE_STATE_H

#include <bitset>

#include "boards/Board.h"
#include "Enums.h"

class BoardBase;

class PieceState
{
private:

    PieceType::Enum pieceType;

    PieceParty::Enum pieceParty;

    bool moved;

protected:

    PieceState(PieceType::Enum type, PieceParty::Enum party, bool _moved) : pieceType(type), pieceParty(party), moved(_moved){}
    virtual ~PieceState() {}

    virtual std::bitset<64> getCellsToAttack(int row, int col, const BoardBase&) const = 0;
    virtual std::bitset<64> getCellsToMove(int row, int col, const BoardBase&) const = 0;

public:

    std::bitset<64> getCells(int index, const BoardBase&, int action = PieceAction::ALL, int policy = CellOccupyPolicy::POSSIBLE) const;

    PieceType::Enum getPieceType() const;

    PieceParty::Enum getPieceParty() const;

    bool isMoved() const;



};



#endif //PIECE_STATE
