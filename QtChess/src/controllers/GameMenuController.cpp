#include "GameMenuController.h"

#include "../game/Game.h"

#include "BoardController.h"

#include "board_controller/LocalGameBoardControllerState.h"
#include "board_controller/PlayerMockBoardControllerState.h"

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
        controller->startNewWithState(new LocalGameboardControllerState(*controller));
    }
}

void GameMenuController::onNewLocalGameWithMockPlayer(PieceParty::Enum party)
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->startNewWithState(new PlayerMockBoardControllerState(*controller, PieceParty::getOpposite(party)));
    }
}

void GameMenuController::onNewNetworkGameAsServer(PieceParty::Enum party, int port)
{
    //TODO: Add actual implementation once it is available
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->startNewWithState(new PlayerMockBoardControllerState(*controller, PieceParty::getOpposite(party)));
    }
}

void GameMenuController::onNewNetworkGameAsClient(PieceParty::Enum party, int port, const QString &host)
{
    //TODO: Add actual implementation once it is available
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->startNewWithState(new PlayerMockBoardControllerState(*controller, PieceParty::getOpposite(party)));
    }
}

void GameMenuController::onContinueLocalGame()
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState(new LocalGameboardControllerState(*controller));
    }
}

void GameMenuController::onContinueLocalGameWithMockPlayer(PieceParty::Enum party)
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState(new PlayerMockBoardControllerState(*controller, PieceParty::getOpposite(party)));
    }
}

void GameMenuController::onContinueNetworkGameAsServer(PieceParty::Enum party, int port)
{
    //TODO: Add actual implementation once it is available
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState(new PlayerMockBoardControllerState(*controller, PieceParty::getOpposite(party)));
    }
}

void GameMenuController::onContinueNetworkGameAsClient(PieceParty::Enum party, int port, const QString &host)
{
    //TODO: Add actual implementation once it is available
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        controller->continueWithState(new PlayerMockBoardControllerState(*controller, PieceParty::getOpposite(party)));
    }
}

GameMenuController::GameMenuController(Game &game) : Controller(game)
{

}

GameMenuController::~GameMenuController()
{

}
