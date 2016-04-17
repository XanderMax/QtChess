import QtQuick 2.0

Rectangle
{
    property alias pieceState: piece.state

    width: 100
    height: 100

    visible:true

    state: "dangerous"


    border.width: 1
    border.color: "black"

    Piece
    {
        id: piece

        state: "none"

        anchors.fill: parent
    }


    Rectangle
    {
        id: shadow
        anchors.fill: parent
    }


    states:
    [
        State {name: "regular"; PropertyChanges {target: shadow; opacity: 0} },

        State {name: "shaded"; PropertyChanges {target: shadow; opacity: 0.4} },

        State {name: "dangerous"; extend: 'shaded'; PropertyChanges {target: shadow; color: "red"} },

        State {name: "available"; extend: 'shaded'; PropertyChanges {target: shadow; color: "green"} }
    ]




}
