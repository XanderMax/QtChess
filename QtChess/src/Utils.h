#ifndef UTILS_H
#define UTILS_H

#include <QList>

#include "models/CellDataObject.h"

#define _KING 'c'
#define _PAWN 'p'
#define _ROOK 'r'
#define _BISHOP 'b'
#define _KNIGHT 'k'
#define _QUEEN 'q'
#define _NONE 'n'

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

QList<CellDataObject*> getCellsFromString(const QString& string);



#endif //UTILS_H
