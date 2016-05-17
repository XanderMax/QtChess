import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4



UTMWindow
{
    width: 400
    height: 250

    QtObject
    {
        id: internal
        property bool server: true
    }

    function showServer(token)
    {
        internal.server = true
        _show(token)
    }

    function showClient(token)
    {
        internal.server = false
        _show(token)
    }

    signal selected(int party, int port, string host, int token)


    onClosing:
    {
        internal.server = true
    }

    Column
    {
        SelectParty
        {
            width: 400

            height: 200

            onPartySelected:
            {
                selected(party, port.text*1, host.text, getToken())
            }
        }

        Row
        {
            TextInput
            {
                id: port
                width: 200
                height: 50

                text: "" + Math.ceil(Math.random() % 100 + 1024)

                mouseSelectionMode: TextInput.SelectCharacters
                selectByMouse: true
            }

            TextInput
            {
                id: host
                width: 200
                height: 50

                text: "127.0.0.1"

                mouseSelectionMode: TextInput.SelectCharacters
                selectByMouse: true
            }
        }
    }


}
