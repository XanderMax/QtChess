#ifndef ONE_PIECE_BOARD_TEST_H
#define ONE_PIECE_BOARD_TEST_H

#include <QtTest/QtTest>

class OnePieceBoardTest : public QObject
{
    Q_OBJECT

private:

    void prepareDataForSamePieceTypeTest();

    void prepareDataForNumberOfMovesTest();

protected:
public:

    OnePieceBoardTest() {}
    ~OnePieceBoardTest() {}

private slots:

    void test_pieceShouldHaveParticularNumberOfMoves();
    void test_pieceShouldHaveParticularNumberOfMoves_data();

    void test_onePieceBoardShouldReturnSamePieceTypeOnSetIndex();
    void test_onePieceBoardShouldReturnSamePieceTypeOnSetIndex_data();
};




#endif //ONE_PIECE_BOARD_TEST_H
