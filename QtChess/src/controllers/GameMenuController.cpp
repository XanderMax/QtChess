#include "GameMenuController.h"

#include "../game/Game.h"

#include "BoardController.h"

#include "board_controller/LocalGameBoardControllerStartegy.h"
#include "board_controller/PlayerMockBoardControllerStrategy.h"

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

void GameMenuController::onNewLocalGameWithMockPlayer()
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        //TODO: Add to logic to be able to select party from GUI
        controller->startNewWithState(new PlayerMockBoardControllerState(*controller, PieceParty::BLACK));
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

void GameMenuController::onContinueLocalGameWithMockPlayer()
{
    std::shared_ptr<BoardController> controller = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(controller != nullptr)
    {
        //TODO: Add to logic to be able to select party from GUI
        controller->continueWithState(new PlayerMockBoardControllerState(*controller, PieceParty::BLACK));
    }
}

GameMenuController::GameMenuController(Game &game) : Controller(game)
{

}

GameMenuController::~GameMenuController()
{

}
