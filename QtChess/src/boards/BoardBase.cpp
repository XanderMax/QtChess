#include "BoardBase.h"

#include "../Constants.h"


BoardBase::~BoardBase()
{
    delete policy;

    policy = nullptr;
}

int BoardBase::getKingIndex(PieceParty::Enum party) const
{
    for(int i = 0; i < CELLS; i++)
    {
        std::shared_ptr<PieceState> pieceState = getPieceStateAt(i);

        if(pieceState != nullptr)
        {
            if(pieceState->getPieceParty() == party && pieceState->getPieceType() == PieceType::KING)
            {
                return i;
            }
        }
    }

    return -1;
}

std::shared_ptr<PieceState> BoardBase::getPieceStateAt(int index) const
{
    return _getPieceStateAt(index);
}

PartyState::Enum BoardBase::getPartyState(PieceParty::Enum party) const
{
    //TODO: implement this method

    int partyKingIndex = getKingIndex(party);
    std::shared_ptr<PieceState> partyKing = getPieceStateAt(partyKingIndex);

    std::bitset<64> kingMoves;

    std::bitset<64> partyMoves;

    std::bitset<64> enemyMoves;

    if(partyKing != nullptr)
    {
        kingMoves = partyKing->getCells(partyKingIndex, *this);
    }

    for(int i = 0; i < CELLS; i++)
    {
        std::shared_ptr<PieceState> state = getPieceStateAt(i);

        if(state != nullptr)
        {
            if(state->getPieceParty() == party)
            {
                if(i == partyKingIndex)
                {
                    continue;
                }

                partyMoves |= state->getCells(i, *this);
            }
            else
            {
                enemyMoves |= state->getCells(i, *this, PieceAction::ALL, CellOccupyPolicy::ALL);
            }
        }
    }

    if(partyKingIndex >= 0 && partyKingIndex < enemyMoves.size() && enemyMoves[partyKingIndex])
    {
        //Party king is under attack

        return PartyState::CHECKED;
    }
    else
    {
        //Party king is not under attack

        if((partyMoves | kingMoves).none())
        {
            return PartyState::PATED;
        }
    }

    return PartyState::REGULAR;
}

std::bitset<CELLS> BoardBase::getAvailableCells(int index, int action, int policy) const
{
    std::shared_ptr<PieceState> state = getPieceStateAt(index);

    if(state != nullptr)
    {
        return state->getCells(index, *this, action, policy);
    }

    return std::bitset<CELLS>();
}

PieceType::Enum BoardBase::getPieceTypeAt(int index) const
{
    std::shared_ptr<PieceState> piece = getPieceStateAt(index);

    if(piece != nullptr)
    {
        return piece->getPieceType();
    }

    return PieceType::NONE;
}

PieceParty::Enum BoardBase::getPiecePartyAt(int index) const
{
    std::shared_ptr<PieceState> piece = getPieceStateAt(index);

    if(piece != nullptr)
    {
        return piece->getPieceParty();
    }

    return PieceParty::WHITE;
}

int BoardBase::getMoveCountAt(int index) const
{
    std::shared_ptr<PieceState> piece = getPieceStateAt(index);

    if(piece != nullptr)
    {
        return piece->getMoveCount();
    }

    return 0;
}

bool BoardBase::getIsMovedAt(int index) const
{
    std::shared_ptr<PieceState> piece = getPieceStateAt(index);

    if(piece != nullptr)
    {
        return piece->isMoved();
    }

    return false;
}

bool BoardBase::isMovePossible(const Move &move) const
{
    if(policy != nullptr)
    {
        return policy->isMovePossible(*this, move);
    }

    return true;
}
