#ifndef GAME_H
#define GAME_H

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
    const QList<MoveModel*>& getMoves() const;

    void addMove(const Move& move);
    void addMove(MoveModel* move);
    MoveModel* createMoveModel(const Move& move) const;

    void emptyMoves();
    void updateMoves();

    template <class TController>
    TController& getController(const QString& name) const
    {
        if(controllers.contains(name))
        {
            Controller* controller = controllers[name];

            try
            {
                TController* tController = dynamic_cast<TController*>(controller);

                if(tController != nullptr)
                {
                    return *tController;
                }
            }
            catch(const std::bad_cast&)
            {

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
