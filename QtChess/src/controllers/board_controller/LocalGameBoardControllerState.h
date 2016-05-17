#ifndef LOCAL_GAME_BOARD_CONTROLLER_STARTEGY_H
#define LOCAL_GAME_BOARD_CONTROLLER_STARTEGY_H

#include "BoardControllerState.h"

class LocalGameboardControllerState : public BoardControllerState
{
private:
protected:

    bool _makeMove(const Move &move);

    bool canMove(const Move &move) const {return true;}
public:

    LocalGameboardControllerState(BoardController& controller);
    ~LocalGameboardControllerState() {}

};




#endif //LOCAL_GAME_BOARD_CONTROLLER_STARTEGY_H
