#include "RegularChessMovePolicy.h"

#include <memory>

#include "BoardBase.h"

#include "OneMoveAheadBoard.h"

QList<int> RegularChessMovePolicy::_getPossibleMovesFor(int index, const BoardBase &board, int pieceAction, int occupyPolicy) const
{
    QList<int> list;

    if(board.getPieceTypeAt(index) != PieceType::NONE)
    {
        QList<int> allPossibleMoves = getCellsFromBits(board.getAvailableCells(index, pieceAction, occupyPolicy));

        for(int i = allPossibleMoves.size() - 1; i >= 0; i--)
        {
            //Using implicit constructor in second argument. The actual constructor is Move(int, int)
            OneMoveAheadBoard tempBoard(board, {index, allPossibleMoves[i]});

            PartyState::Enum partyState = tempBoard.getPartyState(board.getPiecePartyAt(index));

            //Commiting the move shouldn't expose king to an attack
            if(partyState == PartyState::CHECKED)
            {
                allPossibleMoves.removeAt(i);
            }
        }

        list << allPossibleMoves;
    }

    return list;
}
