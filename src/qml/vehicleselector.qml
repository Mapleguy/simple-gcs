import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4

Rectangle {
    id: selector
    anchors.fill: parent

    RowLayout {
        id: selectorLayout
        width: parent.width
        height: 50

        TextField {
            id: connUrl
            Layout.alignment: Qt.AlignCenter
            placeholderText: qsTr("Connection URL")
        }

        ComboBox {
            id: connTypeDD
            Layout.alignment: Qt.AlignCenter
            model: ListModel {
                id: connTypes
                ListElement {text: "TCP"; color: "red"}
                ListElement {text: "UDP"; color: "red"}
                ListElement {text: "Serial"; color: "red"}
            }
        }

        Button {
            text: "Connect"
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            text: "Disconnect"
            Layout.alignment: Qt.AlignCenter
        }
    }
}
