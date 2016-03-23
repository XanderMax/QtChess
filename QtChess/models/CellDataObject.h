#ifndef CELL_DATA_OBJECT_H
#define CELL_DATA_OBJECT_H

#include <QObject>

#include <memory>

#include "states/PieceState.h"
#include "states/NoneState.h"
#include "Enums.h"

class CellDataObject : public QObject
{
    Q_OBJECT

private:

    std::shared_ptr<PieceState> pieceState;
protected:
public:

    CellDataObject() : pieceState(new NoneState()) {}
    ~CellDataObject() {}

    std::shared_ptr<PieceState> getPieceState() const;

    PieceType::Enum getPieceType() const;
    void setPieceType(PieceType::Enum);

    PieceParty::Enum getPieceParty() const;
    void setPieceParty(PieceParty::Enum);

    bool isMoved() const;
    void move();



};


#endif //CELL_DATA_OBJECT_H
