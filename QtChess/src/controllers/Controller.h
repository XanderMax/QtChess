#ifndef CONTROLLER_H
#define CONTROLLER_H


class Game;

class Controller
{
private:
protected:

    const Game& game;
public:

    Controller(const Game& _game) : game(_game){}
    ~Controller() {}
};





#endif //CONTROLLER_H
