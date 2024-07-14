import QtQuick
import fs.controllers.PathsController
import fs.controllers.FilesController
import FileExplorer

Item {
    id: root
}


/*
Item {
    id: root

    readonly property PathInfo infoProvider: PathInfo {}

    property int imageWidth: 50


    required property string name
    required property string path
    required property url imageSource
    required property bool isFile

    signal clicked

    width: 100
    height: 100

    Rectangle {
        id: background

        anchors.fill: parent

        radius: 15

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
            top: parent.top
            left: parent.left
            right: parent.right
            topMargin: 5
            leftMargin: (root.width - root.imageWidth) / 2
            rightMargin: (root.width - root.imageWidth) / 2
        }
    }

    Text {
        id: buttonText

        //text: infoProvider.name
        text: root.name

        color: "#ffffff"
        font.pointSize: 10

        width: parent.width - 20
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        elide: Text.ElideRight

        maximumLineCount: 2;

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        anchors {
            bottom: parent.bottom
            top: img.bottom
            bottomMargin: 5
            //topMargin: 5
            horizontalCenter: parent.horizontalCenter
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
*/


