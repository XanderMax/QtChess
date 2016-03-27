#ifndef BOARD_STATE_TEST_H
#define BOARD_STATE_TEST_H

#include <QtTest/QtTest>

class BoardStateTest : public QObject
{
    Q_OBJECT

private:
protected:
public:

    BoardStateTest(){}
    ~BoardStateTest() {}

private slots:

    void test_boardShouldBeInRegularStateInitially();

    void test_getKingIndexShouldReturnValidIndex();

};



#endif //BOARD_STATE_TEST_H


