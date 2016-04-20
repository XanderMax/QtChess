#include "MoveListController.h"

#include <iostream>

#include "../game/Game.h"

#include "../Utils.h"


void MoveListController::_start()
{
    board = new Board(game.getCells());
}

void MoveListController::_stop()
{
}

void MoveListController::restoreToMove(int index)
{
    const QList<MoveModel*> moves = game.getMoves();

    if(index < 0)
    {
        game.updateBoardCells(BoardConfigurationsString::REGULAR_BOARD());
        game.setActiveParty(PieceParty::WHITE);
        game.setBoardState(BoardState::REGULAR);
    }
    else
    {
        if(board != nullptr)
        {
            game.updateBoardCells(BoardConfigurationsString::REGULAR_BOARD());

            game.setActiveParty(PieceParty::WHITE);
            game.setBoardState(BoardState::REGULAR);

            for(int i = 0; i <= index; i++)
            {
                MoveModel* moveModel = moves[i];

                if(moveModel != nullptr)
                {
                    const Move& move = moveModel->getMove();

                    if(!board->movePiece(move))
                    {
                        break;
                    }

                    game.switchActiveParty();
                    game.setBoardState(board->getBoardState(game.getActiveParty()));
                }
                else
                {
                    break;
                }
            }
        }
    }
}
