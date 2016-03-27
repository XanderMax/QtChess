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

    void test_boardShouldBeInRegularStateForWhiteAfterResetToRegular();
    void test_boardShouldBeInRegularStateForBlackAfterResetToRegular();

    void test_getKingIndexShouldReturnValidIndexForWhiteAfterResetToRegular();
    void test_getKingIndexShouldReturnValidIndexForBlackAfterResetToRegular();

};



#endif //BOARD_STATE_TEST_H


