#include "Board.h"


void Board::init()
{
    for(int i = 0; i < CELLS; i++)
    {
        cells[i] = std::shared_ptr<CellDataObject>(new CellDataObject());
    }
}

Board::Board()
{
    init();
}

Board::~Board()
{
}

void Board::resetToRegular()
{
    //TODO: implement this function to populate board with regular pieces
}

void Board::resetToEmpty()
{
    for(std::shared_ptr<CellDataObject> cell : cells)
    {
        if(cell != nullptr)
        {
            cell->reset();
        }
        else
        {
            cell.reset(new CellDataObject());
        }
    }
}

std::shared_ptr<PieceState> Board::_getPieceStateAt(int index) const
{
    if(index >= 0 && index < cells.size())
    {
        if(cells[index] != nullptr)
        {
            return cells[index]->getPieceState();
        }
    }

    return nullptr;
}
