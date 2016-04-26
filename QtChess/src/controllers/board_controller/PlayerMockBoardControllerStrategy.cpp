#include "PlayerMockBoardControllerStrategy.h"

#include <stdlib.h>

#include "../BoardController.h"

#include "../../game/Game.h"

#define MSEC_BASE 5000
#define MSEC_OFFSET 2000


void PlayerMockBoardControllerStrategy::setUpTimer()
{
    int delay = (rand() % MSEC_BASE) + MSEC_OFFSET;
    QTimer::singleShot(delay, this, SLOT(onTimer()));
}

bool PlayerMockBoardControllerStrategy::_makeMove(const Move &move)
{
    Board* board = controller.getBoard();

    Game& game = controller.getGame();

    PieceParty::Enum activeParty = game.getActiveParty();

    if(board != nullptr)
    {
        if(board->getPiecePartyAt(move.getFrom()) == activeParty
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

bool PlayerMockBoardControllerStrategy::canMove(const Move &move) const
{
    PieceParty::Enum activeParty = controller.getGame().getActiveParty();

    return activeParty != party;
}

PlayerMockBoardControllerStrategy::PlayerMockBoardControllerStrategy(BoardController &controller, PieceParty::Enum _party) :
    BoardControllerStrategy(controller), party(_party)
{
    setUpTimer();
}

PlayerMockBoardControllerStrategy::~PlayerMockBoardControllerStrategy()
{

}

void PlayerMockBoardControllerStrategy::onTimer()
{
    Board* board = controller.getBoard();

    Game& game = controller.getGame();

    if(game.getActiveParty() == party && board != nullptr && board->getBoardState(party) != BoardState::MATED)
    {
        while(true)
        {
            int rnd = rand() % CELLS;

            if(board->getPiecePartyAt(rnd) == party && board->getPieceTypeAt(rnd) != PieceType::NONE)
            {
                std::bitset<CELLS> availableMoves = board->getAvailableMoves(rnd);

                if(availableMoves.any())
                {
                    while(true)
                    {
                        int randomCell = rand() % CELLS;

                        if(getBit(randomCell, availableMoves))
                        {
                            Move move(rnd, randomCell);
                            if(makeMove(move))
                            {
                                break;
                            }
                        }
                    }

                    break;
                }
            }
        }
    }

    if(game.getBoardState() != BoardState::MATED)
    {
        setUpTimer();
    }
}
