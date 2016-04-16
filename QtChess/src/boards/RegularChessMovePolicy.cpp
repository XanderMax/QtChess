#include "RegularChessMovePolicy.h"

#include <memory>

#include "BoardBase.h"

bool RegularChessMovePolicy::isMovePossible(const BoardBase &board, const Move &move) const
{
    std::shared_ptr<PieceState> state = board.getPieceStateAt(move.getFrom());

    if(state != nullptr && state->getPieceType() != PieceType::NONE)
    {
        //TODO: implement this further
    }

    return false;
}
