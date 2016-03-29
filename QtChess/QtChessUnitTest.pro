TEMPLATE = app

QT += qml quick testlib

#CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

# Additional import path used to resolve QML modules in Qt Creator's code model

# Default rules for deployment.
include(deployment.pri)

include(src/source.pri)
include(test/testing.pri)

SOURCES += test.cpp
