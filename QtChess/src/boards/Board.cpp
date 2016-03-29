#include "Board.h"


void Board::init()
{
    for(int i = 0; i < CELLS; i++)
    {
        cells[i] = std::shared_ptr<CellDataObject>(new CellDataObject());
    }
}

void Board::setCell(int index, PieceType::Enum type, PieceParty::Enum party)
{
    if(index >= 0 && index < cells.size())
    {
        if(cells[index] == nullptr)
        {
            cells[index] = std::shared_ptr<CellDataObject>(new CellDataObject());
        }

        cells[index]->setPieceType(type);
        cells[index]->setPieceParty(party);
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
    setCell(_A1_, PieceType::ROOK, PieceParty::BLACK);
    setCell(_A8_, PieceType::ROOK, PieceParty::BLACK);

    setCell(_H1_, PieceType::ROOK, PieceParty::WHITE);
    setCell(_H8_, PieceType::ROOK, PieceParty::WHITE);
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
