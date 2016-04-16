#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>

#include "src/Enums.h"

#include "src/boards/OneMoveAheadBoard.h"

int main(int argc, char *argv[])
{
    std::cout << "HELLO " << PieceType::BISHOP;
}
