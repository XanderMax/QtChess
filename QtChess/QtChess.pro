TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    states/BishopState.cpp \
    states/KingState.cpp \
    states/KnightState.cpp \
    states/NoneState.cpp \
    states/PawnState.cpp \
    states/PieceState.cpp \
    states/QueenState.cpp \
    states/RookState.cpp \
    boards/Board.cpp \
    boards/BoardBase.cpp \
    boards/FreeBoard.cpp \
    game/Game.cpp \
    game/GameState.cpp \
    models/CellDataObject.cpp \
    Constants.cpp

#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    states/BishopState.h \
    states/KingState.h \
    states/KnightState.h \
    states/NoneState.h \
    states/PawnState.h \
    states/PieceState.h \
    states/QueenState.h \
    states/RookState.h \
    Enums.h \
    Constants.h \
    boards/Board.h \
    boards/BoardBase.h \
    boards/FreeBoard.h \
    game/Game.h \
    game/GameState.h \
    models/CellDataObject.h
