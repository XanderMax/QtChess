#include "ServerNetworkGameBoardControllerStrategy.h"

#include "../BoardController.h"

ServerNetworkGameBoardControllerState::ServerNetworkGameBoardControllerState(BoardController &controller, PieceParty::Enum _party, int port) :
    NetworkGameBoardControllerState(controller, port)
{

}

ServerNetworkGameBoardControllerState::~ServerNetworkGameBoardControllerState()
{

}
