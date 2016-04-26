#ifndef LOCAL_GAME_BOARD_CONTROLLER_STARTEGY_H
#define LOCAL_GAME_BOARD_CONTROLLER_STARTEGY_H

#include "BoardControllerStrategy.h"

class LocalGameboardControllerStrategy : public BoardControllerStrategy
{
private:
protected:

    bool _makeMove(const Move &move);
public:

    LocalGameboardControllerStrategy(BoardController& controller);
    ~LocalGameboardControllerStrategy() {}

};




#endif //LOCAL_GAME_BOARD_CONTROLLER_STARTEGY_H
