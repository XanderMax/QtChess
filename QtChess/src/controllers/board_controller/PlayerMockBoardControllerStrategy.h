#ifndef PLAYER_MOCK_BOARD_CONTROLLER_STRATEGY_H
#define PLAYER_MOCK_BOARD_CONTROLLER_STRATEGY_H

#include <QTimer>

#include "BoardControllerStrategy.h"

#include "../../Enums.h"


class PlayerMockBoardControllerState : public QObject,  public BoardControllerState
{
    Q_OBJECT

private:
    PieceParty::Enum party;

    QTimer timer;

    void setUpTimer();
protected:
    bool _makeMove(const Move &move);

    bool canMove(const Move &move) const;
public:

    PlayerMockBoardControllerState(BoardController& controller, PieceParty::Enum _party);
    ~PlayerMockBoardControllerState();

public slots:

    void onTimer();

};





#endif //PLAYER_MOCK_BOARD_CONTROLLER_STRATEGY_H
