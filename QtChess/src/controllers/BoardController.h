#ifndef BOARD_CONTROLLER_H
#define BOARD_CONTROLLER_H

#include <memory>

#include <QList>
#include <QObject>

#include "../boards/Board.h"
#include "../models/CellDataObject.h"
#include "../game/GameState.h"
#include "Controller.h"
#include "board_controller/BoardControllerState.h"

class BoardController : public Controller
{
    Q_OBJECT

private:

    Board* board;
    std::unique_ptr<BoardControllerState> controllerState;

protected:

    void _start();
    void _stop();

public:

    BoardController(Game& game);
    ~BoardController();

    Q_INVOKABLE QList<int> getDangerousCells(int index) const;
    Q_INVOKABLE QList<int> getAvailableCells(int index) const;
    Q_INVOKABLE bool move(int from, int to);

    Q_INVOKABLE void setBoardString(const QString& str);

    Q_INVOKABLE int getPartyKing(PieceParty::Enum party) const;

    Q_INVOKABLE void resetBoardToNewGame();

    void continueWithState(BoardControllerState* boardControllerState);
    void startNewWithState(BoardControllerState* boardControllerState);

    void onMove(const Move& move);

    Board* getBoard() const;
};



#endif //BOARD_CONTROLLER_H
