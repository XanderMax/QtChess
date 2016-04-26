#include "Controller.h"

void Controller::start()
{
    _start();
}

Game &Controller::getGame() const
{
    return game;
}

void Controller::stop()
{
    _stop();
}
