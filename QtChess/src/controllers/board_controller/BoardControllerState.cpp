#include "BoardControllerState.h"

#include "../BoardController.h"
#include "../StatusBarController.h"
#include "../../game/Game.h"


void BoardControllerState::setStatusBarText(const QString &text)
{
    std::shared_ptr<StatusBarController> statusBarController
            = controller.getGame().getController<StatusBarController>(ControllerName::STATUS_BAR_CONTROLLER);

    if(statusBarController != nullptr)
    {
        statusBarController->setStatusBarText(text);
    }
}

bool BoardControllerState::makeMove(const Move &move)
{
    Game& game = controller.getGame();

    MoveModel *moveModel = game.createMoveModel(move);

    if(_makeMove(move))
    {
        game.addMove(moveModel);

        Board* board = controller.getBoard();

        if(board != nullptr)
        {
            game.switchActiveParty();
            game.setBoardState(board->getBoardState(game.getActiveParty()));
        }

        controller.onMove(move);
        return true;
    }

    return false;
}
