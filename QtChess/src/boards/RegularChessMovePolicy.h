#ifndef REGULAR_CHESS_MOVE_POLICY_H
#define REGULAR_CHESS_MOVE_POLICY_H

#include "MovePolicy.h"

class RegularChessMovePolicy : public MovePolicy
{
private:
protected:

    /**
     * @brief _getPossibleMovesFor returns a list of moves which either are not exposing king under attack, or, if king is already attacked, remove the check
     * @param index
     * @param board
     * @param pieceAction
     * @param occupyPolicy
     * @return list of possible cell indicies
     */
    QList<int> _getPossibleMovesFor(int index, const BoardBase& board,  int pieceAction, int occupyPolicy) const;

public:

    RegularChessMovePolicy() : MovePolicy() {}

    ~RegularChessMovePolicy() {}



};



#endif //REGULAR_CHESS_MOVE_POLICY_H
