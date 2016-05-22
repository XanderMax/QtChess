#include "MoveListController.h"

#include <iostream>

#include "../game/Game.h"

#include "../Utils.h"

#include "BoardController.h"


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

void MoveListController::startFrom(int index)
{
    const QList<MoveModel*> moveModels = game.getMoves();
    if(index >= 0 && index < moveModels.size())
    {
        if(board != nullptr)
        {
            if(index == 0)
            {
                game.updateBoardCells(BoardConfigurationsString::REGULAR_BOARD());

                game.setActiveParty(PieceParty::WHITE);
                game.setBoardState(BoardState::REGULAR);

                return;
            }

            QList<Move> moves;

            for(MoveModel* model : moveModels.mid(0, index + 1))
            {
                if(model != nullptr)
                {
                    moves << model->getMove();
                }
            }

            for(Move move : moves)
            {
                if(!board->movePiece(move))
                {
                    break;
                }

                game.switchActiveParty();
                game.setBoardState(board->getBoardState(game.getActiveParty()));
            }

        }
    }
}

const QList<MoveModel *> &MoveListController::getMoves() const
{
    return game.getMoves();
}

void MoveListController::setMoves(const QList<Move> &moves)
{
    std::shared_ptr<BoardController> boardController = game.getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(boardController != nullptr)
    {
        boardController->resetBoardToNewGame();
    }

    if(board != nullptr)
    {
        for(Move move : moves)
        {
            MoveModel* moveModel = game.createMoveModel(move);

            if(!board->movePiece(move))
            {
                break;
            }

            game.switchActiveParty();
            game.setBoardState(board->getBoardState(game.getActiveParty()));

            game.addMove(moveModel);
        }
    }


}
