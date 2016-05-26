#include "ClientNetworkGameBoardControllerState.h"

#include <iostream>

#include <QtNetwork>

#include "../BoardController.h"
#include "../MoveListController.h"

#include "../../game/Game.h"

#include "LocalGameBoardControllerState.h"

void ClientNetworkGameBoardControllerState::_onDataReady(quint16 dataType, QDataStream &in)
{
    std::cout << __PRETTY_FUNCTION__ << " " << dataType << std::endl;

    if(dataType == NetworkMessageType::MOVE_LIST)
    {
        quint8 _party;

        quint16 listSize;

        in >> _party;

        party = (PieceParty::Enum) _party;

        in >> listSize;

        QList<Move> moves;

        for(int i = 0; i < listSize; i++)
        {
            quint16 from, to;
            in >> from >> to;

            moves << Move(from, to);
        }

        std::shared_ptr<MoveListController> moveListController
                = controller.getGame().getController<MoveListController>(ControllerName::MOVE_LIST_CONTROLLER);

        if(moveListController != nullptr)
        {
            moveListController->setMoves(moves);

            setStatusBarText(QString("Type: Network; Role: Client; To: %1:%2; Status: Playing; Party: %3")
                             .arg(host).arg(QString::number(getPort())).arg(party == PieceParty::BLACK ? "Black" : "White"));
        }
        else
        {
            controller.continueWithState<LocalGameboardControllerState>();
        }
    }
    else if(dataType == NetworkMessageType::MOVE)
    {
        quint16 blkSize, messageType, to, from;

        //Slip two quints for blocksize and message type
        in >> from >> to;

        std::cout << __PRETTY_FUNCTION__ << " " << from << " " << to << std::endl;

        Move move(from, to);

        onNewMove(move);
    }
}

ClientNetworkGameBoardControllerState::ClientNetworkGameBoardControllerState(BoardController &controller, PieceParty::Enum party, int port, const QString &_host)
    : NetworkGameBoardControllerState(controller, party, port), blockSize(0), host(_host)
{

    setConnection(new QTcpSocket(this));

    if(connection != nullptr)
    {
        connection->abort();

        connection->connectToHost(host, (quint16) getPort());
    }

    setStatusBarText(QString("Type: Network; Role: Client; To: %1:%2; Status: Connecting to server; Party: %3")
                     .arg(host).arg(QString::number(getPort())).arg(party == PieceParty::BLACK ? "Black" : "White"));
}

ClientNetworkGameBoardControllerState::~ClientNetworkGameBoardControllerState()
{

}
