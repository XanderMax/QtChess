#include "MoveListController.h"

#include "../game/Game.h"


void MoveListController::_start()
{
    board = new Board(game.getCells());
}

void MoveListController::_stop()
{
}
