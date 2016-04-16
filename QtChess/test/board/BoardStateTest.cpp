#include "BoardStateTest.h"

#include <QString>

#include "src/boards/Board.h"
#include "src/Constants.h"


BoardStateTest::BoardStateTest()
{
}

BoardStateTest::~BoardStateTest()
{
}

void BoardStateTest::init()
{
    cells = getCellsFromString(BoardConfigurationsString::REGULAR_BOARD());
}

void BoardStateTest::cleanup()
{
    qDeleteAll(cells);

    cells.clear();
}

void BoardStateTest::test_boardShouldBeInRegularStateForWhiteAfterResetToRegular()
{
    Board board(cells);

    board.resetToRegular();

    PartyState::Enum partyState = board.getPartyState(PieceParty::WHITE);

    QVERIFY2(partyState == PartyState::REGULAR, QString::number(partyState)
             .append(" != PartyState::REGULAR = ")
             .append(QString::number(PartyState::REGULAR))
             .toStdString().c_str());
}

void BoardStateTest::test_boardShouldBeInRegularStateForBlackAfterResetToRegular()
{
    Board board(cells);

    board.resetToRegular();

    PartyState::Enum partyState = board.getPartyState(PieceParty::BLACK);

    QVERIFY2(partyState == PartyState::REGULAR, QString::number(partyState)
             .append(" != PartyState::REGULAR = ")
             .append(QString::number(PartyState::REGULAR))
             .toStdString().c_str());
}

void BoardStateTest::test_getKingIndexShouldReturnValidIndexForWhiteAfterResetToRegular()
{
    Board board(cells);

    board.resetToRegular();

    int whiteKingIndex = board.getKingIndex(PieceParty::WHITE);

    QVERIFY2(whiteKingIndex >= 0 && whiteKingIndex < CELLS,
             QString().append(QString::number(whiteKingIndex))
             .append(" ").append("is less than 0 or greater than 64").toStdString().c_str());
}

void BoardStateTest::test_getKingIndexShouldReturnValidIndexForBlackAfterResetToRegular()
{
    Board board(cells);

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
             .append(" ")
             .append(QString::number(row))
             .append(" ")
             .append(QString::number(col))
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

    QTest::newRow("index _D3_") << ROW(_D3_) << COL(_D3_) << _D3_;
    QTest::newRow("index _F3_") << ROW(_F3_) << COL(_F3_) << _F3_;
    QTest::newRow("index _E5_") << ROW(_E5_) << COL(_E5_) << _E5_;
}

void BoardStateTest::test_getCellsFromStringShouldAlwaysRetrunListWith64Items()
{
    QFETCH(QString, string);
    QFETCH(int, number);

    QList<CellDataObject*> _cells = getCellsFromString(string);

    QVERIFY2(number == _cells.size(), QString("Expected size is not equal to actual: expected = 64; actual = ")
            .append(QString::number(_cells.size()))
            .toStdString()
            .c_str());

    qDeleteAll(_cells);

    _cells.clear();

}

void BoardStateTest::test_getCellsFromStringShouldAlwaysRetrunListWith64Items_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<int>("number");

    QTest::newRow("test1 empty") << BoardConfigurationsString::EMPTY_BOARD() << CELLS;
    QTest::newRow("test2 regular") << BoardConfigurationsString::REGULAR_BOARD() << CELLS;
    QTest::newRow("test3 random") << "0sgfsdgsfrefsdfrwf" << CELLS;
    QTest::newRow("test4 random") << "0sgfsdgsfrfdfsdfsdfsdfsdfsfsdfwergdfgfgwresefgsdfgsdfsdfsdfsdfsdffwerwrwefdsfsdfdsfsdfsdfsdfdsfsdfefsdfrwf" << CELLS;
    QTest::newRow("test3 random") << "nnnpppPPPnnn" << CELLS;
}

void BoardStateTest::test_shouldHaveCorrespondingPieceTypeInParticularIndex()
{
    QFETCH(int, index);
    QFETCH(QString, string);
    QFETCH(PieceType::Enum, type);

    QList<CellDataObject*> _cells = getCellsFromString(string);

    Board board(_cells);

    PieceType::Enum actualType = board.getPieceTypeAt(index);

    QVERIFY2(actualType == type, QString("Expected piece type is not equal to actual at: index = ")
             .append(QString::number(index))
             .append(QString(" expected = "))
             .append(QString::number(type))
             .append(QString(" actual = "))
             .append(QString::number(actualType))
             .append(QString(" board = "))
             .append(string)
             .toStdString()
             .c_str());

    qDeleteAll(_cells);

    _cells.clear();
}

void BoardStateTest::test_shouldHaveCorrespondingPiecePartyInParticularIndex()
{
    QFETCH(int, index);
    QFETCH(QString, string);
    QFETCH(PieceParty::Enum, party);

    QList<CellDataObject*> _cells = getCellsFromString(string);

    Board board(_cells);

    PieceParty::Enum actualParty = board.getPiecePartyAt(index);

    QVERIFY2(actualParty == party, QString("Expected piece party is not equal to actual at: index = ")
             .append(QString::number(index))
             .append(QString(" expected = "))
             .append(QString::number(party))
             .append(QString(" actual = "))
             .append(QString::number(actualParty))
             .append(QString(" board = "))
             .append(string)
             .toStdString()
             .c_str());

    qDeleteAll(_cells);

    _cells.clear();
}

