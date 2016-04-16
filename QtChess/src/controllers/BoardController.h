#ifndef BOARD_CONTROLLER_H
#define BOARD_CONTROLLER_H

#include <QList>
#include <QObject>

#include "../boards/Board.h"
#include "../models/CellDataObject.h"

class BoardController : public QObject
{
    Q_OBJECT

private:

    const QList<CellDataObject>& cells;

protected:
public:

    BoardController(const QList<CellDataObject>& _cells) : cells(_cells){}
    ~BoardController() {}

    Q_INVOKABLE QList<int> getDangerousCells(int index) const;
    Q_INVOKABLE QList<int> getAvailableCells(int index) const;
};



#endif //BOARD_CONTROLLER_H
