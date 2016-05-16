#include "NetworkGameBoardControllerStrategy.h"
#include "../BoardController.h"
#include "../../game/Game.h"

NetworkGameBoardControllerState::NetworkGameBoardControllerState(BoardController &controller, int _port) :
    port(_port), BoardControllerState(controller)
{

}

NetworkGameBoardControllerState::~NetworkGameBoardControllerState()
{

}

int NetworkGameBoardControllerState::getPort() const
{
    return port;
}


bool NetworkGameBoardControllerState::_makeMove(const Move &move)
{
    if(controller.getGame().getActiveParty() == party)
    {
        return __makeMove(move);
    }

    return false;
}

bool NetworkGameBoardControllerState::canMove(const Move &move) const
{
    PieceParty::Enum activeParty = controller.getGame().getActiveParty();

    return activeParty != party;
}
