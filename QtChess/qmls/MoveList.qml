import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle
{
    property alias movesModel: movesList.model

    property int currentIndex: movesList.count - 1;
    visible: true
    color: "white"

    border.width: 2
    border.color: "black"

    function indexToCell(index)
    {
        if(index < 0 || index > 64)
        {
            return "";
        }

        var row = index / 8
        var col = index % 8

        return (String("ABCDEFGH").charAt(col)) + ("" + Math.round(8 - row + 1))
    }




    ScrollView
    {
        anchors.fill: parent
        anchors.topMargin: 10
        ListView
        {
            id: movesList
            anchors.fill: parent
            spacing: 5

            delegate: MovesDelegate{

                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: 10
            }

        }
    }
}
