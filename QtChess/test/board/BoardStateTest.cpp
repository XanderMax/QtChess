#include "BoardStateTest.h"

#include "src/boards/Board.h"
#include "src/Constants.h"


void BoardStateTest::test_boardShouldBeInRegularStateForWhiteAfterResetToRegular()
{
    Board board;

    board.resetToRegular();

    PartyState::Enum partyState = board.getPartyState(PieceParty::WHITE);

    QVERIFY2(partyState == PartyState::REGULAR, QString::number(partyState)
             .append(" != PartyState::REGULAR = ")
             .append(QString::number(PartyState::REGULAR))
             .toStdString().c_str());
}

void BoardStateTest::test_boardShouldBeInRegularStateForBlackAfterResetToRegular()
{
    Board board;

    board.resetToRegular();

    PartyState::Enum partyState = board.getPartyState(PieceParty::BLACK);

    QVERIFY2(partyState == PartyState::REGULAR, QString::number(partyState)
             .append(" != PartyState::REGULAR = ")
             .append(QString::number(PartyState::REGULAR))
             .toStdString().c_str());
}

void BoardStateTest::test_getKingIndexShouldReturnValidIndexForWhiteAfterResetToRegular()
{
    Board board;

    board.resetToRegular();

    int whiteKingIndex = board.getKingIndex(PieceParty::WHITE);

    QVERIFY2(whiteKingIndex >= 0 && whiteKingIndex < CELLS,
             QString().append(QString::number(whiteKingIndex))
             .append(" ").append("is less than 0 or greater than 64").toStdString().c_str());
}

void BoardStateTest::test_getKingIndexShouldReturnValidIndexForBlackAfterResetToRegular()
{
    Board board;

    board.resetToRegular();

    int blackKingIndex = board.getKingIndex(PieceParty::BLACK);

    QVERIFY2(blackKingIndex >= 0 && blackKingIndex < CELLS,
             QString().append(QString::number(blackKingIndex))
             .append(" ").append("is less than 0 or greater than 64").toStdString().c_str());
}
