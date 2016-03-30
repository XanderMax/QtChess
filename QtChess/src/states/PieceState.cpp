#include "PieceState.h"

#include <memory>

#include "../boards/BoardBase.h"
#include "../Constants.h"

#include "NoneState.h"
#include "KingState.h"
#include "KnightState.h"
#include "PawnState.h"

std::bitset<64> PieceState::getCells(int index, const BoardBase &board, int action, int occupyPolicy) const
{
    std::bitset<64> cells;

    if(action & PieceAction::ATTACK)
    {
        cells |= getCellsToAttack(ROW(index), COL(index), board);
    }

    if(action & PieceAction::MOVE)
    {
        cells |= getCellsToMove(ROW(index), COL(index), board);
    }

    std::bitset<64> mask;

    for(int i = 0; i < CELLS; i++)
    {
        std::shared_ptr<PieceState> pieceState = board.getPieceStateAt(i);

        if(pieceState != nullptr)
        {
            if((occupyPolicy & CellOccupyPolicy::EMPTY) && pieceState->getPieceType() == PieceType::NONE)
            {
                mask.set(i);
            }

            if((occupyPolicy & CellOccupyPolicy::FRIENDLY) && pieceState->getPieceParty() == getPieceParty())
            {
                mask.set(i);
            }

            if((occupyPolicy & CellOccupyPolicy::HOSTILE) && pieceState->getPieceParty() != getPieceParty())
            {
                mask.set(i);
            }
        }
    }


    return cells & mask;
}

PieceType::Enum PieceState::getPieceType() const
{
    return pieceType;
}

PieceParty::Enum PieceState::getPieceParty() const
{
    return pieceParty;
}

bool PieceState::isMoved() const
{
    return moveCount > 0;
}

int PieceState::getMoveCount() const
{
    return moveCount;
}

PieceState *PieceState::createPieceState(PieceType::Enum type, PieceParty::Enum party, int moveCount)
{
    switch(type)
    {
        case PieceType::NONE:
        {
            return new NoneState();
        }

        case PieceType::PAWN:
        {
            return new PawnState(party, moveCount);
        }

        case PieceType::KNIGHT:
        {
            return new KnightState(party, moveCount);
        }

        case PieceType::BISHOP:
        {
            break;
        }

        case PieceType::ROOK:
        {
            break;
        }

        case PieceType::QUEEN:
        {
            break;
        }

        case PieceType::KING:
        {
            return new KingState(party, moveCount);
        }

    }

    return new NoneState();
}
