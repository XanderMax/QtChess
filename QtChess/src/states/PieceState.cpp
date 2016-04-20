#include "PieceState.h"

#include <memory>

#include "../boards/BoardBase.h"
#include "../Constants.h"

#include "NoneState.h"
#include "KingState.h"
#include "KnightState.h"
#include "PawnState.h"
#include "RookState.h"
#include "BishopState.h"
#include "QueenState.h"

#include "../Utils.h"

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

QChar PieceState::getChar() const
{
    QChar ch = _getChar();

    if(getPieceParty() == PieceParty::BLACK)
    {
        return ch.toUpper();
    }
    else
    {
        return ch.toLower();
    }
}

QChar PieceState::_getChar() const
{
    switch(getPieceType())
    {
        case PieceType::NONE:
        {
            return _NONE;
        }

        case PieceType::PAWN:
        {
            return _PAWN;
        }

        case PieceType::KNIGHT:
        {
            return _KNIGHT;
        }

        case PieceType::BISHOP:
        {
            return _BISHOP;
        }

        case PieceType::ROOK:
        {
            return _ROOK;
        }

        case PieceType::QUEEN:
        {
            return _QUEEN;
        }

        case PieceType::KING:
        {
            return _KING;
        }
    }

    return _NONE;
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
            return new BishopState(party, moveCount);
        }

        case PieceType::ROOK:
        {
            return new RookState(party, moveCount);
        }

        case PieceType::QUEEN:
        {
            return new QueenState(party, moveCount);
        }

        case PieceType::KING:
        {
            return new KingState(party, moveCount);
        }

    }

    return new NoneState();
}

PieceState *PieceState::copyPieceState(PieceState *pieceState)
{
    if(pieceState != nullptr)
    {
        return createPieceState(pieceState->getPieceType(), pieceState->getPieceParty(), pieceState->getMoveCount());
    }

    return new NoneState();
}
