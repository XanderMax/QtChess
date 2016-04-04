#include "OnePieceBoardTest.h"

#include "src/boards/OnePieceBoard.h"
#include "src/Constants.h"

void OnePieceBoardTest::prepareDataForSamePieceTypeTest()
{
    QTest::addColumn<PieceType::Enum>("type");
    QTest::addColumn<PieceParty::Enum>("party");
    QTest::addColumn<int>("moves");

    QTest::newRow("black knight") << PieceType::KNIGHT << PieceParty::BLACK << 0;
    QTest::newRow("black knight") << PieceType::KNIGHT << PieceParty::BLACK << 1;

    QTest::newRow("white knight") << PieceType::KNIGHT << PieceParty::WHITE << 0;
    QTest::newRow("white knight") << PieceType::KNIGHT << PieceParty::WHITE << 1;

    QTest::newRow("black king") << PieceType::KING << PieceParty::BLACK << 0;
    QTest::newRow("black king") << PieceType::KING << PieceParty::BLACK << 1;

    QTest::newRow("white king") << PieceType::KING << PieceParty::WHITE << 0;
    QTest::newRow("white king") << PieceType::KING << PieceParty::WHITE << 1;

    QTest::newRow("black pawn") << PieceType::PAWN << PieceParty::BLACK << 0;
    QTest::newRow("black pawn") << PieceType::PAWN << PieceParty::BLACK << 1;

    QTest::newRow("white pawn") << PieceType::PAWN << PieceParty::WHITE << 0;
    QTest::newRow("white pawn") << PieceType::PAWN << PieceParty::WHITE << 1;

    QTest::newRow("black bishop") << PieceType::BISHOP << PieceParty::BLACK << 0;
    QTest::newRow("black bishop") << PieceType::BISHOP << PieceParty::BLACK << 1;

    QTest::newRow("white bishop") << PieceType::BISHOP << PieceParty::WHITE << 0;
    QTest::newRow("white bishop") << PieceType::BISHOP << PieceParty::WHITE << 1;

    QTest::newRow("black rook") << PieceType::ROOK << PieceParty::BLACK << 0;
    QTest::newRow("black rook") << PieceType::ROOK << PieceParty::BLACK << 1;

    QTest::newRow("white rook") << PieceType::ROOK << PieceParty::WHITE << 0;
    QTest::newRow("white rook") << PieceType::ROOK << PieceParty::WHITE << 1;

    QTest::newRow("black queen") << PieceType::QUEEN << PieceParty::BLACK << 0;
    QTest::newRow("black queen") << PieceType::QUEEN << PieceParty::BLACK << 1;

    QTest::newRow("white queen") << PieceType::QUEEN << PieceParty::WHITE << 0;
    QTest::newRow("white queen") << PieceType::QUEEN << PieceParty::WHITE << 1;
}

