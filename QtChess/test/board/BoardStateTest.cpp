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

void BoardStateTest::test_indexShouldBeCalculatedCorrectly()
{
    QFETCH(int, row);
    QFETCH(int, col);
    QFETCH(int, index);

    int calculatedIndex = INDEX(row, col);

    QVERIFY2(calculatedIndex == index, QString("Calculated index = ")
             .append(QString::number(calculatedIndex))
             .toStdString()
             .c_str());
}

void BoardStateTest::test_indexShouldBeCalculatedCorrectly_data()
{
    QTest::addColumn<int>("row");
    QTest::addColumn<int>("col");
    QTest::addColumn<int>("index");

    QTest::newRow("index _A1_") << 0 << 0 << _A1_;
    QTest::newRow("index -1 0") << -1 << 0 << -1;
    QTest::newRow("index 0 -1") << 0 << -1 << -1;
    QTest::newRow("index _E4_") << 3 << 4 << _E4_;
    QTest::newRow("index _H8_") << 7 << 7 << _H8_;
    QTest::newRow("index 8 7") << 8 << 7 << -1;
    QTest::newRow("index 7 8") << 7 << 8 << -1;
}
