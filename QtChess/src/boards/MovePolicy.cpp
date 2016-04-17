#include "MovePolicy.h"

#include "../Constants.h"

#include "../states/PieceState.h"

QList<int> MovePolicy::getPossibleMovesFor(int index, const BoardBase &board,  int pieceAction, int occupyPolicy) const
{
    QList<int> list;

    if(index >= 0 && index < CELLS)
    {
        list = _getPossibleMovesFor(index, board, pieceAction, occupyPolicy);

        for(int i = list.length() - 1; i >= 0; i--)
        {
            if(list[i] < 0 || list[i] >= CELLS || i == index)
            {
                list.removeAt(i);
            }
        }
    }

    return list;
}

std::bitset<CELLS> MovePolicy::getPossibleBitsFor(int index, const BoardBase &board, int pieceAction, int occupyPolicy) const
{
    QList<int> list = getPossibleMovesFor(index, board, pieceAction, occupyPolicy);

    std::bitset<CELLS> set;

    for(int i : list)
    {
        setBit(i, set);
    }

    return set;
}
