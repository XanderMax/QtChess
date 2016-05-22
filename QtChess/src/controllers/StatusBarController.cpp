#include "StatusBarController.h"

#include "../game/Game.h"

void StatusBarController::setStatusBarText(const QString &text)
{
    if(statusBar != nullptr)
    {
        statusBar->setProperty("text", text);
    }
}

void StatusBarController::_start()
{
    const QObject* rootView = getGame().getRootView();

    if(rootView != nullptr)
    {
        statusBar = rootView->findChild<QObject*>(QmlObjectName::STATUS_BAR);

        setStatusBarText("N/A");
    }
}

void StatusBarController::_stop()
{

}

StatusBarController::StatusBarController(Game &game) : Controller(game)
{

}

StatusBarController::~StatusBarController()
{

}
