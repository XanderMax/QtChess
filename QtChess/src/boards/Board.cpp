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

    resetToEmpty();

    setCell(_A1_, PieceType::ROOK, PieceParty::BLACK);
    setCell(_H1_, PieceType::ROOK, PieceParty::BLACK);

    setCell(_B1_, PieceType::BISHOP, PieceParty::BLACK);
    setCell(_G1_, PieceType::BISHOP, PieceParty::BLACK);

    setCell(_C1_, PieceType::KNIGHT, PieceParty::BLACK);
    setCell(_F1_, PieceType::KNIGHT, PieceParty::BLACK);

    setCell(_D1_, PieceType::QUEEN, PieceParty::BLACK);
    setCell(_E1_, PieceType::KING, PieceParty::BLACK);

    for(int i = _A2_; i <= _H2_; i++)
    {
        setCell(i, PieceType::PAWN, PieceParty::BLACK);
    }


    setCell(_A8_, PieceType::ROOK, PieceParty::WHITE);
    setCell(_H8_, PieceType::ROOK, PieceParty::WHITE);

    setCell(_B8_, PieceType::BISHOP, PieceParty::WHITE);
    setCell(_G8_, PieceType::BISHOP, PieceParty::WHITE);

    setCell(_C8_, PieceType::KNIGHT, PieceParty::WHITE);
    setCell(_F8_, PieceType::KNIGHT, PieceParty::WHITE);

    setCell(_D8_, PieceType::QUEEN, PieceParty::WHITE);
    setCell(_E8_, PieceType::KING, PieceParty::WHITE);

    for(int i = _A7_; i <= _H7_; i++)
    {
        setCell(_H4_, PieceType::PAWN, PieceParty::WHITE);
    }
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
