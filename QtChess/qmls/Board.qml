import QtQuick 2.0

Rectangle
{
    property alias boardModel: boardCells.model

    width: 820
    height: 840


    Grid
    {
        id: boardGrid

        columns: 8
        rows: 8

        Repeater
        {
            id: boardCells

            Cell
            {
                property int verIndex: index % 8

                property int horIndex: index / 8

                color: verIndex % 2 == 0 ? (horIndex % 2 == 0 ? "#F5CF9A" : "#D1A05C") : (horIndex % 2 == 0 ? "#D1A05C" : "#F5CF9A")

                pieceState: model.modelData.state

                state: "regular"
            }


        }
    }
}
