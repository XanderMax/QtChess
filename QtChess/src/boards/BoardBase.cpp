#include "BoardBase.h"

#include "../Constants.h"

#include "../Utils.h"


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

    std::bitset<CELLS> enemyMoves;

    for(int i = 0; i < CELLS; i++)
    {
        std::shared_ptr<PieceState> state = getPieceStateAt(i);

        if(state != nullptr)
        {
            if(state->getPieceParty() != party && state->getPieceType() != PieceType::NONE)
            {
                std::bitset<CELLS> cells = state->getCells(i, *this, PieceAction::ATTACK, CellOccupyPolicy::FRIENDLY | CellOccupyPolicy::HOSTILE);

                QList<int> tempList = getCellsFromBits(cells);

                enemyMoves |= cells;
            }
        }
    }

    if(partyKingIndex >= 0 && partyKingIndex < enemyMoves.size() && enemyMoves[partyKingIndex])
    {
        //Party king is under attack

        return PartyState::CHECKED;
    }

    return PartyState::REGULAR;
}

BoardState::Enum BoardBase::getBoardState(PieceParty::Enum party) const
{
    PartyState::Enum partyState = getPartyState(party);

    QList<int> possibleMovesForParty;
    if(policy != nullptr)
    {
        for(int i = 0; i < CELLS; i++)
        {
            if(getPiecePartyAt(i) == party && getPieceTypeAt(i) != PieceType::NONE)
            {
                possibleMovesForParty
                        << (policy->getPossibleMovesFor(i, *this, (0 | PieceAction::MOVE), (0 | CellOccupyPolicy::EMPTY)))
                        << (policy->getPossibleMovesFor(i, *this, (0 | PieceAction::ATTACK), (0 | CellOccupyPolicy::HOSTILE)));
            }
        }
    }

    if(partyState == PartyState::CHECKED)
    {
        //King is under attack

        if(possibleMovesForParty.size() > 0)
        {
            return BoardState::CHECKED;
        }
        else
        {
            return BoardState::MATED;
        }
    }
    else if(partyState == PartyState::REGULAR)
    {
        //King is not under attack

        if(possibleMovesForParty.size() > 0)
        {
            return BoardState::REGULAR;
        }
        else
        {
            return BoardState::PATED;
        }
    }

    return BoardState::REGULAR;
}

std::bitset<CELLS> BoardBase::getAvailableCells(int index, int action, int occupyPolicy) const
{
    std::shared_ptr<PieceState> state = getPieceStateAt(index);
    if(state != nullptr)
    {
        return state->getCells(index, *this, action, occupyPolicy);
    }

    return std::bitset<CELLS>();
}

std::bitset<CELLS> BoardBase::getAvailableMoves(int index, int action, int occupyPolicy) const
{
    if(policy != nullptr)
    {
        return policy->getPossibleBitsFor(index, *this, action, occupyPolicy);
    }

    return std::bitset<CELLS>();
}

std::bitset<CELLS> BoardBase::getCellsToMove(int index) const
{
    return getAvailableCells(index, PieceAction::MOVE, CellOccupyPolicy::EMPTY)
            | getAvailableCells(index, PieceAction::ATTACK, CellOccupyPolicy::HOSTILE);
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
        return (policy->getPossibleMovesFor(move.getFrom(), *this)).contains(move.getTo());
    }

    return true;
}

QString BoardBase::getBoardString() const
{
    QString string;
    for(int i = 0; i < CELLS; i++)
    {
        std::shared_ptr<PieceState> state = getPieceStateAt(i);

        if(state != nullptr)
        {
            string.append(state->getChar());
        }
        else
        {
            string.append(_NONE);
        }
    }

    return string;
}
