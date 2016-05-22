import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle
{
    property bool moveNavigationDisabled: false
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

    Rectangle
    {
        id: playbackControl
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.top: parent.top

        height: 50

        anchors.margins: 5

        border.width: 2
        color: "#D1A05C"

        Row
        {

            spacing: 67
            anchors.fill: parent

            Image
            {
                anchors.top: parent.top
                anchors.bottom: parent.bottom

                anchors.margins: 5

                width: height

                source: "qrc:/imgs/rewind.png"

                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        if(!moveNavigationDisabled && moveList && moveList.count)
                        {
                            currentIndex = 0
                            moveListController.restoreToMove(currentIndex)
                        }
                    }
                }
            }

            Image
            {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 5

                width: height
                rotation: 180

                source: "qrc:/imgs/play.png"

                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        if(!moveNavigationDisabled && currentIndex > 0)
                        {
                            currentIndex--
                            moveListController.restoreToMove(currentIndex)
                        }
                    }
                }
            }

            Image
            {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 5

                width: height

                source: "qrc:/imgs/stop.png"
            }

            Image
            {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 5

                width: height

                source: "qrc:/imgs/play.png"

                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        if(!moveNavigationDisabled && currentIndex < moveCount - 1)
                        {
                            currentIndex++
                            moveListController.restoreToMove(currentIndex)
                        }
                    }
                }
            }

            Image
            {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 5

                rotation: 180

                width: height

                source: "qrc:/imgs/rewind.png"


                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        if(!moveNavigationDisabled && moveCount > 0)
                        {
                            currentIndex = moveCount > 0 ? moveCount - 1: 0
                            moveListController.restoreToMove(currentIndex)
                        }
                    }
                }
            }
        }
    }

    ScrollView
    {
        anchors.top: playbackControl.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 10
        anchors.bottomMargin: 10
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
                        if(!moveNavigationDisabled)
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
}
