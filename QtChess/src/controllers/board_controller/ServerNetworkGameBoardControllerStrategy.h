#ifndef SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
#define SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H

#include "NetworkGameBoardControllerStrategy.h"


class ServerNetworkGameBoardControllerState : public NetworkGameBoardControllerState
{
private:
protected:
public:

    ServerNetworkGameBoardControllerState(BoardController& controller, PieceParty::Enum _party, int port);
    ~ServerNetworkGameBoardControllerState();
};







#endif //SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
