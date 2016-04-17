#include "FreeMovePolicy.h"

#include "../Constants.h"

QList<int> FreeMovePolicy::_getPossibleMovesFor(int, const BoardBase &, int, int) const
{
    QList<int> list;

    for(int i = _A1_; i < _H8_; i++)
    {
        list << i;
    }

    return list;
}
