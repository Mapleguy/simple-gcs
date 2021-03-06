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
            text: qsTr("127.0.0.1")
        }

        TextField {
            id: connPort
            Layout.alignment: Qt.AlignCenter
            placeholderText: qsTr("Connection Port/Baud")
            text: qsTr("14550")
        }

        ComboBox {
            id: connTypeDD
            Layout.alignment: Qt.AlignCenter
            model: ListModel {
                id: connTypes
                ListElement {text: "UDP"; color: "red";}
                ListElement {text: "TCP"; color: "red";}
                ListElement {text: "Serial"; color: "red";}
            }
            onCurrentIndexChanged: {
                //Update default values in the URL and Port fields
                switch(connTypes.get(currentIndex).text) {
                    case "UDP":
                        connUrl.text = qsTr("127.0.0.1")
                        connPort.text = qsTr("14550")
                        break
                    case "TCP":
                        connUrl.text = qsTr("127.0.0.1")
                        connPort.text = qsTr("5760")
                        break
                    case "Serial":
                        connUrl.text = qsTr("COM4")
                        connPort.text = qsTr("57600")
                        break
                    default:
                        break
                }
            }
        }

        Button {
            text: "Connect"
            Layout.alignment: Qt.AlignCenter
            onClicked: {
                ConnManager.connectVehicle(connTypeDD.currentIndex, connUrl.text, connPort.text);
            }
        }

        Button {
            text: "Disconnect"
            Layout.alignment: Qt.AlignCenter
            onClicked: {
                ConnManager.disconnectVehicle();
            }
        }
    }
}
