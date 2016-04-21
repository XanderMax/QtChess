import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.0


ApplicationWindow {
    visible: true

    width: 1200
    height: 900

    menuBar: MenuBar {
        Menu
        {
            title: "Game"

            MenuItem {text: "New"; onTriggered: {boardController.resetBoardToNewGame()}}
            MenuItem {text: "Load..."; onTriggered: {fileDialog.open()}}
            MenuItem {text: "Save..."}
            MenuItem {text: "Exit"}
        }

    }


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
        moveIsLast: moveList.isLastMove
    }

    Rectangle
    {
        id: rec
        visible: true
        color: GameState.state === 3 ? "yellow" : "green"
        x: 1000
        y: 0
        height: 200
        width: 200
    }

    MoveList
    {
        id: moveList
        visible: true
        movesModel: Moves
        anchors.top: rec.bottom
        anchors.left: board.right
        anchors.right: parent.right
        anchors.bottom: board.bottom
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home

        onAccepted: {

        }

    }
}
