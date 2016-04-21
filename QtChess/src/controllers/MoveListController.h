#ifndef MOVE_LIST_CONTROLLER_H
#define MOVE_LIST_CONTROLLER_H

#include "Controller.h"

#include "../boards/Board.h"

class MoveListController : public Controller
{
    Q_OBJECT

private:

    Board* board;
protected:

    void _start();
    void _stop();

public:

    MoveListController(Game& game) : Controller(game){}
    ~MoveListController(){}

    Q_INVOKABLE void restoreToMove(int index);

    Q_INVOKABLE void startFrom(int index);


};





#endif //MOVE_LIST_CONTROLLER_H
