#include "BoardStateTest.h"

#include "src/boards/Board.h"
#include "src/Constants.h"


void BoardStateTest::test_boardShouldBeInRegularStateInitially()
{
    Board board;

    board.resetToRegular();

    QCOMPARE(board.getPartyState(PieceParty::WHITE), PartyState::REGULAR);

    QCOMPARE(board.getPartyState(PieceParty::BLACK), PartyState::REGULAR);
}

void BoardStateTest::test_getKingIndexShouldReturnValidIndex()
{
    Board board;

    board.resetToRegular();

    int whiteKingIndex = board.getKingIndex(PieceParty::WHITE);

    QVERIFY2(whiteKingIndex >= 0 && whiteKingIndex < CELLS,
             QString(whiteKingIndex).append(" ").append("is less than 0 or greate than 64").toStdString().c_str());
}
