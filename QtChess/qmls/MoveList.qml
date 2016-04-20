import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle
{
    property alias movesModel: movesList.model

    property int moveCount: movesList && movesList.count ? movesList.count : 0
    property int currentIndex: moveCount > 0 ? moveCount - 1: 0
    property bool isLastMove: moveCount === 0 || (moveCount - 1 === currentIndex)

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

        return (String("ABCDEFGH").charAt(col)) + ("" + (8 - (Math.floor(row))))
    }

    onMoveCountChanged:
    {
        currentIndex = moveCount > 0 ? moveCount - 1: 0
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

                id: moveDelegate
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: 10
                moveIndex: index

                MouseArea
                {
                    anchors.fill: parent

                    onDoubleClicked:
                    {
                        currentIndex = moveDelegate.moveIndex
                        moveListController.restoreToMove(currentIndex)

                        console.log(moveCount + "  " + currentIndex)
                    }
                }
            }

        }
    }
}
