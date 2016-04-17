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
        objectName: "boardWidget"
        boardModel: myBoardModel
    }
}
