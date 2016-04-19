#include "Board.h"

void Board::setCell(int index, PieceType::Enum type, PieceParty::Enum party)
{
    if(index >= 0 && index << CELLS)
    {
        CellDataObject* cell = cells[index];

        if(cell != nullptr)
        {
            cell->setPiece(type, party, 0);
        }
    }
}

CellDataObject *Board::getCellDataObject(int index)
{
    if(index >= 0 && index < cells.size())
    {
        return cells[index];
    }

    return nullptr;
}

Board::Board(const QList<CellDataObject*>& _cells, const MovePolicy *policy) : BoardBase(policy), cells(_cells)
{
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
        setCell(i, PieceType::PAWN, PieceParty::WHITE);
    }
}

void Board::resetToEmpty()
{
    for(CellDataObject* cell : cells)
    {
        if(cell != nullptr)
        {
            cell->reset();
        }
    }
}

bool Board::movePiece(const Move &move)
{
    bool movePosible = isMovePossible(move);

    if(movePosible)
    {
        CellDataObject* fromCell = getCellDataObject(move.getFrom());
        CellDataObject* toCell = getCellDataObject(move.getTo());

        if(fromCell != nullptr && toCell != nullptr)
        {

            //For castling
            if(fromCell->getPieceType() == PieceType::KING && fromCell->getMoveCount() == 0)
            {
                PieceParty::Enum party = fromCell->getPieceParty();

                if(party == PieceParty::BLACK)
                {
                    if(move.getTo() == _G1_)
                    {
                        CellDataObject* rookH1 = getCellDataObject(_H1_);
                        CellDataObject* cellForRook = getCellDataObject(_F1_);

                        if(rookH1->getPieceType() == PieceType::ROOK && cellForRook->getPieceType() == PieceType::NONE)
                        {
                            cellForRook->setPiece(PieceType::ROOK, party, 1);
                            rookH1->reset();
                        }
                    }
                }
                else if(party == PieceParty::WHITE)
                {
                    if(move.getTo() == _A1_)
                    {
                        CellDataObject* rookH1 = getCellDataObject(_H1_);
                        CellDataObject* cellForRook = getCellDataObject(_F1_);

                        if(rookH1->getPieceType() == PieceType::ROOK && cellForRook->getPieceType() == PieceType::NONE)
                        {
                            cellForRook->setPiece(PieceType::ROOK, party, 1);
                        }
                    }
                }
            }

            toCell->setPiece(fromCell->getPieceType(), fromCell->getPieceParty(), fromCell->getMoveCount() + 1);
            fromCell->setPieceType(PieceType::NONE);

            return true;
        }
    }

    return false;
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
