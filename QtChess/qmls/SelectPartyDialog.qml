import QtQuick 2.0
import QtQuick.Window 2.2


UTMWindow
{
    width: 400
    height: 200

    modality: Qt.WindowModal
    flags: Qt.FramelessWindowHint

    signal selected(int party, int token)

    SelectParty
    {
        anchors.fill: parent

        onPartySelected:
        {
            selected(party, getToken())

            _close()
        }
    }


}
