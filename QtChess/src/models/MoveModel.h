#ifndef MOVE_MODEL_H
#define MOVE_MODEL_H

#include <QObject>

#include "../boards/Move.h"
#include "../models/CellDataObject.h"

class MoveModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int fromIndex READ getFrom NOTIFY onFromIndexChanged)
    Q_PROPERTY(int toIndex READ getTo NOTIFY onToIndexChanged)

    Q_PROPERTY(QString stateFrom READ getStateFrom NOTIFY onFromStateChanged)
    Q_PROPERTY(QString stateTo READ getStateTo NOTIFY onToStateChanged)
private:

    Move move;

    int getFrom() const;
    int getTo() const;

    PieceState* fromState;
    PieceState* toState;

    QString sStateFrom;
    QString sStateTo;

protected:
public:

    MoveModel(const Move& _move, const QList<CellDataObject*> list);
    ~MoveModel();

    const Move& getMove() const;

    QString getStateFrom() const;
    QString getStateTo() const;

signals:

    void onFromIndexChanged(int);
    void onToIndexChanged(int);

    void onFromStateChanged(QString);
    void onToStateChanged(QString);

};


#endif //MOVE_MODEL_H
