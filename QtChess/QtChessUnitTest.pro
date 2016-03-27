TEMPLATE = app

QT += qml quick

# Additional import path used to resolve QML modules in Qt Creator's code model

# Default rules for deployment.
include(deployment.pri)

include(src/source.pri)
include(test/testing.pri)

SOURCES += test.cpp
