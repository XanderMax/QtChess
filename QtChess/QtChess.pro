TEMPLATE = app

QT += qml quick

#CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11


#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

include(src/source.pri)

SOURCES += main.cpp \
    test/board/BoardStateTest.cpp \
    test/board/OnePieceBoardTest.cpp \
    test/states/NoneStateTest.cpp \
    test.cpp

HEADERS += \
    test/board/BoardStateTest.h \
    test/board/OnePieceBoardTest.h \
    test/states/NoneStateTest.h