void OnePieceBoardTest::prepareDataForNumberOfMovesTest()
{
    QTest::addColumn<PieceType::Enum>("type");
    QTest::addColumn<PieceParty::Enum>("party");
    QTest::addColumn<int>("moves");
    QTest::addColumn<int>("index");
    QTest::addColumn<int>("action");
    QTest::addColumn<int>("policy");
    QTest::addColumn<int>("result");

     //KNIGHT
    QTest::newRow("black knight !moved D4") << PieceType::KNIGHT << PieceParty::BLACK << 0 << _D4_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("black knight !moved move friendly") << PieceType::KNIGHT << PieceParty::BLACK << 0 << _D4_
                                            << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("black knight !moved move hostile") << PieceType::KNIGHT << PieceParty::BLACK << 0 << _D4_
                                            << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    QTest::newRow("black knight !moved move empty") << PieceType::KNIGHT << PieceParty::BLACK << 0 << _D4_
                                            << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << 8;


    QTest::newRow("black knight moved D4") << PieceType::KNIGHT << PieceParty::BLACK << 1 << _D4_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("black knight moved move friendly") << PieceType::KNIGHT << PieceParty::BLACK << 1 << _D4_
                                            << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("black knight moved move hostile") << PieceType::KNIGHT << PieceParty::BLACK << 1 << _D4_
                                            << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    QTest::newRow("black knight moved move empty") << PieceType::KNIGHT << PieceParty::BLACK << 1 << _D4_
                                            << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << 8;



    QTest::newRow("black knight !moved A1") << PieceType::KNIGHT << PieceParty::BLACK << 0 << _A1_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    QTest::newRow("black knight moved A1") << PieceType::KNIGHT << PieceParty::BLACK << 1 << _A1_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    QTest::newRow("black knight !moved H1") << PieceType::KNIGHT << PieceParty::BLACK << 0 << _H1_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    QTest::newRow("black knight moved H1") << PieceType::KNIGHT << PieceParty::BLACK << 1 << _H1_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    QTest::newRow("white knight !moved D4") << PieceType::KNIGHT << PieceParty::WHITE << 0 << _D4_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("white knight moved D4") << PieceType::KNIGHT << PieceParty::WHITE << 1 << _D4_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("white knight !moved A1") << PieceType::KNIGHT << PieceParty::WHITE << 0 << _A1_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    QTest::newRow("white knight moved A1") << PieceType::KNIGHT << PieceParty::WHITE << 1 << _A1_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    QTest::newRow("white knight !moved H1") << PieceType::KNIGHT << PieceParty::WHITE << 0 << _H1_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    QTest::newRow("white knight moved H1") << PieceType::KNIGHT << PieceParty::WHITE << 1 << _H1_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 2;

    //KNIGHT


    //KING

    QTest::newRow("black king !moved D4") << PieceType::KING << PieceParty::BLACK << 0 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("black king moved D4") << PieceType::KING << PieceParty::BLACK << 1 << _D4_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("black king moved D4") << PieceType::KING << PieceParty::BLACK << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << 8;

    QTest::newRow("black king moved D4 move friendly") << PieceType::KING << PieceParty::BLACK << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("black king moved D4 move hostile") << PieceType::KING << PieceParty::BLACK << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    QTest::newRow("white king !moved D4") << PieceType::KING << PieceParty::WHITE << 0 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("white king moved D4") << PieceType::KING << PieceParty::WHITE << 1 << _D4_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 8;

    QTest::newRow("white king moved D4 move empty") << PieceType::KING << PieceParty::WHITE << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << 8;

    QTest::newRow("white king moved D4 move friendly") << PieceType::KING << PieceParty::WHITE << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("white king moved D4 move hostile") << PieceType::KING << PieceParty::WHITE << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    //KING


    //PAWN

    QTest::newRow("black pawn !moved D4") << PieceType::PAWN << PieceParty::BLACK << 0 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 4;

    QTest::newRow("black pawn moved D4") << PieceType::PAWN << PieceParty::BLACK << 1 << _D4_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 3;

    QTest::newRow("black pawn moved D4 move empty") << PieceType::PAWN << PieceParty::BLACK << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << 1;

    QTest::newRow("black pawn moved D4 move friendly") << PieceType::PAWN << PieceParty::BLACK << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("black pawn moved D4 move hostile") << PieceType::PAWN << PieceParty::BLACK << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    QTest::newRow("white pawn !moved D4") << PieceType::PAWN << PieceParty::WHITE << 0 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 4;

    QTest::newRow("white pawn moved D4") << PieceType::PAWN << PieceParty::WHITE << 1 << _D4_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 3;

    QTest::newRow("white pawn !moved D4 move empty") << PieceType::PAWN << PieceParty::WHITE << 0 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::EMPTY) << 2;

    QTest::newRow("white pawn moved D4 move friendly") << PieceType::PAWN << PieceParty::WHITE << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("white pawn moved D4 move hostile") << PieceType::PAWN << PieceParty::WHITE << 1 << _D4_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    //PAWN

    //BISHOP

    QTest::newRow("black bishop !moved D4") << PieceType::BISHOP << PieceParty::BLACK << 0 << _D4_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 13;

    QTest::newRow("black bishop moved D4") << PieceType::BISHOP << PieceParty::BLACK << 1 << _D4_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 13;

    QTest::newRow("black bishop !moved A1") << PieceType::BISHOP << PieceParty::BLACK << 0 << _A1_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;

    QTest::newRow("black bishop moved A1") << PieceType::BISHOP << PieceParty::BLACK << 1 << _A1_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;

    QTest::newRow("black bishop !moved B2") << PieceType::BISHOP << PieceParty::BLACK << 0 << _B2_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 9;

    QTest::newRow("black bishop moved B2") << PieceType::BISHOP << PieceParty::BLACK << 1 << _B2_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 9;

    QTest::newRow("black bishop !moved C3") << PieceType::BISHOP << PieceParty::BLACK << 0 << _C3_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 11;

    QTest::newRow("black bishop moved C3") << PieceType::BISHOP << PieceParty::BLACK << 1 << _C3_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 11;

    QTest::newRow("black bishop !moved H6") << PieceType::BISHOP << PieceParty::BLACK << 0 << _H6_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;

    QTest::newRow("black bishop moved H6") << PieceType::BISHOP << PieceParty::BLACK << 1 << _H6_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;


    QTest::newRow("white bishop !moved D4") << PieceType::BISHOP << PieceParty::WHITE << 0 << _D4_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 13;

    QTest::newRow("white bishop moved D4") << PieceType::BISHOP << PieceParty::WHITE << 1 << _D4_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 13;

    QTest::newRow("white bishop !moved A1") << PieceType::BISHOP << PieceParty::WHITE << 0 << _A1_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;

    QTest::newRow("white bishop moved A1") << PieceType::BISHOP << PieceParty::WHITE << 1 << _A1_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;

    QTest::newRow("white bishop !moved B2") << PieceType::BISHOP << PieceParty::WHITE << 0 << _B2_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 9;

    QTest::newRow("white bishop moved B2") << PieceType::BISHOP << PieceParty::WHITE << 1 << _B2_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 9;

    QTest::newRow("white bishop !moved C3") << PieceType::BISHOP << PieceParty::WHITE << 0 << _C3_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 11;

    QTest::newRow("white bishop moved C3") << PieceType::BISHOP << PieceParty::WHITE << 1 << _C3_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 11;

    QTest::newRow("white bishop !moved H6") << PieceType::BISHOP << PieceParty::WHITE << 0 << _H6_
                                            << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;

    QTest::newRow("white bishop moved H6") << PieceType::BISHOP << PieceParty::WHITE << 1 << _H6_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 7;


    //BISHOP



    //ROOK

    QTest::newRow("black rook !moved D4") << PieceType::ROOK << PieceParty::BLACK << 0 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("black rook moved D4") << PieceType::ROOK << PieceParty::BLACK << 1 << _D4_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("black rook !moved A1") << PieceType::ROOK << PieceParty::BLACK << 0 << _A1_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("black rook moved A1") << PieceType::ROOK << PieceParty::BLACK << 1 << _A1_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("black rook !moved A1 move friendly") << PieceType::ROOK << PieceParty::BLACK << 0 << _A1_
                                          << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("black rook moved A1 move hostile") << PieceType::ROOK << PieceParty::BLACK << 1 << _A1_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    QTest::newRow("black rook !moved A1 attack friendly") << PieceType::ROOK << PieceParty::BLACK << 0 << _A1_
                                          << (0 | PieceAction::ATTACK) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("black rook moved A1 attack hostile") << PieceType::ROOK << PieceParty::BLACK << 1 << _A1_
                                         << (0 | PieceAction::ATTACK) << (0 | CellOccupyPolicy::HOSTILE) << 0;


    QTest::newRow("white rook !moved D4") << PieceType::ROOK << PieceParty::WHITE << 0 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("white rook moved D4") << PieceType::ROOK << PieceParty::WHITE << 1 << _D4_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("white rook !moved A1") << PieceType::ROOK << PieceParty::WHITE << 0 << _A1_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("white rook moved A1") << PieceType::ROOK << PieceParty::WHITE << 1 << _A1_
                                         << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 14;

    QTest::newRow("white rook !moved A1 move friendly") << PieceType::ROOK << PieceParty::WHITE << 0 << _A1_
                                          << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("white rook moved A1 move hostile") << PieceType::ROOK << PieceParty::WHITE << 1 << _A1_
                                         << (0 | PieceAction::MOVE) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    QTest::newRow("white rook !moved A1 attack friendly") << PieceType::ROOK << PieceParty::WHITE << 0 << _A1_
                                          << (0 | PieceAction::ATTACK) << (0 | CellOccupyPolicy::FRIENDLY) << 0;

    QTest::newRow("white rook moved A1 attack hostile") << PieceType::ROOK << PieceParty::WHITE << 1 << _A1_
                                         << (0 | PieceAction::ATTACK) << (0 | CellOccupyPolicy::HOSTILE) << 0;

    //ROOK


    //QUEEN

    QTest::newRow("black queen !moved D4") << PieceType::QUEEN << PieceParty::BLACK << 0 << _D4_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 27;

    QTest::newRow("black queen moved D4") << PieceType::QUEEN << PieceParty::BLACK << 1 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 27;

    QTest::newRow("white queen !moved D4") << PieceType::QUEEN << PieceParty::WHITE << 0 << _D4_
                                           << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 27;

    QTest::newRow("white queen moved D4") << PieceType::QUEEN << PieceParty::WHITE << 1 << _D4_
                                          << PieceAction::ALL << CellOccupyPolicy::POSSIBLE << 27;

    //QUEEN
}

