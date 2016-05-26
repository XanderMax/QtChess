#ifndef BOARD_CONTROLLER_H
#define BOARD_CONTROLLER_H

#include <memory>

#include <iostream>

#include <QList>
#include <QObject>

#include "../boards/Board.h"
#include "../models/CellDataObject.h"
#include "../game/GameState.h"
#include "Controller.h"
#include "board_controller/BoardControllerState.h"
#include "../Utils.h"

class BoardController : public Controller
{
    Q_OBJECT

private:

    Board* board;
    BoardControllerState* controllerState;

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

    template <class TBoardControllerState, typename...Args>
    void continueWithState(Args...args)
    {
        std::cout << "continueWithState" << std::endl;

        qObjectSafeDelete(controllerState);
        controllerState = new TBoardControllerState(*this, args...);
    }

    template <class TBoardControllerState, typename...Args>
    void startNewWithState(Args...args)
    {
        std::cout << "startNewWithState" << std::endl;

        qObjectSafeDelete(controllerState);

        resetBoardToNewGame();
        controllerState = new TBoardControllerState(*this, args...);
    }

    void onMove(const Move& move);

    Board* getBoard() const;
};



#endif //BOARD_CONTROLLER_H
