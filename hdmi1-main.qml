import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    visible: true
    width: 1920
    height: 1080

    Rectangle {
        id: rRed
        anchors.centerIn: parent
        color: "red"
        width: 200
        height: 200
        rotation: 45

        RotationAnimator {
            target: rRed
            from: 0
            to: 360
            duration: 3000
            running: true
            loops: Animation.Infinite
        }
    }

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello HDMI!")
        font.pixelSize: 60
    }

}
