import QtQuick 2.0
import QtQuick.Window 2.2


Window
{
    width: 400
    height: 200

    modality: Qt.WindowModal
    flags: Qt.FramelessWindowHint

    QtObject
    {
        id: internal
        property int token: 0
    }

    function _show (token)
    {

        internal.token = token
        show()
    }

    signal partySelected(int party, int token)

    Rectangle
    {
        color: "#F5CF9A"

        border.color: "black"
        border.width: 2

        anchors.fill: parent

        Row
        {
            anchors.fill: parent

            Cell
            {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: height

                pieceState: "w_king"
                state: "regular"

                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        if(internal.token !== 0)
                        {
                            partySelected(1, internal.token)
                        }

                        internal.token = 0
                    }
                }
            }

            Cell
            {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: height

                pieceState: "b_king"
                state: "regular"

                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        if(internal.token !== 0)
                        {
                            partySelected(0, internal.token)
                        }
                        internal.token = 0
                    }
                }
            }
        }
    }
}
