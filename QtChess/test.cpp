#include <iostream>

#include "QtTest/QTest"

#include "test/board/BoardStateTest.h"
#include "test/states/NoneStateTest.h"


//If you need to add more tests add them here
int test(int argc, char *argv[])
{
    return 0
            | QTest::qExec(new BoardStateTest(), argc, argv)
            | QTest::qExec(new NoneStateTest(), argc, argv)
            | 1;
}


int main(int argc, char *argv[])
{
    std::cout << "[TESTING]" << std::endl;

    test(argc, argv);

    std::cout << "[/TESTING]" << std::endl;


    return 0;
}

