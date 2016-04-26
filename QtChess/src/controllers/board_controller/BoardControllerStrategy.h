#ifndef BOARD_CONTROLLER_STARTEGY_H
#define BOARD_CONTROLLER_STARTEGY_H

#include "../../boards/Move.h"


class BoardController;

class BoardControllerStrategy
{
private:
protected:

    BoardController& controller;

    virtual bool _makeMove(const Move& move) = 0;
public:

    BoardControllerStrategy(BoardController& _controller) : controller(_controller) {}
    virtual ~BoardControllerStrategy() {}

    bool makeMove(const Move& move);
};




#endif //BOARD_CONTROLLER_STRATEGY_H
