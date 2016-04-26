#ifndef NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
#define NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H

#include "BoardControllerStrategy.h"
#include "../../Enums.h"


class NetworkGameBoardControllerStrategy : public BoardControllerStrategy
{
private:
    int port;
protected:

    //Represents the party which this client plays for
    PieceParty::Enum party;

    bool _makeMove(const Move &move);

    virtual bool __makeMove(const Move &move) = 0;

    bool canMove(const Move &move) const;
public:

    NetworkGameBoardControllerStrategy(BoardController& controller, int _port);
    virtual ~NetworkGameBoardControllerStrategy();

    int getPort() const;
};





#endif //NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
