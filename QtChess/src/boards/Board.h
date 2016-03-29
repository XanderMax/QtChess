#ifndef BOARD_H
#define BOARD_H

#include <array>

#include "BoardBase.h"
#include "../Constants.h"

#include "../models/CellDataObject.h"

class PieceState;

class Board : public BoardBase
{
private:

    std::array<std::shared_ptr<CellDataObject>, CELLS> cells;

    void init();

    void setCell(int, PieceType::Enum, PieceParty::Enum);
protected:

        std::shared_ptr<PieceState> _getPieceStateAt(int) const;
public:

    Board();
    ~Board();

    void resetToRegular();

    void resetToEmpty();


};

#endif //BOARD_H
