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
    QList<Move>  moves;

    QMap<QString, Controller*> controllers;

    void initGameState();

    void initView();

    void initBoard();

    void startControllers();

    void setUpControllers();

    void addController(const QString& name, Controller* controller);

    void exposeControllersToQmlApp();

protected:
public:

    Game(QQmlApplicationEngine& engine);

    ~Game();

    QQmlApplicationEngine& getEngine() const;

    void updateBoardCells(const QString& stringCells);

    const QList<CellDataObject*>& getCells() const;

    void addMove(const Move& move);
    void emptyMoves();
    void updateMoves();

    BoardState::Enum getBoardState() const;
    void setBoardState(BoardState::Enum boardState);

    PieceParty::Enum getActiveParty() const;
    void setActiveParty(PieceParty::Enum activeParty);
    void switchActiveParty();

    const QObject* getRootView() const;



};




#endif //GAME_H
