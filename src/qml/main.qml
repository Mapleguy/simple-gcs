import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    minimumHeight: 480
    maximumHeight: 480
    height: 480
    minimumWidth: 640
    maximumWidth: 640
    width: 640
    visible: true
    title: qsTr("Simple GCS")

    Loader{
        width: parent.width
        source: "qrc:qml/vehicleselector.qml";
    }

    Loader{
        width: parent.width
        y: 30
        source: "qrc:qml/commands.qml";
    }
}
