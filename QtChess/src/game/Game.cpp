#include "Game.h"

#include <QQmlContext>

#include <QQmlComponent>

#include "../Utils.h"

#include "../controllers/BoardController.h"
#include "../controllers/MoveListController.h"

Game::Game(QQmlApplicationEngine &_engine) : engine(_engine)
{
    initGameState();

    initBoard();

    updateMoves();

    initView();

    setUpControllers();
    startControllers();
    exposeControllersToQmlApp();
}

Game::~Game()
{
    delete gameState;
    gameState = nullptr;

    qDeleteAll(cells);
    cells.clear();

    delete rootView;
    rootView = nullptr;

    delete rootComponent;
    rootComponent = nullptr;

    controllers.clear();

    qDeleteAll(moves);
    moves.clear();
}

QQmlApplicationEngine &Game::getEngine() const
{
    return engine;
}

void Game::updateBoardCells(const QString &stringCells)
{
    if(cells.isEmpty())
    {
        cells = getCellsFromString(stringCells);
    }
    else
    {
        QList<CellDataObject*> tempList = getCellsFromString(stringCells);

        for(int i = 0; i < tempList.size(); i++)
        {
            if(i >= cells.size())
            {
                break;
            }

            CellDataObject* object = cells[i];
            CellDataObject* tmpObject = tempList[i];

            if(object != nullptr && tmpObject != nullptr)
            {
                object->setPiece(tmpObject->getPieceType(), tmpObject->getPieceParty(), tmpObject->getMoveCount());
            }
        }

        qDeleteAll(tempList);
        tempList.clear();
    }

    QList<QObject*> cellObjects;

    for(CellDataObject* cellObject : cells)
    {
        if(cellObject != nullptr)
        {
            cellObjects << (QObject*)cellObject;
        }
    }

    QQmlContext* cntx = engine.rootContext();

    if(cntx != nullptr)
    {
        cntx->setContextProperty("myBoardModel", QVariant::fromValue(cellObjects));
    }
}

const QList<CellDataObject *> &Game::getCells() const
{
    return cells;
}

const QList<MoveModel *> &Game::getMoves() const
{
    return moves;
}

void Game::addMove(const Move &move)
{
    moves << new MoveModel(move, cells);
    updateMoves();
}

void Game::addMove(MoveModel *move)
{
    if(move != nullptr)
    {
        moves << move;
    }

    updateMoves();
}

MoveModel *Game::createMoveModel(const Move &move) const
{
    return new MoveModel(move, cells);
}

void Game::emptyMoves()
{
    QQmlContext* cntx = engine.rootContext();

    QList<QObject*> list;

    if(cntx != nullptr)
    {
        cntx->setContextProperty("Moves", QVariant::fromValue(list));
    }

    if(!moves.isEmpty())
    {
        qDeleteAll(moves);
        moves.clear();
    }
}

void Game::updateMoves()
{
    QQmlContext* cntx = engine.rootContext();

    QList<QObject*> list;

    for(int i = 0; i < moves.size(); i++)
    {
        MoveModel* model = moves[i];

        if(model != nullptr)
        {
            list << (QObject*) model;
        }
    }

    if(cntx != nullptr)
    {
        cntx->setContextProperty("Moves", QVariant::fromValue(list));
    }
}

BoardState::Enum Game::getBoardState() const
{
    if(gameState != nullptr)
    {
        return gameState->getBoardState();
    }

    return BoardState::REGULAR;
}

void Game::setBoardState(BoardState::Enum boardState)
{
    if(gameState != nullptr)
    {
        gameState->setBoardState(boardState);
    }
}

PieceParty::Enum Game::getActiveParty() const
{
    if(gameState != nullptr)
    {
        return gameState->getPieceParty();
    }

    return PieceParty::WHITE;
}

void Game::setActiveParty(PieceParty::Enum activeParty)
{
    if(gameState != nullptr)
    {
        gameState->setPieceParty(activeParty);
    }
}

void Game::switchActiveParty()
{
    if(gameState != nullptr)
    {
        if(gameState->getPieceParty() == PieceParty::BLACK)
        {
            gameState->setPieceParty(PieceParty::WHITE);
        }
        else if(gameState->getPieceParty() == PieceParty::WHITE)
        {
            gameState->setPieceParty(PieceParty::BLACK);
        }
    }
}

const QObject *Game::getRootView() const
{
    return rootView;
}

const QObject *Game::findChild(const QString &name)
{
    if(rootView != nullptr)
    {
        return rootView->findChild<QObject*>(name);
    }

    return nullptr;
}

void Game::addController(const QString &name, Controller *controller)
{
    if(!controllers.contains(name) && controller != nullptr)
    {
        controllers.insert(name, std::shared_ptr<Controller>(controller));
    }
}

void Game::exposeControllersToQmlApp()
{
    QQmlContext* cntx = engine.rootContext();

    for(auto it = controllers.begin(); it != controllers.end(); ++it)
    {
        std::shared_ptr<Controller> ctr = it.value();

        if(ctr != nullptr && cntx != nullptr)
        {
            cntx->setContextProperty(it.key(), ctr.get());
        }
    }
}

void Game::initGameState()
{
    gameState = new GameState();

    QQmlContext* cntx = engine.rootContext();

    if(cntx != nullptr)
    {
        cntx->setContextProperty("GameState", (QObject*)gameState);
    }
}

void Game::initView()
{
    rootComponent = new QQmlComponent(&engine, QUrl(QStringLiteral("qrc:/qmls/Main.qml")));

    rootView = rootComponent->create();
}

void Game::initBoard()
{
    updateBoardCells(BoardConfigurationsString::EMPTY_BOARD());
    emptyMoves();
}

void Game::startControllers()
{
    for(auto it = controllers.begin(); it != controllers.end(); ++it)
    {
        std::shared_ptr<Controller> ctr = it.value();

        if(ctr != nullptr)
        {
            ctr->start();
        }
    }
}

void Game::setUpControllers()
{
    addController("boardController", new BoardController(*this));
    addController("moveListController", new MoveListController(*this));
}
