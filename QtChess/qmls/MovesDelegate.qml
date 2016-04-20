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
        spacing: 26
        anchors.fill: parent
        Text
        {
            color: "black"
            width: 50
            height: width

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.pixelSize: 30

            text: indexToCell(model.modelData.fromIndex)
        }

        Piece
        {
            visible: true
//                        anchors.top: parent.top
//                        anchors.bottom: parent.bottom
            width: 50
            height: width

            state: model.modelData.stateFrom
        }

        Image
        {
            width: 50
            height: width
            source: "qrc:/imgs/move_arrow.png"
        }

        Piece
        {
            visible: true
//                        anchors.top: parent.top
//                        anchors.bottom: parent.bottom
            width: 50
            height: width

            state: model.modelData.stateTo
        }
        Text
        {
            color: "black"
            width: 50
            height: width

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.pixelSize: 30

            text: indexToCell(model.modelData.toIndex)
        }
    }


}
