TEMPLATE = app

QT += qml quick
QT += network
QT += svg

#CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

QMAKE_LFLAGS += -static -static-libgcc

CONFIG += static


#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

include(src/source.pri)

SOURCES += main.cpp

RESOURCES += \
    imgs.qrc \
    qmls.qrc
