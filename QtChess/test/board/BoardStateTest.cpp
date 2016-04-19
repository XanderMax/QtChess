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

    QTest::newRow("D3 white king") << "nnPnnnnnnnnRnnnnnnpcnnnnR" << _D3_ << PieceType::KING << PieceParty::WHITE;

    QTest::newRow("D3 white king") << "nnPnn|nnnn|nnRnnnnn|np||c|nnnnR" << _D3_ << PieceType::KING << PieceParty::WHITE;

    QTest::newRow("C3 black pawn") << "nnPnn|nnnn|nnRnnnnn|np||c|nnnnR" << _C1_ << PieceType::PAWN << PieceParty::BLACK;

    QTest::newRow("D3 black king") << "nnnn|knnc|nnrn|nnnn|nnnC|nnkn|nnnn|rnnn" << _D3_ << PieceType::KING << PieceParty::BLACK;


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

    QTest::newRow("1") << BoardConfigurationsString::REGULAR_BOARD() << PieceParty::BLACK << PartyState::REGULAR;
    QTest::newRow("2") << BoardConfigurationsString::REGULAR_BOARD() << PieceParty::WHITE << PartyState::REGULAR;


    QTest::newRow("3") << "Cnrnnnnnnnnnrnnnnnnnnnnnnnnnnnnnc" << PieceParty::BLACK << PartyState::CHECKED;
    QTest::newRow("4") << "cnRnnnnnnnnnRnnnnnnnnnnnnnnnnnnnC" << PieceParty::WHITE << PartyState::CHECKED;

    QTest::newRow("5") << "Cnrnnnnnnnnnrnnnnnnnnnnnnnnnnnnnc" << PieceParty::WHITE << PartyState::REGULAR;
    QTest::newRow("6") << "cnRnnnnnnnnnRnnnnnnnnnnnnnnnnnnnC" << PieceParty::BLACK << PartyState::REGULAR;


    QTest::newRow("7") << "nnnnnnnCNnQnnnnnNnncnnKnNnnnRnnnn" << PieceParty::BLACK << PartyState::REGULAR;
    QTest::newRow("8") << "nnnnnnncNnqnnnnnNnnCnnknNnnnrnnnn" << PieceParty::WHITE << PartyState::REGULAR;

    QTest::newRow("9") << "nnnnnnncNnqnnnnnNnnCnnknNnnnrnnnn" << PieceParty::BLACK << PartyState::CHECKED;
    QTest::newRow("10") << "nnnnnnnCNnQnnnnnNnncnnKnNnnnRnnnn" << PieceParty::WHITE << PartyState::CHECKED;


    QTest::newRow("11") << "nnnnKnnCnnRnnnnnnnncnnKnnnnnRnnn" << PieceParty::BLACK << PartyState::REGULAR;
    QTest::newRow("12") << "nnnnknncnnrnnnnnnnnCnnknnnnnrnnn" << PieceParty::WHITE << PartyState::REGULAR;

    QTest::newRow("13") << "nnnn|knnc|nnrn|nnnn|nnnC|nnkn|nnnn|rnnn" << PieceParty::BLACK << PartyState::CHECKED;
    QTest::newRow("14") << "nnnnKnnCnnRnnnnnnnncnnKnnnnnRnnn" << PieceParty::WHITE << PartyState::CHECKED;

    QTest::newRow("15") << "nnPnnnnnnnnRnnnnnnpcnnnnR" << PieceParty::WHITE << PartyState::CHECKED;



}

