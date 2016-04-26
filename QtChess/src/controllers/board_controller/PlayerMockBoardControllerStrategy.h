#ifndef PLAYER_MOCK_BOARD_CONTROLLER_STRATEGY_H
#define PLAYER_MOCK_BOARD_CONTROLLER_STRATEGY_H

#include <QTimer>

#include "BoardControllerStrategy.h"

#include "../../Enums.h"


class PlayerMockBoardControllerStrategy : public QObject,  public BoardControllerStrategy
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

    PlayerMockBoardControllerStrategy(BoardController& controller, PieceParty::Enum _party);
    ~PlayerMockBoardControllerStrategy();

public slots:

    void onTimer();

};





#endif //PLAYER_MOCK_BOARD_CONTROLLER_STRATEGY_H
