#ifndef GAME_H
#define GAME_H

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>

#include "GameState.h"

#include "../models/MoveModel.h"

#include "../controllers/Controller.h"  



class Game : public QObject
{
    Q_OBJECT

private:

    QQmlApplicationEngine& engine;
    QObject* rootView;
    QQmlComponent* rootComponent;

    GameState* gameState;

    QList<CellDataObject*> cells;
    QList<MoveModel*>  moves;

    QMap<QString, std::shared_ptr<Controller>> controllers;

    void initGameState();

    void initView();

    void initBoard();

    void startControllers();

    void setUpControllers();

    template<class TController, typename ... Types>
    void addController(const QString& name, Types...args)
    {
        if(!controllers.contains(name))
        {
            controllers.insert(name, std::shared_ptr<Controller>(new TController(*this, args...)));
        }
    }

    void exposeControllersToQmlApp();

protected:
public:

    Game(QQmlApplicationEngine& engine);

    ~Game();

    QQmlApplicationEngine& getEngine() const;

    void updateBoardCells(const QString& stringCells);

    const QList<CellDataObject*>& getCells() const;
    const QList<MoveModel*>& getMoves() const;

    void addMove(const Move& move);
    void addMove(MoveModel* move);
    MoveModel* createMoveModel(const Move& move) const;

    void emptyMoves();
    void updateMoves();

    template <class TController = Controller>
    std::shared_ptr<TController> getController(const QString& name) const
    {
        if(controllers.contains(name))
        {
            std::shared_ptr<Controller> controller = controllers[name];

            if(controller != nullptr)
            {
                return std::dynamic_pointer_cast<TController>(controller);
            }

        }

        return nullptr;
    }

    BoardState::Enum getBoardState() const;
    void setBoardState(BoardState::Enum boardState);

    PieceParty::Enum getActiveParty() const;
    void setActiveParty(PieceParty::Enum activeParty);
    void switchActiveParty();

    const QObject* getRootView() const;

    const QObject* findChild(const QString &name);



};




#endif //GAME_H
