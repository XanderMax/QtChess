#include "SaveLoadController.h"

#include <vector>
#include <fstream>
#include <iostream>

#include "../Constants.h"

#include "../boards/Move.h"

#include "../game/Game.h"

bool SaveLoadController::readFromFile(std::ifstream &in)
{
    std::vector<Move*> moves;

    while(!in.eof())
    {
        int from = -1, to = -1;

        in >> from >> to;

        std::cout << "MOVE: " << from << " " << to << std::endl;

        if(from >= 0 && from < CELLS && to >=0 && to < CELLS)
        {
            Move move(from, to);

            moves.push_back(&move);
        }
        else
        {
            return false;
        }
    }

    game.emptyMoves();

    for(Move* move : moves)
    {
        if(move != nullptr)
        {
            game.addMove(*move);
        }
        else
        {
            return true;
        }
    }

    return true;
}

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

bool SaveLoadController::readFromFile(const QString &fileName)
{
    std::ifstream in(fileName.toStdString().c_str());

    if(in.is_open())
    {
        return readFromFile(in);
    }

    return false;
}

bool SaveLoadController::writeToFile(const QString &fileName)
{
    return false;
}
