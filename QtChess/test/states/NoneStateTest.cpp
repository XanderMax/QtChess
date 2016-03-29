#include "NoneStateTest.h"

#include "src/Enums.h"


void NoneStateTest::test_noneStateShouldReturnNoneForGetPieceType()
{
    NoneState noneState;

    QVERIFY2(noneState.getPieceType() == PieceType::NONE,
             "noneState didn't return PieceState::NONE as a result getPieceType()");
}

void NoneStateTest::test_noneStateShouldReturnZeroForGetMoveCount()
{
    NoneState noneState;

    QVERIFY2(noneState.getMoveCount() == 0,
             "noneState didn't return 0 as a result getMoveCount()");
}

void NoneStateTest::test_noneStateShouldReturnEmptyBitsetForGetCells()
{
    //TODO: implement this test as a Data Driven test
}


