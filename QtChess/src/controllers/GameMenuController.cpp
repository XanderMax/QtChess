#include "GameMenuController.h"

#include "../game/Game.h"

#include "BoardController.h"

#include "board_controller/LocalGameBoardControllerState.h"
#include "board_controller/PlayerMockBoardControllerState.h"
#include "board_controller/ServerNetworkGameBoardControllerState.h"
#include "board_controller/ClientNetworkGameBoardControllerState.h"

void GameMenuController::_start()
{

}

void GameMenuController::_stop()
{

}

void GameMenuController::onNewLocalGame()
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->startNewWithState<LocalGameboardControllerState>();
    }
}

void GameMenuController::onNewLocalGameWithMockPlayer(PieceParty::Enum party)
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->startNewWithState<PlayerMockBoardControllerState>(PieceParty::getOpposite(party));
    }
}

void GameMenuController::onNewNetworkGameAsServer(PieceParty::Enum party, int port)
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->startNewWithState<ServerNetworkGameBoardControllerState>(party, port);
    }
}

void GameMenuController::onNewNetworkGameAsClient(PieceParty::Enum party, int port, const QString &host)
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->startNewWithState<ClientNetworkGameBoardControllerState>(party, port, host);
    }
}

void GameMenuController::onContinueLocalGame()
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState<LocalGameboardControllerState>();
    }
}

void GameMenuController::onContinueLocalGameWithMockPlayer(PieceParty::Enum party)
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState<PlayerMockBoardControllerState>(PieceParty::getOpposite(party));
    }
}

void GameMenuController::onContinueNetworkGameAsServer(PieceParty::Enum party, int port)
{
    //TODO: Add actual implementation once it is available
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState<ServerNetworkGameBoardControllerState>(party, port);
    }
}

void GameMenuController::onContinueNetworkGameAsClient(PieceParty::Enum party, int port, const QString &host)
{
    //TODO: Add actual implementation once it is available
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState<ClientNetworkGameBoardControllerState>(party, port, host);
    }
}

GameMenuController::GameMenuController(Game &game) : Controller(game)
{

}

GameMenuController::~GameMenuController()
{

}
