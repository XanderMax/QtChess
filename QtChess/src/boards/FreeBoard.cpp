#include "FreeBoard.h"


FreeBoard::FreeBoard(const BoardBase &board, int _fromIndex, int _toIndex)
    : originalBoard(board), fromIndex(_fromIndex), toIndex(_toIndex)
{
    emptyCell = std::shared_ptr<PieceState>(new NoneState());
}

std::shared_ptr<PieceState> FreeBoard::_getPieceStateAt(int index) const
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
