#ifndef CELL_DATA_OBJECT_H
#define CELL_DATA_OBJECT_H

#include <QObject>

#include <memory>

#include "../states/PieceState.h"
#include "../states/NoneState.h"
#include "../Enums.h"

class CellDataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString state READ getState NOTIFY onStateChanged)

private:

    std::shared_ptr<PieceState> pieceState;

protected:
public:

    CellDataObject() : pieceState(new NoneState()) {}
    CellDataObject(PieceType::Enum type, PieceParty::Enum party, int moves = 0);

    ~CellDataObject() {}

    std::shared_ptr<PieceState> getPieceState() const;

    PieceType::Enum getPieceType() const;
    void setPieceType(PieceType::Enum);

    PieceParty::Enum getPieceParty() const;
    void setPieceParty(PieceParty::Enum);

    void setPiece(PieceType::Enum type, PieceParty::Enum party, int moves = 0);

    bool isMoved() const;
    void move();

    void reset();

    int getMoveCount() const;

    QString getState() const;

signals:

    void onStateChanged(QString _state);

};


#endif //CELL_DATA_OBJECT_H
