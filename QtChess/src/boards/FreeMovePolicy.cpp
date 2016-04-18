#include "FreeMovePolicy.h"

#include "../Constants.h"

QList<int> FreeMovePolicy::_getPossibleMovesFor(int, const BoardBase &, int, int) const
{
    QList<int> list;

    for(int i = 0; i < CELLS; i++)
    {
        list << i;
    }

    return list;
}
