#include "ServerNetworkGameBoardControllerState.h"

#include <iostream>

#include <QtNetwork>

#include "../BoardController.h"
#include "../AlertMessageController.h"

#include "LocalGameBoardControllerState.h"
#include "../MoveListController.h"

#include "../../models/MoveModel.h"

#include "../../game/Game.h"

void ServerNetworkGameBoardControllerState::initTcpServer()
{
    tcpServer = new QTcpServer(this);

    std::shared_ptr<AlertMessageController> alertMessageController
            = controller.getGame().getController<AlertMessageController>(ControllerName::ALERT_MESSAGE_CONTROLLER);

    if(!tcpServer->listen(QHostAddress::Any, (qint16) getPort()))
    {
        //Display an alert telling user that server couldn't be started
        if(alertMessageController != nullptr)
        {
            alertMessageController->pushStandardOkAlert("Couldn't start the server.", "Continue local game");
        }

        controller.continueWithState<LocalGameboardControllerState>();

        return;
    }

    ipAddress = "";
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        if(ipAddressesList[i] != QHostAddress::LocalHost && ipAddressesList[i].toIPv4Address())
        {
            ipAddress = ipAddressesList[i].toString();
        }
    }

    if(ipAddress.isEmpty())
    {
        ipAddress = (QHostAddress(QHostAddress::LocalHost)).toString();
    }

    //Display an alert telling user that server was started and showing user the address to which client should connect
    if(alertMessageController != nullptr)
    {
        alertMessageController->pushStandardOkAlert("Server started on:", ipAddress.append(":").append(QString::number(getPort())));
    }

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onConnected()));

    setStatusBarText(QString("Type: Network; Role: Server; At: %1; Status: Listening/Waitng client; Party: %2")
                     .arg(ipAddress).arg(party == PieceParty::BLACK ? "Black" : "White"));

}

void ServerNetworkGameBoardControllerState::disposeTcpServer()
{
    if(tcpServer != nullptr)
    {
        tcpServer->close();
    }
}

void ServerNetworkGameBoardControllerState::sessionOpenned()
{

}

void ServerNetworkGameBoardControllerState::onConnected()
{
    std::cout << __PRETTY_FUNCTION__ <<std::endl;

    //When client connects server will send all moves performed since new game

    std::shared_ptr<MoveListController> moveListController
            = controller.getGame().getController<MoveListController>(ControllerName::MOVE_LIST_CONTROLLER);

    if(moveListController != nullptr)
    {
        const QList<MoveModel *> moves = moveListController->getMoves();

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);

        //Reserving quint16 for the size of block
        out << (quint16) 0;

        //settings message type
        out << NetworkMessageType::MOVE_LIST;

        out << (quint8) PieceParty::getOpposite(party);

        //Reserving for moves' count
        out << (quint16) moves.size();

        //adding move items
        for(MoveModel *moveModel : moves)
        {
            if(moveModel != nullptr)
            {
                out << (quint16) moveModel->getMove().getFrom();
                out << (quint16) moveModel->getMove().getTo();
            }
            else
            {
                out << (quint16) 0;
                out << (quint16) 0;
            }
        }

        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));

        setConnection(tcpServer->nextPendingConnection());

        if(connection != nullptr)
        {
            connect(connection, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));

            connect(connection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

            connection->write(block);
        }

        setStatusBarText(QString("Type: Network; Role: Server; At: %1; Status: Client connected/Playing; Party: %2")
                         .arg(ipAddress).arg(party == PieceParty::BLACK ? "Black" : "White"));
    }
    else
    {
        //TODO: show alert here

        controller.continueWithState<LocalGameboardControllerState>();
    }
}

void ServerNetworkGameBoardControllerState::clientDisconnected()
{
    //TODO: add implementation here

    controller.continueWithState<LocalGameboardControllerState>();
}

void ServerNetworkGameBoardControllerState::onError(QAbstractSocket::SocketError)
{
    controller.continueWithState<LocalGameboardControllerState>();
}

void ServerNetworkGameBoardControllerState::_onDataReady(quint16 dataType, QDataStream &in)
{
    if(dataType == NetworkMessageType::MOVE)
    {
        quint16 blkSize, messageType, to, from;

        in >> from >> to;

        std::cout << __PRETTY_FUNCTION__ << " " << from << " " << to << std::endl;

        Move move(from, to);

        onNewMove(move);
    }
}

ServerNetworkGameBoardControllerState::ServerNetworkGameBoardControllerState(BoardController &controller, PieceParty::Enum _party, int port) :
    NetworkGameBoardControllerState(controller, _party, port), tcpServer(nullptr)
{
    initTcpServer();
}

ServerNetworkGameBoardControllerState::ServerNetworkGameBoardControllerState(const ServerNetworkGameBoardControllerState &state)
    :NetworkGameBoardControllerState(state.controller, state.getParty(), state.getPort()), tcpServer(nullptr)
{
    initTcpServer();
}

ServerNetworkGameBoardControllerState::~ServerNetworkGameBoardControllerState()
{
    disposeTcpServer();
}
