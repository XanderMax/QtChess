#include "ServerNetworkGameBoardControllerStrategy.h"

#include "../BoardController.h"

ServerNetworkGameBoardControllerStrategy::ServerNetworkGameBoardControllerStrategy(BoardController &controller, PieceParty::Enum _party, int port) :
    NetworkGameBoardControllerStrategy(controller, port)
{

}

ServerNetworkGameBoardControllerStrategy::~ServerNetworkGameBoardControllerStrategy()
{

}
