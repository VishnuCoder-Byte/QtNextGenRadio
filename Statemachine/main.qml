import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 600

    // App state
    property string currentState: "startup"

    // Your navigation function
    function nav(item) {
        if (appController.pop) {
            stackView.pop();
        } else {
            stackView.push(item);
        }
    }

    Timer {
        interval: 6000
        running: true
        repeat: false
        onTriggered: showNotification()
    }


    StackView {
        id: stackView
        anchors.fill: parent

        // Load pages based on state
        function loadStatePage(stateName) {
            var component;
            var item;
            switch (stateName) {
                case "startup":
                    component = Qt.createComponent("StartupPage.qml");
                    item = component.createObject(stackView);
                    item.finished.connect(function () {
                        mainWindow.currentState = "main";
                    });
                    break;
                case "main":
                    component = Qt.createComponent("MainPage.qml");
                    item = component.createObject(stackView);
                    break;
            }
            if (item)
                nav(item);
        }

        Component.onCompleted: {
            loadStatePage(currentState);
        }
    }

    // React to state changes
    onCurrentStateChanged: {
        console.log("State changed to:", currentState);
        stackView.clear();  // Remove old page before pushing new one
        stackView.loadStatePage(currentState);
    }

    function showNotification() {
        var component = Qt.createComponent("NotificationPage.qml");
        var notif = component.createObject(stackView);

        notif.notificationFinished.connect(function () {
            stackView.pop();  // Return to previous page
        });

        stackView.push(notif);  // Show notification
    }

}
