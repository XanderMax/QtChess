#include "PlayerMockBoardControllerState.h"

#include <stdlib.h>

#include "../BoardController.h"

#include "../../game/Game.h"

#define MSEC_BASE 2000
#define MSEC_OFFSET 1000

#define MAX_RANDOM_ITERATIONS 10000


void PlayerMockBoardControllerState::setUpTimer()
{
    int delay = (rand() % MSEC_BASE) + MSEC_OFFSET;
    QTimer::singleShot(delay, this, SLOT(onTimer()));
}

bool PlayerMockBoardControllerState::_makeMove(const Move &move)
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

bool PlayerMockBoardControllerState::canMove(const Move &move) const
{
    PieceParty::Enum activeParty = controller.getGame().getActiveParty();

    return activeParty != party;
}

PlayerMockBoardControllerState::PlayerMockBoardControllerState(BoardController &controller, PieceParty::Enum _party) :
    BoardControllerState(controller), party(_party)
{
    setUpTimer();

    setStatusBarText(QString("Local with dummy player; Party: %1")
                     .arg(PieceParty::getOpposite(party) == PieceParty::BLACK ? "Black" : "White"));
}

PlayerMockBoardControllerState::~PlayerMockBoardControllerState()
{

}

void PlayerMockBoardControllerState::onTimer()
{
    Board* board = controller.getBoard();

    Game& game = controller.getGame();

    if(game.getActiveParty() == party && board != nullptr)
    {
        if(board != nullptr)
        {
            BoardState::Enum boardState = board->getBoardState(party);

            if(boardState != BoardState::PATED && boardState != BoardState::MATED)
            {
                while(true)
                {
                    int rnd = rand() % CELLS;

                    if(board->getPiecePartyAt(rnd) == party && board->getPieceTypeAt(rnd) != PieceType::NONE)
                    {
                        std::bitset<CELLS> availableMoves = board->getAvailableMoves(rnd);

                        if(availableMoves.any())
                        {
                            int iterations = 0;
                            while(true)
                            {
                                iterations++;
                                int randomCell = rand() % CELLS;

                                if(getBit(randomCell, availableMoves))
                                {
                                    Move move(rnd, randomCell);
                                    if(makeMove(move))
                                    {
                                        break;
                                    }
                                }

                                if(iterations >= MAX_RANDOM_ITERATIONS)
                                {
                                    break;
                                }
                            }

                            break;
                        }
                    }
                }
            }
        }

    }

    if(game.getBoardState() != BoardState::MATED && game.getBoardState() != BoardState::PATED)
    {
        setUpTimer();
    }
}
