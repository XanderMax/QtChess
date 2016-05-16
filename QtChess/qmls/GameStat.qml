import QtQuick 2.0

Rectangle
{
    id: root

    property variant party: ["BLACK", "WHITE"]
    property variant gameStatus: ["MOVE", "CHECKED", "MATED", "PATED"]
    border.width: 2
    border.color: "black"

    Text
    {
        visible: true
        id: gameStateText

        anchors.fill: parent

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        text: party[GameState.party] + " " + gameStatus[GameState.state]

        font.bold: true

        font.pointSize: 16
    }
}
