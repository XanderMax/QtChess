import QtQuick 2.0

Rectangle
{
    property alias boardModel: boardCells.model

    property bool moveIsLast: true

    property int selectedCellIndex: -1

    width: 820
    height: 840

    function resetAllCellsToRegular()
    {
        for(var i = 0; i < boardCells.count; i++)
        {
            boardCells.itemAt(i).state = "regular"
        }
    }

    function highlightMoveCells(index)
    {
        var cells = boardController.getAvailableCells(index)
        var dangerCells = boardController.getDangerousCells(index)

        for(var i = 0; i < cells.length; i++)
        {
            boardCells.itemAt(cells[i]).state = "available"
        }

        for(var i = 0; i < dangerCells.length; i++)
        {
            boardCells.itemAt(dangerCells[i]).state = "dangerous"
        }
    }

    TextInput
    {
        id: boardInput
        objectName: "boardInput"
        height: 20
        visible: true

        onAccepted:
        {
            boardController.setBoardString(text)
        }

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        mouseSelectionMode: TextInput.SelectCharacters
        selectByMouse: true
    }

    Column
    {
        id: numbers
        anchors.top: boardInput.bottom
        visible: true

        width:20
        height: 800

        Repeater
        {
            model: 8
            Rectangle
            {
                border.width: 1
                border.color: "black"
                height: 100
                width: 20
                color: "white"
                visible: true

                Text
                {
                    anchors.fill: parent
                    text: "" + (8 - index)
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "black"
                }
            }
        }
    }

    Grid
    {
        anchors.top: numbers.top
        anchors.left: numbers.right

        id: boardGrid

        columns: 8
        rows: 8

        Repeater
        {
            id: boardCells

            Cell
            {
                property int cellIndex: index
                property int verIndex: index % 8

                property int horIndex: index / 8

                color: verIndex % 2 == 0 ? (horIndex % 2 == 0 ? "#F5CF9A" : "#D1A05C") : (horIndex % 2 == 0 ? "#D1A05C" : "#F5CF9A")

                pieceState: model.modelData.state

                state: "regular"
                selected: cellIndex === selectedCellIndex

                MouseArea
                {
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked:
                    {
                        if(selectedCellIndex === -1)
                        {
                            if(pieceState !== "none")
                            {
                                selectedCellIndex = cellIndex;
                                highlightMoveCells(cellIndex)
                            }
                        }
                        else
                        {
                            if(moveIsLast)
                            {
                                boardController.move(selectedCellIndex, cellIndex)
                            }

                            if(selectedCellIndex !== cellIndex)
                            {
                                resetAllCellsToRegular()
                                highlightMoveCells(cellIndex)
                            }

                            selectedCellIndex = -1
                        }
                    }

                    onEntered:
                    {
                        if(selectedCellIndex === -1)
                        {
                            resetAllCellsToRegular()

                            highlightMoveCells(cellIndex)
                        }
                    }

                    onExited:
                    {
                        if(selectedCellIndex === -1)
                        {
                            resetAllCellsToRegular()
                        }
                    }
                }
            }


        }
    }

    Rectangle
    {
        anchors.fill: boardGrid

        visible: !moveIsLast

        color: "grey"
        opacity: 0.6
    }

    Row
    {
        anchors.top: boardGrid.bottom
        anchors.left: numbers.right
        Repeater
        {
            model: 8

            Rectangle
            {
                border.color: "black"
                border.width: 1

                width: 100
                height: 20

                color: "white"

                Text
                {
                    anchors.fill: parent
                    text: String("abcdefgh").charAt(index)
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "black"
                }
            }
        }
    }
}
