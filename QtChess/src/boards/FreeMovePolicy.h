#ifndef FREE_MOVE_POLICY_H
#define FREE_MOVE_PILICY_H

#include "MovePolicy.h"

class FreeMovePolicy : public MovePolicy
{
private:
protected:
    QList<int> _getPossibleMovesFor(int index, const BoardBase&,  int pieceAction, int occupyPolicy) const;

public:

    FreeMovePolicy() : MovePolicy() {}

    ~FreeMovePolicy(){}


};




#endif //FREE_MOVE_POLICY_H
