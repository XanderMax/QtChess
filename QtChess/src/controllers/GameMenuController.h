#ifndef GAME_MENU_CONTROLLER_H
#define GAME_MENU_CONTROLLER_H


#include "Controller.h"

#include "board_controller/BoardControllerState.h"

#include "../Enums.h"


class GameMenuController : public Controller
{
    Q_OBJECT

private:

protected:

    void _start();
    void _stop();

public:

    GameMenuController(Game& game);
    ~GameMenuController();

    Q_INVOKABLE void onNewLocalGame();
    Q_INVOKABLE void onNewLocalGameWithMockPlayer(PieceParty::Enum);
    Q_INVOKABLE void onNewNetworkGameAsServer(PieceParty::Enum, int port);
    Q_INVOKABLE void onNewNetworkGameAsClient(PieceParty::Enum, int port, const QString& host);

    Q_INVOKABLE void onContinueLocalGame();
    Q_INVOKABLE void onContinueLocalGameWithMockPlayer(PieceParty::Enum);
    Q_INVOKABLE void onContinueNetworkGameAsServer(PieceParty::Enum, int port);
    Q_INVOKABLE void onContinueNetworkGameAsClient(PieceParty::Enum, int port, const QString& host);

};




#endif //GAME_MENU_CONTROLLER_H
