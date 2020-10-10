import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4

Rectangle {
    id: commands
    width: parent.width
    color: "blue"
    RowLayout {
        id: commandLayout
        width: parent.width
        height: 50

        Button {
            text: "Arm"
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            text: "Disarm"
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            text: "Take Off"
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            text: "Land"
            Layout.alignment: Qt.AlignCenter
        }
    }
}
