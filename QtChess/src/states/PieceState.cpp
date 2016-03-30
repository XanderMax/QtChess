#include "PieceState.h"

#include <memory>

#include "../boards/BoardBase.h"
#include "../Constants.h"

#include "NoneState.h"
#include "KingState.h"
#include "KnightState.h"
#include "PawnState.h"
#include "RookState.h"

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

    bool empty = ((occupyPolicy & CellOccupyPolicy::EMPTY) != 0);

    bool friendly = ((occupyPolicy & CellOccupyPolicy::FRIENDLY) != 0);

    bool hostile = ((occupyPolicy & CellOccupyPolicy::HOSTILE) != 0);

    for(int i = 0; i < CELLS; i++)
    {
        std::shared_ptr<PieceState> pieceState = board.getPieceStateAt(i);

        if(pieceState != nullptr)
        {
            if(empty && pieceState->getPieceType() == PieceType::NONE)
            {
                mask.set(i);
            }

            if(friendly && pieceState->getPieceParty() == getPieceParty()
                    && pieceState->getPieceType() != PieceType::NONE)
            {
                mask.set(i);
            }

            if(hostile && pieceState->getPieceParty() != getPieceParty()
                    && pieceState->getPieceType() != PieceType::NONE)
            {
                mask.set(i);
            }
        }
    }

    std::string str = (cells & mask).to_string();
    std::string str_mask = (mask).to_string();
    std::string str_cells = (cells).to_string();


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
            return new RookState(party, moveCount);
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
