import QtQuick 2.4

Rectangle
{
    property int moveIndex: 0
    id: moveDelegate

    color: "#F5CF9A"
    border.color: currentIndex === moveIndex ? "red" : "black"
    border.width: 2

    height: 50

    Row
    {
        spacing: 39
        anchors.fill: parent
        Text
        {
            color: "black"

            visible: true
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 5
            width: height

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.pixelSize: 30

            text: indexToCell(model.modelData.fromIndex)
        }

        Cell
        {
            visible: true
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 5
            width: height

            pieceState: model.modelData.stateFrom
            state: "regular"

            property int verIndex: model.modelData.fromIndex % 8
            property int horIndex: model.modelData.fromIndex / 8
            color: verIndex % 2 == 0 ? (horIndex % 2 == 0 ? "#F5CF9A" : "#D1A05C") : (horIndex % 2 == 0 ? "#D1A05C" : "#F5CF9A")
        }

        Image
        {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 5
            width: height
            source: model.modelData.stateTo === "none" ? "qrc:/imgs/move_arrow.png" : "qrc:/imgs/sword.png"
        }

        Cell
        {
            visible: true
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 5
            width: height

            pieceState: model.modelData.stateTo
            state: "regular"

            property int verIndex: model.modelData.toIndex % 8
            property int horIndex: model.modelData.toIndex / 8
            color: verIndex % 2 == 0 ? (horIndex % 2 == 0 ? "#F5CF9A" : "#D1A05C") : (horIndex % 2 == 0 ? "#D1A05C" : "#F5CF9A")
        }
        Text
        {
            color: "black"

            visible: true
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 5
            width: height

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.pixelSize: 30

            text: indexToCell(model.modelData.toIndex)
        }
    }


}
