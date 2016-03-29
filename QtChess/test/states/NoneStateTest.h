#ifndef NONE_STATE_TEST_H
#define NONE_STATE_TEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "src/states/NoneState.h"

class NoneStateTest : public QObject
{
    Q_OBJECT

private:
protected:
public:

    NoneStateTest() {}
    ~NoneStateTest() {}

private slots:

    void test_noneStateShouldReturnNoneForGetPieceType();

    void test_noneStateShouldReturnZeroForGetMoveCount();

    void test_noneStateShouldReturnEmptyBitsetForGetCells();

};



#endif //NONE_STATE_TEST_H
