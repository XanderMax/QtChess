#include "OnePieceBoard.h"


std::shared_ptr<PieceState> OnePieceBoard::_getPieceStateAt(int index) const
{
    if(index == position)
    {
        return state;
    }
    else
    {
        return none;
    }
}
