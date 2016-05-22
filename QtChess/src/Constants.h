#ifndef CONSTANTS_H
#define CONSTANTS_H

#define CELLS 64

#define ROWS 8
#define COLS 8

#define ROW(index) index / 8
#define COL(index) index % 8

#define INDEX(row, col) (((row) >= 0 && (row) < ROWS) ? (((col) >= 0 && (col) < COLS) ? ((8 * (row)) + (col)) : -1) : -1)

#include "_BoardCellIndicies_.h"

#include <QtGlobal>


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

namespace ControllerName
{
    static const char *BOARD_CONTROLLER = "boardController";
    static const char *MOVE_LIST_CONTROLLER = "moveListController";
    static const char *GAME_MENU_CONTROLLER = "gameMenuController";
    static const char *ALERT_MESSAGE_CONTROLLER = "alertMessageController";
}

namespace QmlObjectName
{
    static const char *STATUS_BAR = "statusBar";
}

namespace NetworkMessageType
{
    static const quint16 MOVE_LIST = 34534;
    static const quint16 MOVE = 6342;
}


#endif //CONSTANTS_H
