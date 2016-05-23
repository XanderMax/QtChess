#ifndef NULL_BOARD_CONTROLLER_STATE_H
#define NULL_BOARD_CONTROLLER_STATE_H

#include "BoardControllerState.h"

class NullBoardControllerState : public BoardControllerState
{
private:
protected:

    bool _makeMove(const Move &move);

public:

    NullBoardControllerState(BoardController& controller);
    ~NullBoardControllerState();

    bool canMove(const Move &move) const {return false;}
};




#endif //NULL_BOARD_CONTROLLER_STATE_H
