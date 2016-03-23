#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <QObject>

#include "Enums.h"

class GameState : QObject
{
    Q_OBJECT

    Q_PROPERTY(int state READ getBoardState NOTIFY onStateChanged)
    Q_PROPERTY(int party READ getPieceParty NOTIFY onPartyChanged)

private:

    BoardState::Enum boardState;

    PieceParty::Enum activeParty;

protected:
public:

    GameState(BoardState::Enum _boardState = BoardState::REGULAR, PieceParty::Enum _party = PieceParty::WHITE);

    ~GameState();

    BoardState::Enum getBoardState() const;
    void setBoardState(BoardState::Enum);

    PieceParty::Enum getPieceParty() const;
    void setPieceParty(PieceParty::Enum);

signals:

    void onStateChanged();

    void onPartyChanged();


};


#endif //GAME_STATE_H
