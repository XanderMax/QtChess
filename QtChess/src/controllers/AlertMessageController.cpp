#include "AlertMessageController.h"

#include <iostream>

#include "../game/Game.h"


void AlertMessageController::_start()
{

}

void AlertMessageController::_stop()
{

}

AlertMessageController::AlertMessageController(Game &game) : Controller(game)
{

}

AlertMessageController::~AlertMessageController()
{

}

void AlertMessageController::pushStandardOkAlert(const QString &title, const QString &body)
{
    //TODO: Add implementation

    std::cout << __PRETTY_FUNCTION__ << title.toStdString() << " : " << body.toStdString() << std::endl;
}
