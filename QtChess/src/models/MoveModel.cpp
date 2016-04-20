#include "MoveModel.h"

#include "../Constants.h"

int MoveModel::getFrom() const
{
    return move.getFrom();
}

int MoveModel::getTo() const
{
    return move.getTo();
}

MoveModel::MoveModel(const Move &_move, const QList<CellDataObject *> list) : move(_move), fromState(nullptr), toState(nullptr)
{
    if(move.getFrom() >= 0 && move.getFrom() < list.size())
    {
        CellDataObject* cellFrom = list[move.getFrom()];

        if(cellFrom != nullptr)
        {
            sStateFrom = cellFrom->getState();
            fromState = PieceState::copyPieceState(cellFrom->getPieceState().get());
        }
        else
        {
            sStateFrom = StateName::NONE;
        }
    }

    if(move.getTo() >= 0 && move.getTo() < list.size())
    {
        CellDataObject* cellTo = list[move.getTo()];

        if(cellTo != nullptr)
        {
            sStateTo = cellTo->getState();
            toState = PieceState::copyPieceState(cellTo->getPieceState().get());
        }
        else
        {
            sStateTo = StateName::NONE;
        }
    }

    emit onFromIndexChanged(move.getFrom());
    emit onToIndexChanged(move.getFrom());

    emit onFromStateChanged(getStateFrom());
    emit onToStateChanged(getStateTo());
}

MoveModel::~MoveModel()
{
    delete fromState;
    delete toState;
}

const Move &MoveModel::getMove() const
{
    return move;
}

QString MoveModel::getStateFrom() const
{
    return sStateFrom;
}

QString MoveModel::getStateTo() const
{
    return sStateTo;
}
