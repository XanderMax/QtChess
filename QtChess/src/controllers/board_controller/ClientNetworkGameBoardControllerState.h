#ifndef CLIENT_NETWORK_GAME_BOARD_CONTROLLER_STATE_H
#define CLIENT_NETWORK_GAME_BOARD_CONTROLLER_STATE_H

#include <QTcpSocket>

#include "NetworkGameBoardControllerState.h"

class ClientNetworkGameBoardControllerState : public NetworkGameBoardControllerState
{

    Q_OBJECT

private:
    QString host;

    quint16 blockSize;

protected:

    void _onDataReady(quint16 dataType, QDataStream& in);

public:

    ClientNetworkGameBoardControllerState(BoardController& controller, PieceParty::Enum party, int port, const QString& host);
    ~ClientNetworkGameBoardControllerState();
};



#endif //CLIENT_NETWORK_GAME_BOARD_CONTROLLER_STATE_H
