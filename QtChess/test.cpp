#include <iostream>

#include "QtTest/QTest"

#include "test/board/BoardStateTest.h"


//If you need to add more tests add it here
void test(int argc, char *argv[])
{
    QTest::qExec(new BoardStateTest(), argc, argv);
}


void main(int argc, char *argv[])
{
    std::cout << "[TESTING]" << std::endl;

    test(argc, argv);

    std::cout << "[/TESTING]" << std::endl;
}

