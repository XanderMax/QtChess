#include "Game.h"

#include <QQmlContext>

#include <QQmlComponent>

#include "../Utils.h"

Game::Game(QQmlApplicationEngine &_engine) : engine(_engine)
{
    initGameState();

    initBoard();

    initView();
}

Game::~Game()
{
    delete gameState;
    gameState = nullptr;

    qDeleteAll(cells);
    cells.clear();

    delete boardController;
    boardController = nullptr;

    delete rootView;

    delete rootComponent;
}

QQmlApplicationEngine &Game::getEngine() const
{
    return engine;
}

void Game::initGameState()
{
    gameState = new GameState();
}

void Game::initView()
{
    rootComponent = new QQmlComponent(&engine, QUrl(QStringLiteral("qrc:/qmls/Main.qml")));

    rootView = rootComponent->create();
}

void Game::initBoard()
{
    cells = getCellsFromString(BoardConfigurationsString::REGULAR_BOARD());

    QQmlContext* cntx = engine.rootContext();

    if(cntx != nullptr)
    {
        engine.rootContext()->setContextProperty("myBoardModel", QVariant::fromValue(cells));
    }
}