void OnePieceBoardTest::test_pieceShouldHaveParticularNumberOfMoves()
{
    //Using prepareDataForNumberOfMovesTest
    QFETCH(PieceType::Enum, type);
    QFETCH(PieceParty::Enum, party);
    QFETCH(int, moves);
    QFETCH(int, index);
    QFETCH(int, action);
    QFETCH(int, policy);
    QFETCH(int, result);

    OnePieceBoard board(index, type, party, moves);

    int numberOfMoves = board.getAvailableCells(index, action, policy).count();

    QVERIFY2(numberOfMoves == result, QString("Number of moves != ")
             .append(QString::number(result))
             .append(". Actual = ")
             .append(QString::number(numberOfMoves))
             .append(" action = ")
             .append(QString::number(action))
             .append(" policy = ")
             .append(QString::number(policy))
             .toStdString().c_str());
}

void OnePieceBoardTest::test_pieceShouldHaveParticularNumberOfMoves_data()
{
    prepareDataForNumberOfMovesTest();
}


void OnePieceBoardTest::test_onePieceBoardShouldReturnSamePieceTypeOnSetIndex()
{
    //Using prepareDataForSamePieceTypeTest
    QFETCH(PieceType::Enum, type);
    QFETCH(PieceParty::Enum, party);
    QFETCH(int, moves);

    OnePieceBoard board(_D4_, type, party, moves);

    PieceType::Enum res = board.getPieceTypeAt(_D4_);

    QVERIFY2(res == type, QString("Piece type != ")
             .append(QString::number(type))
             .append(". Actual = ")
             .append(QString::number(res))
             .toStdString().c_str());
}

void OnePieceBoardTest::test_onePieceBoardShouldReturnSamePieceTypeOnSetIndex_data()
{
    prepareDataForSamePieceTypeTest();
}
