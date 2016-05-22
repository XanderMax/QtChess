#ifndef SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
#define SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H

#include <QObject>
#include <QTcpServer>

#include "NetworkGameBoardControllerState.h"


class ServerNetworkGameBoardControllerState : public NetworkGameBoardControllerState
{

    Q_OBJECT

private:

    QString ipAddress;

    void initTcpServer();
    void disposeTcpServer();

private slots:

    void sessionOpenned();
    void onConnected();
    void clientDisconnected();
    void onError(QAbstractSocket::SocketError);

protected:

    QTcpServer* tcpServer;

    void _onDataReady(quint16 type, QDataStream& in);

public:

    ServerNetworkGameBoardControllerState(BoardController& controller, PieceParty::Enum _party, int port);
    ServerNetworkGameBoardControllerState(const ServerNetworkGameBoardControllerState&);
    ~ServerNetworkGameBoardControllerState();
};







#endif //SERVER_NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
