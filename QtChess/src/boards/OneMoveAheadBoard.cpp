#include "OneMoveAheadBoard.h"


OneMoveAheadBoard::OneMoveAheadBoard(const BoardBase &board, const Move &move)
    : BoardBase(new FreeMovePolicy()), originalBoard(board), fromIndex(move.getFrom()), toIndex(move.getTo())
{
    emptyCell = std::shared_ptr<PieceState>(new NoneState());
}

std::shared_ptr<PieceState> OneMoveAheadBoard::_getPieceStateAt(int index) const
{
    if(index == fromIndex)
    {
        return emptyCell;
    }
    else if(index == toIndex)
    {
        return originalBoard.getPieceStateAt(fromIndex);
    }
    else
    {
        return originalBoard.getPieceStateAt(index);
    }
}
