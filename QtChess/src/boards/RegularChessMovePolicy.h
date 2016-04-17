#ifndef REGULAR_CHESS_MOVE_POLICY_H
#define REGULAR_CHESS_MOVE_POLICY_H

#include "MovePolicy.h"

class RegularChessMovePolicy : public MovePolicy
{
private:
protected:
    QList<int> _getPossibleMovesFor(int index, const BoardBase& board,  int pieceAction, int occupyPolicy) const;

public:

    RegularChessMovePolicy() : MovePolicy() {}

    ~RegularChessMovePolicy() {}



};



#endif //REGULAR_CHESS_MOVE_POLICY_H
