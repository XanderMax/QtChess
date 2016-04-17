#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "GameState.h"

#include "src/controllers/BoardController.h"



class Game : public QObject
{
    Q_OBJECT

private:

    QQmlApplicationEngine& engine;
    QObject* rootView;
    QQmlComponent* rootComponent;

    GameState* gameState;

    QList<CellDataObject*> cells;

    BoardController* boardController;




    void initGameState();

    void loadRootQmlComponent();

    void initView();

    void initBoard();

protected:
public:

    Game(QQmlApplicationEngine& engine);

    ~Game();

    QQmlApplicationEngine& getEngine() const;

};




#endif //GAME_H
