#ifndef ENUMS_H
#define ENUMS_H


namespace BoardState
{
    enum Enum : int
    {
        REGULAR = 0,
        CHECKED,
        MATED,
        PATED
    };
}

namespace PieceType
{
    enum Enum : int
    {
        NONE = 0,
        PAWN,
        KNIGHT,
        BISHOP,
        ROOK,
        QUEEN,
        KING
    };
}

namespace PartyState
{
    enum Enum : int
    {
        CHECKED = 0,
        REGULAR,
        PATED
    };
}

namespace PieceParty
{
    enum Enum : int
    {
        BLACK = 0,
        WHITE
    };
}

namespace PieceAction
{
    enum Enum
    {
        MOVE = 1 << 0,
        ATTACK = 1 << 1
    };

    static const int ALL = MOVE | ATTACK;
}

namespace CellOccupyPolicy
{
    enum Enum
    {
        EMPTY = 1 << 0,
        HOSTILE = 1 << 1,
        FRIENDLY = 1 << 2
    };

    static const int ALL = EMPTY | HOSTILE | FRIENDLY;
    static const int POSSIBLE = EMPTY | HOSTILE;
}


#endif //ENUMS_H
