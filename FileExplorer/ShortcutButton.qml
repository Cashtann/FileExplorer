import QtQuick
import fs.controllers.PathsController

Item {
    id: root

    property alias text: buttonText.text
    property string path

    // When creating new object
    // you need to specify "text" (text: "something")
    // as well as id, width and height
    // you may also need to specify Slot
    // "onClicked: { some logic here }

    signal clicked

    Rectangle {
        id: background

        anchors.fill: parent

        radius: 10

        color: "#ffffff"
        opacity: if (buttonMouseArea.containsPress) {
                   return 0.2
               } else if (buttonMouseArea.containsMouse) {
                   return 0.1
               } else {
                   0
               }
    }

    Text {
        id: buttonText
        color: "#ffffff"
        font.pointSize: 12

        anchors.centerIn: parent
    }

    MouseArea {
        id: buttonMouseArea

        anchors.fill: parent

        hoverEnabled: true

        onClicked: {
            PathsController.printCurrentSubdirectories()
        }
    }
}


