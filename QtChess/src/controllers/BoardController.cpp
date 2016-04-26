#include "BoardController.h"

#include "../Utils.h"

#include "../game/Game.h"
#include "../boards/FreeMovePolicy.h"

#include "board_controller/LocalGameBoardControllerStartegy.h"
#include "board_controller/PlayerMockBoardControllerStrategy.h"


void BoardController::_start()
{
    board = new Board(game.getCells());
}

void BoardController::_stop()
{

}

BoardController::BoardController(Game &game)  : Controller(game), controllerStrategy(new LocalGameboardControllerStrategy(*this))
{

}

BoardController::~BoardController()
{
    delete board;
}

QList<int> BoardController::getDangerousCells(int index) const
{
    QList<int> cellsList;

    if(board != nullptr)
    {

        PieceParty::Enum party = board->getPiecePartyAt(index);

        std::bitset<CELLS> cells = (board->getAvailableMoves(index, PieceAction::MOVE, CellOccupyPolicy::EMPTY) | board->getAvailableMoves(index, PieceAction::ATTACK, CellOccupyPolicy::HOSTILE));

        std::bitset<CELLS> enemyCells;

        for(int i = 0; i < CELLS; i++)
        {
            if(board->getPiecePartyAt(i) != party && board->getPieceTypeAt(i) != PieceType::NONE)
            {
                enemyCells |= (board->getAvailableCells(i, PieceAction::ATTACK, CellOccupyPolicy::FRIENDLY | CellOccupyPolicy::EMPTY));
            }
        }

        cellsList = getCellsFromBits(cells & enemyCells);
    }

    return cellsList;
}

QList<int> BoardController::getAvailableCells(int index) const
{

    QList<int> cellsList;

    if(board != nullptr)
    {
        std::bitset<CELLS> moveCells = board->getAvailableMoves(index, PieceAction::MOVE, CellOccupyPolicy::EMPTY);
        std::bitset<CELLS> attackCells = board->getAvailableMoves(index, PieceAction::ATTACK, CellOccupyPolicy::HOSTILE);

        std::bitset<CELLS> cells = (moveCells | attackCells);

        cellsList << (getCellsFromBits(cells));
    }

    return cellsList;
}

bool BoardController::move(int from, int to)
{
    if(board != nullptr)
    {
        Move move(from, to);

        if(controllerStrategy != nullptr && controllerStrategy->canMove(move))
        {
            return controllerStrategy->makeMove(move);
        }
    }

    return false;
}

void BoardController::setBoardString(const QString &str)
{
    if(str.isEmpty())
    {
        game.updateBoardCells(BoardConfigurationsString::REGULAR_BOARD());
    }
    else
    {
        game.updateBoardCells(str);
    }

    if(board != nullptr)
    {
        game.setActiveParty(PieceParty::WHITE);
        game.setBoardState(board->getBoardState(game.getActiveParty()));
    }
}

int BoardController::getPartyKing(PieceParty::Enum party) const
{
    if(board != nullptr)
    {
        board->getKingIndex(party);
    }

    return -1;
}

void BoardController::resetBoardToNewGame()
{
    game.emptyMoves();
    game.updateBoardCells(BoardConfigurationsString::REGULAR_BOARD());
    game.setActiveParty(PieceParty::WHITE);
    game.setBoardState(board->getBoardState(game.getActiveParty()));
}

void BoardController::onMove(const Move&)
{
    const QObject* root = game.getRootView();

    if(root != nullptr)
    {
        QObject* boardInput =  root->findChild<QObject*>("boardInput");

        if(boardInput != nullptr)
        {
            boardInput->setProperty("text", board->getBoardString());
        }
    }
}

Board *BoardController::getBoard() const
{
    return board;
}
