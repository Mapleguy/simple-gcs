import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle {
    id: selector
    anchors.fill: parent
    TextField {
        id: connUrl
        width: 500
        placeholderText: qsTr("Connection URL")
    }

    ComboBox {
        id: connTypeDD
        anchors.right: parent.right
        width: 100
        model: ListModel {
            id: connTypes
            ListElement {text: "TCP"; color: "red"}
            ListElement {text: "UDP"; color: "red"}
            ListElement {text: "Serial"; color: "red"}
        }
    }
}
