#include "SaveLoadController.h"

#include <vector>
#include <fstream>
#include <iostream>

#include <QFile>
#include <QDataStream>

#include "../Constants.h"

#include "../boards/Move.h"

#include "../game/Game.h"

#include "StatusBarController.h"
#include "MoveListController.h"
#include "BoardController.h"

#include "board_controller/NullBoardControllerState.h"

bool SaveLoadController::writeToFile(std::ofstream &out)
{
    return false;
}

void SaveLoadController::_start()
{

}

void SaveLoadController::_stop()
{

}

SaveLoadController::SaveLoadController(Game &game) : Controller(game)
{

}

SaveLoadController::~SaveLoadController()
{

}

bool SaveLoadController::readFromFile(const QUrl &fileName)
{
    std::shared_ptr<StatusBarController> statusBarController
            = getGame().getController<StatusBarController>(ControllerName::STATUS_BAR_CONTROLLER);

    std::shared_ptr<MoveListController> moveListController
            = getGame().getController<MoveListController>(ControllerName::MOVE_LIST_CONTROLLER);

    std::shared_ptr<BoardController> boardController
            = getGame().getController<BoardController>(ControllerName::BOARD_CONTROLLER);

    if(moveListController == nullptr || boardController == nullptr)
    {
        return false;
    }

    if(statusBarController != nullptr)
    {
        statusBarController->setStatusBarText(QString("Loading from file - '%1'").arg(fileName.toLocalFile()));
    }

    QFile file(fileName.toLocalFile());

    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        boardController->startNewWithState<NullBoardControllerState>();

        QDataStream in(&file);

        QList<Move> moves;

        while(!in.atEnd())
        {
            quint8 from, to;

            in >> from >> to;

            Move move(from, to);

            moves << move;
        }

        moveListController->setMoves(moves);


    }
    else
    {
        if(statusBarController != nullptr)
        {
            statusBarController->setStatusBarText(QString("File '%1' doesn't exist or couldn't be openned").arg(fileName.toLocalFile()));
        }
    }

    return false;
}

bool SaveLoadController::writeToFile(const QUrl &fileName)
{
    std::shared_ptr<MoveListController> moveListController
            = getGame().getController<MoveListController>(ControllerName::MOVE_LIST_CONTROLLER);

    if(moveListController == nullptr)
    {
        return false;
    }

    QFile file(fileName.toLocalFile());

    if(!file.exists() && file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);

        const QList<MoveModel*> moves = moveListController->getMoves();

        for(MoveModel* model : moves)
        {
            if(model != nullptr)
            {
                quint8 from = (quint8)model->getMove().getFrom(), to = (quint8)model->getMove().getTo();

                out << from << to;
            }
            else
            {
                break;
            }
        }
    }

    return false;
}
