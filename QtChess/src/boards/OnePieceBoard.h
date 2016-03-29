#ifndef ONE_PIECE_BOARD_H
#define ONE_PIECE_BOARD_H


#include "BoardBase.h"


class OnePieceBoard : public BoardBase
{
private:
    int position;

    std::shared_ptr<PieceState> state;

    std::shared_ptr<PieceState> none;

protected:
        std::shared_ptr<PieceState> _getPieceStateAt(int) const;
public:

    OnePieceBoard(int index, PieceType::Enum type, PieceParty::Enum party, int moves)
        :position(index), state(PieceState::createPieceState(type, party, moves))
        ,none(PieceState::createPieceState(PieceType::NONE, PieceParty::WHITE)) {}

    ~OnePieceBoard() {state = nullptr; none = nullptr;}

};




#endif //ONE_PIECE_BOARD_H
