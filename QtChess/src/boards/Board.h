#ifndef BOARD_H
#define BOARD_H

#include <array>

#include "BoardBase.h"
#include "../Constants.h"

#include "../models/CellDataObject.h"

#include "RegularChessMovePolicy.h"

class PieceState;

class Board : public BoardBase
{
private:

    const QList<CellDataObject*>& cells;

    void setCell(int, PieceType::Enum, PieceParty::Enum);
protected:

        std::shared_ptr<PieceState> _getPieceStateAt(int) const;
public:

    Board(const QList<CellDataObject*>& _cells, const MovePolicy* policy = new RegularChessMovePolicy());
    ~Board();

    void resetToRegular();

    void resetToEmpty();


};

#endif //BOARD_H
