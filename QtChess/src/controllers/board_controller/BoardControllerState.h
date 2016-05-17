#ifndef BOARD_CONTROLLER_STARTEGY_H
#define BOARD_CONTROLLER_STARTEGY_H

#include "../../boards/Move.h"


class BoardController;

class BoardControllerState
{
private:
protected:

    BoardController& controller;

    virtual bool _makeMove(const Move& move) = 0;

public:

    BoardControllerState(BoardController& _controller) : controller(_controller) {}
    virtual ~BoardControllerState() {}

    bool makeMove(const Move& move);

    virtual bool canMove(const Move& move) const = 0;
};




#endif //BOARD_CONTROLLER_STRATEGY_H
