#include "NullBoardControllerState.h"

#include <memory>

#include "../BoardController.h"
#include "../../game/Game.h"

NullBoardControllerState::NullBoardControllerState(BoardController &controller) : BoardControllerState(controller)
{
    setStatusBarText("N/A");
}

NullBoardControllerState::~NullBoardControllerState()
{

}


bool NullBoardControllerState::_makeMove(const Move &move)
{
    return false;
}
