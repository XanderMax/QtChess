#include "NetworkGameBoardControllerStrategy.h"
#include "../BoardController.h"
#include "../../game/Game.h"

NetworkGameBoardControllerStrategy::NetworkGameBoardControllerStrategy(BoardController &controller, int _port) :
    port(_port), BoardControllerStrategy(controller)
{

}

NetworkGameBoardControllerStrategy::~NetworkGameBoardControllerStrategy()
{

}

int NetworkGameBoardControllerStrategy::getPort() const
{
    return port;
}


bool NetworkGameBoardControllerStrategy::_makeMove(const Move &move)
{
    if(controller.getGame().getActiveParty() == party)
    {
        return __makeMove(move);
    }

    return false;
}

bool NetworkGameBoardControllerStrategy::canMove(const Move &move) const
{
    PieceParty::Enum activeParty = controller.getGame().getActiveParty();

    return activeParty != party;
}
