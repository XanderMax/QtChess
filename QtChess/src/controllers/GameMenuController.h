#ifndef GAME_MENU_CONTROLLER_H
#define GAME_MENU_CONTROLLER_H


#include "Controller.h"

#include "board_controller/BoardControllerStrategy.h"


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
    Q_INVOKABLE void onNewLocalGameWithMockPlayer();
//    void onNewNetworkGameAsServer(int port);
//    void onNewNetworkGameAsClient(int port, const QString& host);

    Q_INVOKABLE void onContinueLocalGame();
    Q_INVOKABLE void onContinueLocalGameWithMockPlayer();
//    void onContinueNetworkGameAsServer(int port);
//    void onContinueNetworkGameAsClient(int port, const QString& host);

};




#endif //GAME_MENU_CONTROLLER_H
