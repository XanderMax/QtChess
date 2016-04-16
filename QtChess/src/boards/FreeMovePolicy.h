#ifndef FREE_MOVE_POLICY_H
#define FREE_MOVE_PILICY_H

#include "MovePolicy.h"

class FreeMovePolicy : public MovePolicy
{
private:
protected:
public:

    FreeMovePolicy() : MovePolicy() {}

    ~FreeMovePolicy(){}

    bool isMovePossible(const BoardBase&, const Move &) const {return true;}
};




#endif //FREE_MOVE_POLICY_H
