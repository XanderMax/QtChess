#ifndef BOARD_STATE_TEST_H
#define BOARD_STATE_TEST_H

#include <QtTest/QtTest>

#include "src/Utils.h"

class BoardStateTest : public QObject
{
    Q_OBJECT

private:

    QList<CellDataObject*> cells;

protected:
public:

    BoardStateTest();
    ~BoardStateTest();

private slots:

    void init();
    void cleanup();

    void test_boardShouldBeInRegularStateForWhiteAfterResetToRegular();
    void test_boardShouldBeInRegularStateForBlackAfterResetToRegular();


    void test_getKingIndexShouldReturnValidIndexForWhiteAfterResetToRegular();
    void test_getKingIndexShouldReturnValidIndexForBlackAfterResetToRegular();


    void test_indexShouldBeCalculatedCorrectly();
    void test_indexShouldBeCalculatedCorrectly_data();


    void test_getCellsFromStringShouldAlwaysRetrunListWith64Items();
    void test_getCellsFromStringShouldAlwaysRetrunListWith64Items_data();


    void test_shouldHaveCorrespondingPieceTypeInParticularIndex();
    void test_shouldHaveCorrespondingPieceTypeInParticularIndex_data();

    void test_shouldHaveCorrespondingPiecePartyInParticularIndex();
    void test_shouldHaveCorrespondingPiecePartyInParticularIndex_data();

    void shouldHaveCorrespondingPieceInParticularIndexData();


    void test_boardShouldEvaluatePartyStateCorrectlyForParticularConfiguration();
    void test_boardShouldEvaluatePartyStateCorrectlyForParticularConfiguration_data();


    void test_boardShouldEvaluateBoardStateCorrectlyForParticularConfiguration();
    void test_boardShouldEvaluateBoardStateCorrectlyForParticularConfiguration_data();

};



#endif //BOARD_STATE_TEST_H


