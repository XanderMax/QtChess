#ifndef PIECE_STATE_H
#define PIECE_STATE_H

#include <bitset>

#include <QList>

#include "../Enums.h"

#include "../Constants.h"

class BoardBase;

class PieceState
{
private:

    PieceType::Enum pieceType;

    PieceParty::Enum pieceParty;

    int moveCount;

    QChar _getChar() const;

protected:

    PieceState(PieceType::Enum type, PieceParty::Enum party, int _moveCount = 0) : pieceType(type), pieceParty(party), moveCount(_moveCount){}

    virtual std::bitset<CELLS> getCellsToAttack(int row, int col, const BoardBase&) const = 0;
    virtual std::bitset<CELLS> getCellsToMove(int row, int col, const BoardBase&) const = 0;

public:

    virtual ~PieceState() {}

    std::bitset<64> getCells(int index, const BoardBase&, int action = PieceAction::ALL, int policy = CellOccupyPolicy::POSSIBLE) const;

    PieceType::Enum getPieceType() const;

    PieceParty::Enum getPieceParty() const;

    bool isMoved() const;

    int getMoveCount() const;

    QChar getChar() const;

    static PieceState *createPieceState(PieceType::Enum, PieceParty::Enum, int moveCount = 0);

    static PieceState* copyPieceState(PieceState* pieceState);



};

template <size_t number>
void setBit(unsigned int index, std::bitset<number> &set)
{
    if(index >= 0 && index < set.size())
    {
        set.set(index);
    }
}

template <size_t number>
bool getBit(unsigned int index, const std::bitset<number> &set)
{
    if(index >= 0 && index < set.size())
    {
        return set[index];
    }

    return false;
}

template<size_t number>
QList<int> getCellsFromBits(const std::bitset<number> &set)
{
    QList<int> list;

    for(unsigned int i = 0; i < set.size(); i++)
    {
        if(set[i])
        {
            list << i;
        }
    }

    return list;
}

#endif //PIECE_STATE
