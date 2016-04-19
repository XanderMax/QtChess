import QtQuick 2.4
import QtQuick.Window 2.2


Window {
    visible: true

    width: 1200
    height: 900


    Rectangle
    {
        anchors.fill: parent
        visible: true

        color: "blue"
    }

    Board
    {
        id: board
        boardModel: myBoardModel
    }

    Rectangle
    {
        visible: true
        color: GameState.state == 3 ? "yellow" : "green"
        x: 1000
        y: 0
        height: 200
        width: 200

        Column
        {
            Repeater
            {
                model: Moves

                Text {height: 20; width: 20; text: "HELLO"}
            }
        }
    }
}
