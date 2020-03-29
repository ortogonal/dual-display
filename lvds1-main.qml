import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    visible: true
    width: 1024
    height: 768

    Rectangle {
        id: rRed
        anchors.centerIn: parent
        color: "blue"
        width: 200
        height: 200
        rotation: 45

        RotationAnimator {
            target: rRed
            from: 360
            to: 0
            duration: 3000
            running: true
            loops: Animation.Infinite
        }

    }

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello LVDS!")
        font.pixelSize: 60
    }
}
