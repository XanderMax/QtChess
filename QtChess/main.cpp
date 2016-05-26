#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "src/game/Game.h"

//Test ffffffsdlfjdlsfjdoklsfjdklsfjdklsj
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    new Game(engine);

    return app.exec();

}
