import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.0


ApplicationWindow {
    visible: true

    id: root

    maximumWidth: 1300
    maximumHeight: 900

    minimumWidth: maximumWidth
    minimumHeight: maximumHeight

    width: maximumWidth
    height: maximumHeight

    QtObject
    {
        id: partySelectToken

        property int new_local_with_computer: 1
        property int new_network_server: 2
        property int new_network_client: 3

        property int continue_local_with_computer: 4
        property int continue_network_server: 5
        property int continue_network_client: 6

    }

    property bool disableMoveNavigation: false

    menuBar: MenuBar {
        Menu
        {
            title: "Game"

            Menu
            {
                title: "New";

                MenuItem {
                    text: "Local multiplayer";
                    onTriggered: {
                        gameMenuController.onNewLocalGame();
                        disableMoveNavigation = false
                    }
                }

                MenuItem {
                    text: "Local with computer";
                    onTriggered: {
                        partySelect._show(partySelectToken.new_local_with_computer);
                    }
                }

                Menu
                {
                    title: "Network"

                    MenuItem {text: "Server";
                        onTriggered: {
                            networkPartySelect.showServer(partySelectToken.new_network_server)
                        }
                    }

                    MenuItem {text: "Client";
                        onTriggered: {
                            networkPartySelect.showServer(partySelectToken.new_network_client)
                        }
                    }
                }
            }

            Menu
            {
                title: "Continue"

                MenuItem {
                    text: "Local multiplayer";
                    onTriggered: {
                        gameMenuController.onContinueLocalGame();
                        disableMoveNavigation = false
                    }
                }

                MenuItem {
                    text: "Local with computer";
                    onTriggered: {
                        partySelect._show(partySelectToken.continue_local_with_computer);
                    }
                }

                Menu
                {
                    title: "Network"

                    MenuItem {text: "Server";
                        onTriggered: {
                            networkPartySelect.showServer(partySelectToken.continue_network_server)
                        }
                    }
                }
            }

            MenuItem {
                text: "Load...";
                onTriggered: {fileDialog.open()
                }
            }

            MenuItem {
                text: "Save...";
                onTriggered: {

                }
            }

            MenuItem {
                text: "Exit";
                onTriggered: {

                }
            }
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

    Text
    {
        objectName: "statusBar"
        anchors.top: board.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home

        onAccepted: {

        }

    }

    SelectPartyDialog
    {
        id: partySelect

        visible: false

        x: root.x + (root.width - width) / 2
        y: root.y + (root.height - height) / 2

        onSelected:
        {
            if(token === partySelectToken.new_local_with_computer)
            {
                gameMenuController.onNewLocalGameWithMockPlayer(party)
                disableMoveNavigation = true
            }
            else if(token === partySelectToken.continue_local_with_computer)
            {
                gameMenuController.onContinueLocalGameWithMockPlayer(party)
                disableMoveNavigation = true
            }

            _close()
        }
    }

    SelectPartyForNetworkGame
    {
        id: networkPartySelect

        visible: false

        x: root.x + (root.width - width) / 2
        y: root.y + (root.height - height) / 2

        onSelected:
        {
            if(token === partySelectToken.new_network_server)
            {
                gameMenuController.onNewNetworkGameAsServer(party, port)
                disableMoveNavigation = true
            }
            else if(token === partySelectToken.new_network_client)
            {
                gameMenuController.onNewNetworkGameAsClient(party, port, host)
                disableMoveNavigation = true
            }
            else if(token == partySelectToken.continue_network_server)
            {
                gameMenuController.onContinueNetworkGameAsServer(party, port)
                disableMoveNavigation = true
            }
            else if(token === partySelectToken.continue_network_client)
            {
                gameMenuController.onContinueNetworkGameAsClient(party, port, host)
                disableMoveNavigation = true
            }

            _close()
        }
    }
}
