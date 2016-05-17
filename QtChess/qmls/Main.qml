import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.0


ApplicationWindow {
    visible: true

    id: root

    width: 1200
    height: 900

    QtObject
    {
        id: partySelectToken

        property int new_local_with_computer: 1
        property int new_network_server: 2
        property int new_network_client: 3

        property int continue_local_with_computer: 4

    }

    property bool disableMoveNavigation: false

    menuBar: MenuBar {
        Menu
        {
            title: "Game"

            Menu
            {
                title: "New";

                MenuItem {text: "Local multiplayer"; onTriggered: {gameMenuController.onNewLocalGame(); disableMoveNavigation = false}}
                MenuItem {text: "Local with computer"; onTriggered: {partySelect._show(partySelectToken.new_local_with_computer);  disableMoveNavigation = true}}
                MenuItem {text: "Network"; onTriggered: { disableMoveNavigation = true}}
            }

            Menu
            {
                title: "Continue"

                MenuItem {text: "Local multiplayer"; onTriggered: {gameMenuController.onContinueLocalGame(); disableMoveNavigation = false}}
                MenuItem {text: "Local with computer"; onTriggered: {partySelect._show(partySelectToken.continue_local_with_computer); disableMoveNavigation = true}}
                MenuItem {text: "Network"; onTriggered: {gameMenuController.onContinueLocalGame(); disableMoveNavigation = true}}
            }

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

    GameStat
    {
        id: rec
        visible: true
        x: 8
        y: 0
        height: 200
//        width: 200

        anchors.left: board.right
        anchors.right: parent.right
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

        moveNavigationDisabled: disableMoveNavigation
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home

        onAccepted: {

        }

    }

    SelectParty
    {
        id: partySelect

        visible: false

        x: root.x + (root.width - width) / 2
        y: root.y + (root.height - height) / 2

        onPartySelected:
        {
            if(token === partySelectToken.new_local_with_computer)
            {
                gameMenuController.onNewLocalGameWithMockPlayer(party)
            }
            else if(token === partySelectToken.continue_local_with_computer)
            {
                gameMenuController.onContinueLocalGameWithMockPlayer(party)
            }

            close()
        }
    }
}
