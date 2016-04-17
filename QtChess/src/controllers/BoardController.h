#ifndef BOARD_CONTROLLER_H
#define BOARD_CONTROLLER_H

#include <QList>
#include <QObject>

#include "../boards/Board.h"
#include "../models/CellDataObject.h"
#include "../game/GameState.h"
#include "Controller.h"

class BoardController : public QObject, public Controller
{
    Q_OBJECT

private:

protected:

public:

    BoardController(const Game& game) : Controller(game){}
    ~BoardController() {}

    Q_INVOKABLE QList<int> getDangerousCells(int index) const;
    Q_INVOKABLE QList<int> getAvailableCells(int index) const;
};



#endif //BOARD_CONTROLLER_H