void BoardStateTest::test_shouldHaveCorrespondingPieceTypeInParticularIndex_data()
{
    shouldHaveCorrespondingPieceInParticularIndexData();
}

void BoardStateTest::test_shouldHaveCorrespondingPiecePartyInParticularIndex_data()
{
    shouldHaveCorrespondingPieceInParticularIndexData();
}

void BoardStateTest::shouldHaveCorrespondingPieceInParticularIndexData()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<int>("index");
    QTest::addColumn<PieceType::Enum>("type");
    QTest::addColumn<PieceParty::Enum>("party");

    QTest::newRow("A1 black rook") << BoardConfigurationsString::REGULAR_BOARD() << _A1_ << PieceType::ROOK << PieceParty::BLACK;
    QTest::newRow("H1 black rook") << BoardConfigurationsString::REGULAR_BOARD() << _H1_ << PieceType::ROOK << PieceParty::BLACK;

    QTest::newRow("B1 black knight") << BoardConfigurationsString::REGULAR_BOARD() << _B1_ << PieceType::KNIGHT << PieceParty::BLACK;
    QTest::newRow("G1 bkacl knight") << BoardConfigurationsString::REGULAR_BOARD() << _G1_ << PieceType::KNIGHT << PieceParty::BLACK;

    QTest::newRow("C1 black bishop") << BoardConfigurationsString::REGULAR_BOARD() << _C1_ << PieceType::BISHOP << PieceParty::BLACK;
    QTest::newRow("F1 bkacl bishop") << BoardConfigurationsString::REGULAR_BOARD() << _F1_ << PieceType::BISHOP << PieceParty::BLACK;

    QTest::newRow("D1 black queen") << BoardConfigurationsString::REGULAR_BOARD() << _D1_ << PieceType::QUEEN << PieceParty::BLACK;
    QTest::newRow("E1 black king") << BoardConfigurationsString::REGULAR_BOARD() << _E1_ << PieceType::KING << PieceParty::BLACK;


    QTest::newRow("A8 white rook") << BoardConfigurationsString::REGULAR_BOARD() << _A8_ << PieceType::ROOK << PieceParty::WHITE;
    QTest::newRow("H8 white rook") << BoardConfigurationsString::REGULAR_BOARD() << _H8_ << PieceType::ROOK << PieceParty::WHITE;

    QTest::newRow("B8 white knight") << BoardConfigurationsString::REGULAR_BOARD() << _B8_ << PieceType::KNIGHT << PieceParty::WHITE;
    QTest::newRow("G8 white knight") << BoardConfigurationsString::REGULAR_BOARD() << _G8_ << PieceType::KNIGHT << PieceParty::WHITE;

    QTest::newRow("C1 white bishop") << BoardConfigurationsString::REGULAR_BOARD() << _C8_ << PieceType::BISHOP << PieceParty::WHITE;
    QTest::newRow("F1 white bishop") << BoardConfigurationsString::REGULAR_BOARD() << _F8_ << PieceType::BISHOP << PieceParty::WHITE;

    QTest::newRow("D1 white queen") << BoardConfigurationsString::REGULAR_BOARD() << _D8_ << PieceType::QUEEN << PieceParty::WHITE;
    QTest::newRow("E1 white king") << BoardConfigurationsString::REGULAR_BOARD() << _E8_ << PieceType::KING << PieceParty::WHITE;
}

void BoardStateTest::test_boardShouldEvaluatePartyStateCorrectlyForParticularConfiguration()
{
    QFETCH(QString, string);
    QFETCH(PieceParty::Enum, party);
    QFETCH(PartyState::Enum, state);

    QList<CellDataObject*> _cells = getCellsFromString(string);

    Board board(_cells);

    PartyState::Enum actualState = board.getPartyState(party);

    QVERIFY2(actualState == state, QString("Expected party state is not equal to actual: expected = ")
             .append(QString::number(state))
             .append(QString("; actual = "))
             .append(QString::number(actualState))
             .append("; board = ")
             .append(string)
             .toStdString()
             .c_str());

    qDeleteAll(_cells);
    _cells.clear();
}

void BoardStateTest::test_boardShouldEvaluatePartyStateCorrectlyForParticularConfiguration_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<PieceParty::Enum>("party");
    QTest::addColumn<PartyState::Enum>("state");

    QTest::newRow("") << BoardConfigurationsString::REGULAR_BOARD() << PieceParty::BLACK << PartyState::REGULAR;
    QTest::newRow("") << BoardConfigurationsString::REGULAR_BOARD() << PieceParty::WHITE << PartyState::REGULAR;


    QTest::newRow("") << "Cnrnnnnnnnnnrnnnnnnnnnnnnnnnnnnnc" << PieceParty::BLACK << PartyState::CHECKED;
    QTest::newRow("") << "cnRnnnnnnnnnRnnnnnnnnnnnnnnnnnnnC" << PieceParty::WHITE << PartyState::CHECKED;

    QTest::newRow("") << "Cnrnnnnnnnnnrnnnnnnnnnnnnnnnnnnnc" << PieceParty::WHITE << PartyState::REGULAR;
    QTest::newRow("") << "cnRnnnnnnnnnRnnnnnnnnnnnnnnnnnnnC" << PieceParty::BLACK << PartyState::REGULAR;


}


