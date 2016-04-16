#ifndef MOVE_POLICY_H
#define MOVE_POLICY_H

#include "Move.h"

class BoardBase;

class MovePolicy
{
private:
protected:

    MovePolicy(){}

public:

    virtual ~MovePolicy(){}

    virtual bool isMovePossible(const BoardBase& board, const Move&) const = 0;

};




#endif //MOVE_POLICY_H
