import QtQuick 2.0
import QtQuick.Window 2.2

Window
{
    modality: Qt.WindowModal
    flags: Qt.FramelessWindowHint

    QtObject
    {
        id: internal
        property int token: 0
    }

    function getToken()
    {
        return internal.token
    }

    function _show (token)
    {

        internal.token = token
        show()
    }

    function _close ()
    {
        internal.token = 0
        close ()
    }
}
