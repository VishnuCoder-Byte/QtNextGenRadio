// MainPage.qml
import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: mainPage
    width: parent.width
    height: parent.height
    opacity: 1.0

    Rectangle {
        anchors.fill: parent
        color: "#ddd"

        Text {
            text: "I'm the main page (state 2)"
            anchors.centerIn: parent
            font.pointSize: 20
        }
    }

    // ✅ Define the animation properly
    NumberAnimation {
        id: fadeInAnim
        target: mainPage
        property: "opacity"
        from: 0
        to: 1
        duration: 800
    }

    Component.onCompleted: fadeInAnim.start()
}
