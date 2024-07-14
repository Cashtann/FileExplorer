import QtQuick
import fs.controllers.FilesController
import FileExplorer

Item {
    id: root

    readonly property PathInfo infoProvider: PathInfo {}

    property int imageWidth: 40

    required property url imageSource

    signal clicked

    width: 50
    height: 50

    Rectangle {
        id: background

        anchors.fill: parent

        radius: 5

        color: "#ffffff"
        opacity: if (buttonMouseArea.containsPress) {
                   return 0.1
               } else if (buttonMouseArea.containsMouse) {
                   return 0.05
               } else {
                   0
               }
    }

    Image {
        id: img

        //source: infoProvider.imageSource
        source: root.imageSource


        fillMode: Image.PreserveAspectFit
        //mipmap: true
        anchors {
            fill: parent
            leftMargin: (root.width - root.imageWidth) / 2
            rightMargin: (root.width - root.imageWidth) / 2
        }
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



