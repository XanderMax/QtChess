#ifndef MOVE_H
#define MOVE_H


class Move
{
private:

    int from;
    int to;

protected:
public:

    Move(int _from, int _to);

    ~Move() {}


    int getFrom() const;
    int getTo() const;


};




#endif //MOVE_H
