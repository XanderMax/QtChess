#include "NetworkGameBoardControllerState.h"

#include <iostream>

#include <QDataStream>
#include <QByteArray>

#include "../BoardController.h"
#include "../../game/Game.h"

#include "LocalGameBoardControllerState.h"



NetworkGameBoardControllerState::NetworkGameBoardControllerState(BoardController &controller, PieceParty::Enum _party, int _port) :
    port(_port), blockSize(0), connection(nullptr), party(_party), BoardControllerState(controller)
{

}

NetworkGameBoardControllerState::~NetworkGameBoardControllerState()
{
    if(connection != nullptr)
    {
        connection->disconnectFromHost();

        disconnect(connection, SIGNAL(readyRead()), this, SLOT(onNewMessage()));
        disconnect(connection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

        delete connection;
        connection = nullptr;
    }
}

int NetworkGameBoardControllerState::getPort() const
{
    return port;
}

PieceParty::Enum NetworkGameBoardControllerState::getParty() const
{
    return party;
}


void NetworkGameBoardControllerState::onNewMessage()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if(connection != nullptr)
    {

        QDataStream in(connection);

        in.setVersion(QDataStream::Qt_4_0);

        if (blockSize == 0) {
            if (connection->bytesAvailable() < (int)sizeof(quint16))
            {
                return;
            }

            in >> blockSize;
        }

        std::cout << __PRETTY_FUNCTION__ << " " << blockSize << std::endl;

        if (connection->bytesAvailable() < blockSize)
        {
            return;
        }


        quint16 messageType;

        in >> messageType;

        std::cout << __PRETTY_FUNCTION__ << " " << messageType << std::endl;

        onDataReady(messageType, in);

        blockSize = 0;
    }
    else
    {
        //TODO: display some alert here
    }
}

void NetworkGameBoardControllerState::onError(QAbstractSocket::SocketError error)
{
    onConnectionError(error);
}

bool NetworkGameBoardControllerState::_makeMove(const Move &move)
{
    if(controller.getGame().getActiveParty() == party)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);

        out << (quint16) 0;
        out << NetworkMessageType::MOVE;
        out << (quint16) move.getFrom();
        out << (quint16) move.getTo();

        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));


        bool moved = false;

        Board* board = controller.getBoard();

        Game& game = controller.getGame();

        PieceParty::Enum activeParty = game.getActiveParty();

        if(board != nullptr)
        {
            if(board->getPiecePartyAt(move.getFrom()) == activeParty
                    && board->getPieceTypeAt(move.getFrom()) != PieceType::NONE)
            {
                if(board->movePiece(move))
                {
                    moved = true;
                }
            }
        }

        if(moved)
        {
            if(connection == nullptr || connection->write(block) < 0)
            {
                //TODO: Add showing alert here
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    return false;
}

void NetworkGameBoardControllerState::onDataReady(quint16 dataType, QDataStream &in)
{
    std::cout << __PRETTY_FUNCTION__ << " " << dataType << std::endl;

    _onDataReady(dataType, in);
}

void NetworkGameBoardControllerState::_onDataReady(quint16 dataType, QDataStream &in)
{
    //DO NOTHING HERE. LET DERIVED CLASS DECIDE WHAT SHOULD BE DONE HERE
}

void NetworkGameBoardControllerState::onConnectionCreated()
{
    if(connection != nullptr)
    {
        connect(connection, SIGNAL(readyRead()), SLOT(onNewMessage()));

        connect(connection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

        _onConnectionCreated();
    }
}

void NetworkGameBoardControllerState::_onConnectionCreated()
{
    //DO NOTHING HERE. LET DERIVED CLASS DECIDE WHAT SHOULD BE DONE HERE
}

void NetworkGameBoardControllerState::onNewMove(const Move &move)
{
    std::cout << __PRETTY_FUNCTION__ << " " << move.getFrom() << " " << move.getTo() << std::endl;

    Game& game = controller.getGame();

    MoveModel* moveModel = game.createMoveModel(move);

    Board* board = controller.getBoard();

    PieceParty::Enum activeParty = game.getActiveParty();

    if(board != nullptr)
    {
        if(board->getPiecePartyAt(move.getFrom()) == activeParty
                && board->getPieceTypeAt(move.getFrom()) != PieceType::NONE)
        {
            if(!board->movePiece(move))
            {
                //TODO: Add alert here that corrupted data has been received from server
                controller.continueWithState<LocalGameboardControllerState>();
            }
        }

        game.switchActiveParty();
        game.setBoardState(board->getBoardState(game.getActiveParty()));
    }

    game.addMove(moveModel);

    _onNewMove(move);
}

void NetworkGameBoardControllerState::_onNewMove(const Move &move)
{
    //DO NOTHING HERE. LET DERIVED CLASS DECIDE WHAT SHOULD BE DONE HERE
}

void NetworkGameBoardControllerState::onConnectionError(QAbstractSocket::SocketError error)
{

    std::cout << __PRETTY_FUNCTION__ << " " << (int)error << std::endl;
    //TODO: Show alert here
    controller.continueWithState<LocalGameboardControllerState>();

    _onConnectionError(error);
}

void NetworkGameBoardControllerState::_onConnectionError(QAbstractSocket::SocketError)
{
    //DO NOTHING HERE. LET DERIVED CLASS DECIDE WHAT SHOULD BE DONE HERE
}


bool NetworkGameBoardControllerState::canMove(const Move &move) const
{
    PieceParty::Enum activeParty = controller.getGame().getActiveParty();

    return activeParty == party;
}

void NetworkGameBoardControllerState::setConnection(QTcpSocket *_connection)
{
    if(connection == nullptr && _connection != nullptr)
    {
        connection = _connection;

        onConnectionCreated();
    }
}
