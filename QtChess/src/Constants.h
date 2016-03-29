#ifndef CONSTANTS_H
#define CONSTANTS_H

#define CELLS 64

#define ROWS 8
#define COLS 8

#define ROW(index) index / 8
#define COL(index) index % 8

#include "_BoardCellIndicies_.h"


//Piece states

namespace StateName
{
    static const char *NONE = "none";

    static const char *W_PAWN = "w_pawn";
    static const char *B_PAWN = "b_pawn";

    static const char *W_KNIGHT = "w_knight";
    static const char *B_KNIGHT = "b_knight";

    static const char *W_BISHOP = "w_bishop";
    static const char *B_BISHOP = "b_bishop";

    static const char *W_ROOK = "w_rook";
    static const char *B_ROOK = "b_rook";

    static const char *W_QUEEN = "w_queen";
    static const char *B_QUEEN = "b_queen";

    static const char *W_KING = "w_king";
    static const char *B_KING = "b_king";
}


#endif //CONSTANTS_H
