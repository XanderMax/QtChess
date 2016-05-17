#include "BoardControllerState.h"

#include "../BoardController.h"
#include "../../game/Game.h"


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
