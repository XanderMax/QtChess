#include "LocalGameBoardControllerStartegy.h"

#include "../BoardController.h"
#include "../../game/Game.h"

LocalGameboardControllerStrategy::LocalGameboardControllerStrategy(BoardController &controller) :
    BoardControllerStrategy(controller)
{

}


bool LocalGameboardControllerStrategy::_makeMove(const Move &move)
{
    Board* board = controller.getBoard();

    Game& game = controller.getGame();

    if(board != nullptr)
    {
        if(board->getPiecePartyAt(move.getFrom()) == game.getActiveParty()
                && board->getPieceTypeAt(move.getFrom()) != PieceType::NONE)
        {
            if(board->movePiece(move))
            {
                return true;
            }
        }
    }

    return false;
}
