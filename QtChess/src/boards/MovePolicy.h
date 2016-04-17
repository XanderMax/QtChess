#ifndef MOVE_POLICY_H
#define MOVE_POLICY_H

#include <bitset>

#include <QList>

#include "Move.h"

#include "../Enums.h"

#include "../Constants.h"

class BoardBase;

class MovePolicy
{
private:
protected:

    MovePolicy(){}

    virtual QList<int> _getPossibleMovesFor(int, const BoardBase& board, int pieceAction, int occupyPolicy) const = 0;

public:

    virtual ~MovePolicy(){}

    QList<int> getPossibleMovesFor(int index, const BoardBase& board, int pieceAction = PieceAction::ALL, int occupyPolicy = CellOccupyPolicy::POSSIBLE) const;

    std::bitset<CELLS> getPossibleBitsFor(int index, const BoardBase& board, int pieceAction = PieceAction::ALL, int occupyPolicy = CellOccupyPolicy::POSSIBLE) const;



};




#endif //MOVE_POLICY_H
