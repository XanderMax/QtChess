#ifndef MOVE_H
#define MOVE_H

#include <QMetaType>

#include <QObject>

class Move
{

    Q_GADGET
    Q_PROPERTY(int fromIndex READ getFrom)
    Q_PROPERTY(int toIndex READ getTo)

private:

    int from;
    int to;

protected:
public:

    Move(int _from, int _to);
    Move():from(0), to(0){}

    Move(const Move& move):from(move.getFrom()), to(move.getTo()){}

    ~Move() {}


    int getFrom() const;
    int getTo() const;


};

Q_DECLARE_METATYPE(Move)




#endif //MOVE_H
