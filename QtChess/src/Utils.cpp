#include "Utils.h"

QList<CellDataObject *> getCellsFromString(const QString &string)
{
    QList<CellDataObject*> list;

    for(int i = 0; i < CELLS; i++)
    {
        QChar piece = i < string.length() ? string.at(i) : _NONE;

        QChar c = piece.toLower();

        PieceType::Enum type;

        if(c == _KING)
        {
            type = PieceType::KING;
        }
        else if(c == _PAWN)
        {
            type = PieceType::PAWN;
        }
        else if(c == _ROOK)
        {
            type = PieceType::ROOK;
        }
        else if(c == _BISHOP)
        {
            type = PieceType::BISHOP;
        }
        else if(c == _KNIGHT)
        {
            type = PieceType::KNIGHT;
        }
        else if(c == _QUEEN)
        {
            type = PieceType::QUEEN;
        }
        else if(c == _NONE)
        {
            type = PieceType::NONE;
        }
        else
        {
            type = PieceType::NONE;
        }

        list << (new CellDataObject(type, (piece.isLower() ? PieceParty::WHITE : PieceParty::BLACK)));
    }

    return list;
}
