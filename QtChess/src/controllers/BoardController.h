#ifndef BOARD_CONTROLLER_H
#define BOARD_CONTROLLER_H

#include <QList>
#include <QObject>

#include "../boards/Board.h"
#include "../models/CellDataObject.h"
#include "../game/GameState.h"
#include "Controller.h"

class BoardController : public Controller
{
    Q_OBJECT

private:

    Board* board;

protected:

    void _start();
    void _stop();

public:

    BoardController(Game& game) : Controller(game){}
    ~BoardController();

    Q_INVOKABLE QList<int> getDangerousCells(int index) const;
    Q_INVOKABLE QList<int> getAvailableCells(int index) const;
    Q_INVOKABLE bool move(int from, int to);

    Q_INVOKABLE void setBoardString(const QString& str);

    Q_INVOKABLE int getPartyKing(PieceParty::Enum party) const;
};



#endif //BOARD_CONTROLLER_H
