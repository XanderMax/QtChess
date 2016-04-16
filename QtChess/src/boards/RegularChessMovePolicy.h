#ifndef REGULAR_CHESS_MOVE_POLICY_H
#define REGULAR_CHESS_MOVE_POLICY_H

#include "MovePolicy.h"

class RegularChessMovePolicy : public MovePolicy
{
private:
protected:
public:

    RegularChessMovePolicy() : MovePolicy() {}

    ~RegularChessMovePolicy() {}


    bool isMovePossible(const BoardBase& board, const Move&) const;
};



#endif //REGULAR_CHESS_MOVE_POLICY_H
