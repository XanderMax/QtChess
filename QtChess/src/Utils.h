#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include <QList>

#include "models/CellDataObject.h"

#define _KING 'c'
#define _PAWN 'p'
#define _ROOK 'r'
#define _BISHOP 'b'
#define _KNIGHT 'k'
#define _QUEEN 'q'
#define _NONE 'n'
#define _DELIMITER '|'

namespace BoardConfigurationsString
{
    static const QString REGULAR_BOARD() {return "RKBQCBKR"
                                                 "PPPPPPPP"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "pppppppp"
                                                 "rkbqcbkr";}

    static const QString EMPTY_BOARD() {return   "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn"
                                                 "nnnnnnnn";}
}

template<class Type = CellDataObject>
QList<Type *> getCellsFromString(const QString &string)
{
    QList<Type*> list;

    int i = 0;
    while(list.size() < 64)
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
        else if(c == _DELIMITER)
        {
            i++;
            continue;
        }
        else
        {
            type = PieceType::NONE;
        }

        Type *element = dynamic_cast<Type*>(new CellDataObject(type, (piece.isLower() ? PieceParty::WHITE : PieceParty::BLACK)));
        list << element;

        i++;
    }

    return list;
}

template <typename TObjectType>
void qObjectSafeDelete(TObjectType *object)
{
    std::cout << "qObjectSafeDelete" << std::endl;
    if(object != nullptr)
    {
        std::cout << typeid(object).name() << std::endl;
        QObject* qObject = dynamic_cast<QObject*>(object);

        if(qObject != nullptr)
        {
            std::cout << "QObject*" << std::endl;
            qObject->deleteLater();
        }
        else
        {
            std::cout << "!QObject*" << std::endl;
            delete object;
        }
    }
}



#endif //UTILS_H
