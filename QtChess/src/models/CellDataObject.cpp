#include "CellDataObject.h"

#include "../Constants.h"

CellDataObject::CellDataObject(PieceType::Enum type, PieceParty::Enum party, int moves)
    : pieceState(PieceState::createPieceState(type, party, moves))
{

}

std::shared_ptr<PieceState> CellDataObject::getPieceState() const
{
    return pieceState;
}

PieceType::Enum CellDataObject::getPieceType() const
{
    if(pieceState != nullptr)
    {
        return pieceState->getPieceType();
    }

    return PieceType::NONE;
}

void CellDataObject::setPieceType(PieceType::Enum pieceType)
{
    PieceState *state;
    if(pieceState != nullptr)
    {
        state = PieceState::createPieceState(pieceType, pieceState->getPieceParty(), pieceState->getMoveCount());
    }
    else
    {
        state = PieceState::createPieceState(pieceType, PieceParty::WHITE, 0);
    }

    pieceState.reset(state);
}

PieceParty::Enum CellDataObject::getPieceParty() const
{
    if(pieceState != nullptr)
    {
        return pieceState->getPieceParty();
    }

    return PieceParty::WHITE;
}

void CellDataObject::setPieceParty(PieceParty::Enum pieceParty)
{
    PieceState *state;
    if(pieceState != nullptr)
    {
        state = PieceState::createPieceState(pieceState->getPieceType(), pieceParty, pieceState->getMoveCount());
    }
    else
    {
        state = PieceState::createPieceState(PieceType::NONE, pieceParty, 0);
    }

    pieceState.reset(state);
}

void CellDataObject::setPiece(PieceType::Enum type, PieceParty::Enum party, int moves)
{
    pieceState.reset(PieceState::createPieceState(type, party, moves));
}

bool CellDataObject::isMoved() const
{
    if(pieceState != nullptr)
    {
        return pieceState->isMoved();
    }

    return false;
}

void CellDataObject::move()
{
    PieceState *state;

    if(pieceState != nullptr)
    {
        state = PieceState::createPieceState(pieceState->getPieceType(), pieceState->getPieceParty(), pieceState->getMoveCount() + 1);
    }
    else
    {
        state = PieceState::createPieceState(PieceType::NONE, PieceParty::WHITE, 0);
    }

    pieceState.reset(state);
}

void CellDataObject::reset()
{
    setPieceType(PieceType::NONE);
}

int CellDataObject::getMoveCount() const
{
    if(pieceState != nullptr)
    {
        return pieceState->getMoveCount();
    }

    return 0;
}

QString CellDataObject::getState() const
{
    if(pieceState != nullptr)
    {
        if(pieceState->getPieceParty() == PieceParty::WHITE)
        {
            switch(pieceState->getPieceType())
            {
                case PieceType::NONE:
                {
                    return StateName::NONE;
                }

                case PieceType::PAWN:
                {
                    return StateName::W_PAWN;
                }

                case PieceType::KNIGHT:
                {
                    return StateName::W_KNIGHT;
                }

                case PieceType::BISHOP:
                {
                    return StateName::W_BISHOP;
                }

                case PieceType::ROOK:
                {
                    return StateName::W_ROOK;
                }

                case PieceType::QUEEN:
                {
                    return StateName::W_QUEEN;
                }

                case PieceType::KING:
                {
                    return StateName::W_KING;
                }

                default:
                {
                    return StateName::NONE;
                }
            }
        }
        else if(pieceState->getPieceParty() == PieceParty::BLACK)
        {
            switch(pieceState->getPieceType())
            {
                case PieceType::NONE:
                {
                    return StateName::NONE;
                }

                case PieceType::PAWN:
                {
                    return StateName::B_PAWN;
                }

                case PieceType::KNIGHT:
                {
                    return StateName::B_KNIGHT;
                }

                case PieceType::BISHOP:
                {
                    return StateName::B_BISHOP;
                }

                case PieceType::ROOK:
                {
                    return StateName::B_ROOK;
                }

                case PieceType::QUEEN:
                {
                    return StateName::B_QUEEN;
                }

                case PieceType::KING:
                {
                    return StateName::B_KING;
                }

                default:
                {
                    return StateName::NONE;
                }
            }
        }
    }

    return StateName::NONE;
}
