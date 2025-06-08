// NotificationPage.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: parent.width
    height: parent.height

    Rectangle {
        anchors.fill: parent
        color: "#f8e71c"

        Text {
            anchors.centerIn: parent
            text: "This is a notification"
            font.pointSize: 18
        }

        Button {
            text: "OK"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 20
            onClicked: {
                // Signal back to main.qml
                notificationFinished()
            }
        }
    }

    signal notificationFinished()
}
