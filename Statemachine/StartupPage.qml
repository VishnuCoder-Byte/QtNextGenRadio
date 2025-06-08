// StartupPage.qml
import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: startupPage
    width: parent.width
    height: parent.height

    signal finished()

    Rectangle {
        id: logoRect
        width: 200; height: 200
        color: "#666"
        anchors.centerIn: parent
        radius: 10
        opacity: 0.0

        SequentialAnimation on opacity {
            running: true
            loops: 1
            PropertyAnimation { to: 1.0; duration: 1000 }
            PauseAnimation { duration: 1000 }
            PropertyAnimation { to: 0.0; duration: 1000 }

            onStopped: {
                startupPage.finished()
            }
        }

        Text {
            anchors.centerIn: parent
            text: "Loading..."
            color: "white"
            font.pointSize: 20
        }
    }
}
