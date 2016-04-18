#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>


class Game;

class Controller : public QObject
{
private:
protected:

    Game& game;

    virtual void _start() = 0;
public:

    Controller(Game& _game) : game(_game){}
    ~Controller() {}

    void start();
};





#endif //CONTROLLER_H
