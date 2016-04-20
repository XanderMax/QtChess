#ifndef MOVE_H
#define MOVE_H

#include <QMetaType>

#include <QObject>

class Move
{
private:

    int from;
    int to;

protected:
public:

    Move(int _from, int _to);

    Move(const Move& move):from(move.getFrom()), to(move.getTo()){}

    ~Move() {}


    int getFrom() const;
    int getTo() const;


};


#endif //MOVE_H
