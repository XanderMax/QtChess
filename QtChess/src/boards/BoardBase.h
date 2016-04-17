#ifndef BOARD_BASE_H
#define BOARD_BASE_H

#include <memory>

#include "../Enums.h"

#include "../states/PieceState.h"

#include "Move.h"

#include "MovePolicy.h"
#include "FreeMovePolicy.h"

#include "../Constants.h"

class BoardBase
{
private:

    const MovePolicy* policy;

protected:
    BoardBase(const MovePolicy* _policy) : policy(_policy) {}
    virtual ~BoardBase();

    virtual std::shared_ptr<PieceState> _getPieceStateAt(int) const = 0;

public:

    int getKingIndex(PieceParty::Enum) const;

    std::shared_ptr<PieceState> getPieceStateAt(int) const;

    PartyState::Enum getPartyState(PieceParty::Enum) const;

    BoardState::Enum getBoardState(PieceParty::Enum) const;

    std::bitset<CELLS> getAvailableCells(int index, int action = PieceAction::ALL, int policy = CellOccupyPolicy::POSSIBLE) const;

    PieceType::Enum getPieceTypeAt(int) const;

    PieceParty::Enum getPiecePartyAt(int) const;

    int getMoveCountAt(int) const;

    bool getIsMovedAt(int) const;

    bool isMovePossible(const Move& move) const;

};

#endif //BOARD_BASE_H
