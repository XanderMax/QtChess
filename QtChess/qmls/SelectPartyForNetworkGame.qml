import QtQuick 2.0
import QtQuick.Window 2.2



Window
{
    width: 400
    height: 250

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

    SelectParty
    {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: 200
    }

    Row
    {
        TextInput
        {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }

        TextInput
        {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
    }


}
