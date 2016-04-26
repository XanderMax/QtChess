#ifndef SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
#define SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H

#include "NetworkGameBoardControllerStrategy.h"


class ServerNetworkGameBoardControllerStrategy : public NetworkGameBoardControllerStrategy
{
private:
protected:
public:

    ServerNetworkGameBoardControllerStrategy(BoardController& controller, PieceParty::Enum _party, int port);
    ~ServerNetworkGameBoardControllerStrategy();
};







#endif //SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
