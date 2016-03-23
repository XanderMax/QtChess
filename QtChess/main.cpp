#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>

#include "Enums.h"

#include "boards/FreeBoard.h"

int main(int argc, char *argv[])
{
    std::cout << "HELLO " << PieceType::BISHOP;
}
