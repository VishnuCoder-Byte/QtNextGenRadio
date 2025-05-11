import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 420
    height: 128
    title: "Radio UI"
    color: "black"

    Rectangle {
        anchors.fill: parent
        color: "black"

        Column {
            spacing: 8
            anchors.centerIn: parent
            width: parent.width - 20

            ListView {
                id: sourceListView
                width: parent.width
                height: 60
                model: radioModel.sourceList
                orientation: ListView.Horizontal
                spacing: 10

                delegate: Rectangle {
                    width: 80
                    height: 60
                    color: "#333"
                    radius: 5
                    border.color: "white"

                    Text {
                        anchors.centerIn: parent
                        color: "white"
                        text: modelData
                        font.pixelSize: 14
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            radioModel.setData("channel", modelData)
                            radiocontroller.receiveData(modelData);
                        }
                    }
                }
            }

            Rectangle {
                width: parent.width
                height: 40
                color: "#222"
                radius: 5
                border.color: "white"

                Text {
                    anchors.centerIn: parent
                    color: "lightgreen"
                    text: "Now Playing: " + radioModel.currentChannel
                    font.pixelSize: 16
                }
            }
        }
    }
}
