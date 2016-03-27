#include "GameState.h"

GameState::GameState(BoardState::Enum _boardState, PieceParty::Enum _party)
    :boardState(_boardState), activeParty(_party)
{

}

BoardState::Enum GameState::getBoardState() const
{
    return boardState;
}

void GameState::setBoardState(BoardState::Enum state)
{
    boardState = state;

    emit onStateChanged(boardState);
}

PieceParty::Enum GameState::getPieceParty() const
{
    return activeParty;
}

void GameState::setPieceParty(PieceParty::Enum party)
{
    activeParty = party;

    emit onPartyChanged(activeParty);
}
