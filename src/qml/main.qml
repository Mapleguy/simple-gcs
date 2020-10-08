import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 1280
    height: 960
    visible: true
    title: qsTr("Simple GCS")

    Loader{
        width: parent.width
        height: 50
        source: "qrc:qml/vehicleselector.qml";
    }
}
