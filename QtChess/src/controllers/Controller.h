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
    virtual void _stop() = 0;

    void stop();
public:

    Controller(Game& _game) : game(_game){}
    virtual ~Controller() {stop();}

    void start();

    Game& getGame() const;

};





#endif //CONTROLLER_H
