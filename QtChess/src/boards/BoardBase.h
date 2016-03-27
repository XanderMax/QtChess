#ifndef BOARD_BASE_H
#define BOARD_BASE_H

#include <memory>

#include "../Enums.h"

#include "../states/PieceState.h"

class BoardBase
{
private:
protected:
    BoardBase() {}
    virtual ~BoardBase() {}

    virtual std::shared_ptr<PieceState> _getPieceStateAt(int) const = 0;

public:

    int getKingIndex(PieceParty::Enum) const;

    std::shared_ptr<PieceState> getPieceStateAt(int) const;

    PartyState::Enum getPartyState(PieceParty::Enum) const;

};

#endif //BOARD_BASE_H
