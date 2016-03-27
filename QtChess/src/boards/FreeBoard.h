#ifndef FREE_BOARD_H
#define FREE_BOARD_H

#include "BoardBase.h"

#include "../states/NoneState.h"

class FreeBoard : public BoardBase
{
private:

    const BoardBase& originalBoard;

    int fromIndex;

    int toIndex;

    std::shared_ptr<PieceState> emptyCell;
protected:
public:

    FreeBoard(const BoardBase& board, int fromIndex, int toIndex);
    ~FreeBoard() {}

    std::shared_ptr<PieceState> _getPieceStateAt(int) const;

};


#endif //FREE_BOARD_H
