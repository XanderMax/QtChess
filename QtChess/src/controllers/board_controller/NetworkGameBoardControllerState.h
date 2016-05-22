#ifndef NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
#define NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H

#include <QTcpSocket>

#include "BoardControllerState.h"
#include "../../Enums.h"


class NetworkGameBoardControllerState : public QObject, public BoardControllerState
{

    Q_OBJECT

private:
    int port;

    quint16 blockSize;

private slots:

    void onNewMessage();

    void onError(QAbstractSocket::SocketError);

protected:

    //Represents the party which this client plays for
    PieceParty::Enum party;

    QTcpSocket *connection;

    bool _makeMove(const Move &move);

    void onDataReady(quint16 dataType, QDataStream& in);
    virtual void _onDataReady(quint16 dataType, QDataStream& in);

    void onConnectionCreated();
    virtual void _onConnectionCreated();

    void onNewMove(const Move& move);
    virtual void _onNewMove(const Move& move);

    void onConnectionError(QAbstractSocket::SocketError);
    virtual void _onConnectionError(QAbstractSocket::SocketError);

    void setConnection(QTcpSocket* _connection);

public:

    NetworkGameBoardControllerState(BoardController& controller, PieceParty::Enum _party, int _port);
    virtual ~NetworkGameBoardControllerState();

    bool canMove(const Move &move) const;

    int getPort() const;

    PieceParty::Enum getParty() const;
};





#endif //NETWORK_GAME_BOARD_CONTROLLER_STRATEGY_H
