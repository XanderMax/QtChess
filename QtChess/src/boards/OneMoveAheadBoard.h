#ifndef FREE_BOARD_H
#define FREE_BOARD_H

#include "BoardBase.h"

#include "Move.h"

#include "../states/NoneState.h"

class OneMoveAheadBoard : public BoardBase
{
private:

    const BoardBase& originalBoard;

    int fromIndex;

    int toIndex;

    std::shared_ptr<PieceState> emptyCell;
protected:
public:

    OneMoveAheadBoard(const BoardBase& board, const Move& move);
    ~OneMoveAheadBoard() {}

    std::shared_ptr<PieceState> _getPieceStateAt(int) const;

};


#endif //FREE_BOARD_H
