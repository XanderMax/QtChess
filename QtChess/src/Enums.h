#ifndef ENUMS_H
#define ENUMS_H

#include <QMetaType>


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

Q_DECLARE_METATYPE(BoardState::Enum)

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

Q_DECLARE_METATYPE(PieceType::Enum)

namespace PartyState
{
    enum Enum : int
    {
        CHECKED = 0,
        REGULAR,
        PATED
    };
}

Q_DECLARE_METATYPE(PartyState::Enum)

namespace PieceParty
{
    enum Enum : int
    {
        BLACK = 0,
        WHITE
    };
}

Q_DECLARE_METATYPE(PieceParty::Enum)

namespace PieceAction
{
    enum Enum : int
    {
        MOVE = 1 << 0,
        ATTACK = 1 << 1
    };

    static const int ALL = MOVE | ATTACK;
}

Q_DECLARE_METATYPE(PieceAction::Enum)

namespace CellOccupyPolicy
{
    enum Enum : int
    {
        EMPTY = 1 << 0,
        HOSTILE = 1 << 1,
        FRIENDLY = 1 << 2
    };

    static const int ALL = EMPTY | HOSTILE | FRIENDLY;
    static const int POSSIBLE = EMPTY | HOSTILE;
}

Q_DECLARE_METATYPE(CellOccupyPolicy::Enum)


#endif //ENUMS_H