void BoardStateTest::test_boardShouldEvaluateBoardStateCorrectlyForParticularConfiguration()
{
    QFETCH(QString, string);
    QFETCH(PieceParty::Enum, party);
    QFETCH(BoardState::Enum, state);

    QList<CellDataObject*> _cells = getCellsFromString(string);

    Board board(_cells);

    BoardState::Enum actualState = board.getBoardState(party);

    QVERIFY2(actualState == state, QString("Expected board state is not equal to actual: expected = ")
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

void BoardStateTest::test_boardShouldEvaluateBoardStateCorrectlyForParticularConfiguration_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<PieceParty::Enum>("party");
    QTest::addColumn<BoardState::Enum>("state");

    QTest::newRow("1") << BoardConfigurationsString::REGULAR_BOARD() << PieceParty::BLACK << BoardState::REGULAR;
    QTest::newRow("2") << BoardConfigurationsString::REGULAR_BOARD() << PieceParty::WHITE << BoardState::REGULAR;


    QTest::newRow("3") << "nnnnKnnCnnRnnnnnnnncnnKnnnnnRnnn" << PieceParty::BLACK << BoardState::REGULAR;
    QTest::newRow("4") << "nnnnknncnnrnnnnnnnnCnnknnnnnrnnn" << PieceParty::WHITE << BoardState::REGULAR;

    QTest::newRow("5") << "nnnnknncnnrnnnnnnnnCnnknnnnnrnnn" << PieceParty::BLACK << BoardState::MATED;
    QTest::newRow("6") << "nnnnKnnCnnRnnnnnnnncnnKnnnnnRnnn" << PieceParty::WHITE << BoardState::MATED;


    QTest::newRow("7") << "nnnnnnnCnnRnnnnnnnncnnKnnKnnRnnn" << PieceParty::BLACK << BoardState::REGULAR;
    QTest::newRow("8") << "nnnnnnncnnrnnnnnnnnCnnknnknnrnnn" << PieceParty::WHITE << BoardState::REGULAR;

    QTest::newRow("9") << "nnnnnnncnnrnnnnnnnnCnnknnknnrnnn" << PieceParty::BLACK << BoardState::MATED;
    QTest::newRow("10") << "nnnnnnnCnnRnnnnnnnncnnKnnKnnRnnn" << PieceParty::WHITE << BoardState::MATED;


    QTest::newRow("11") << "nnnnnnnCnnRnnnnnnnncnnKnnnnnRnnnnnK" << PieceParty::BLACK << BoardState::REGULAR;
    QTest::newRow("12") << "nnnnnnncnnrnnnnnnnnCnnknnnnnrnnnnnk" << PieceParty::WHITE << BoardState::REGULAR;

    QTest::newRow("13") << "nnnnnnncnnrnnnnnnnnCnnknnnnnrnnnnnk" << PieceParty::BLACK << BoardState::CHECKED;
    QTest::newRow("14") << "nnnnnnnCnnRnnnnnnnncnnKnnnnnRnnnnnK" << PieceParty::WHITE << BoardState::CHECKED;


    QTest::newRow("15") << "nnPnnnnnnnnRnnnnnnpcnnnnR" << PieceParty::WHITE << BoardState::CHECKED;

    QTest::newRow("16") << "Cnnnnnnnnnnnrnncnrn" << PieceParty::BLACK << BoardState::PATED;

    QTest::newRow("17") << "Cnnn|Pnnn|nnnn|rnnc|nrnn|nnnn" << PieceParty::BLACK << BoardState::PATED;

    QTest::newRow("18") << "CnnnPnnnnnnnrnncnrnnnnnnnnnq" << PieceParty::BLACK << BoardState::MATED;

}

void BoardStateTest::test_availableMovesShouldContainParticularIndiciesForMove()
{
    QFETCH(QString, string);
    QFETCH(int, action);
    QFETCH(int, policy);
    QFETCH(int, index);
    QFETCH(int, possibleMove);

    QList<CellDataObject*> _cells = getCellsFromString(string);

    Board board(_cells);

    std::bitset<CELLS> cells = board.getAvailableMoves(index, action, policy);
    QVERIFY2(getBit(possibleMove, cells), QString("Available moves doesn't contain expected move: expected = ")
             .append(QString::number(possibleMove))
             .append(QString("; at = "))
             .append(QString::number(index))
             .append("; board = ")
             .append(string)
             .append("; moves = ")
             .append(cells.to_string<char,std::string::traits_type,std::string::allocator_type>().c_str())
             .toStdString()
             .c_str());

    qDeleteAll(_cells);
    _cells.clear();
}

void BoardStateTest::test_availableMovesShouldContainParticularIndiciesForMove_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<int>("action");
    QTest::addColumn<int>("policy");
    QTest::addColumn<int>("index");
    QTest::addColumn<int>("possibleMove");

    QTest::newRow("1") << BoardConfigurationsString::REGULAR_BOARD() << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << _A7_ << _A6_;
    QTest::newRow("2") << BoardConfigurationsString::REGULAR_BOARD() << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << _A7_ << _A5_;
    QTest::newRow("3") << BoardConfigurationsString::REGULAR_BOARD() << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << _B8_ << _A6_;
    QTest::newRow("4") << BoardConfigurationsString::REGULAR_BOARD() << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << _B8_ << _C6_;

    QTest::newRow("5") << "nnnnCnnR|nnnnnp" << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << _E1_ << _F1_;
    QTest::newRow("6") << "nnnnCnnR|nnnnnp" << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << _E1_ << _D1_;
}


