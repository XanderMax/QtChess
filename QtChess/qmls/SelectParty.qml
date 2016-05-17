import QtQuick 2.0


Rectangle
{
    color: "#F5CF9A"

    border.color: "black"
    border.width: 2

    signal partySelected(int party)

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
                    partySelected(1)
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
                    partySelected(0)
                }
            }
        }
    }
}
