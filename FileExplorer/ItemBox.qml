import QtQuick
import fs.controllers.PathsController

Item {
    id: root

    property alias text: buttonText.text
    property alias imageSource: img.source
    property string path
    property int imageWidth: 60


    // When creating new object
    // you need to specify "text" (text: "something")
    // as well as id, width and height
    // you may also need to specify Slot
    // "onClicked: { some logic here }

    signal clicked

    width: 120
    height: 120

    Rectangle {
        id: background

        anchors.fill: parent

        radius: 15

        color: "#ffffff"
        opacity: if (buttonMouseArea.containsPress) {
                   return 0.2
               } else if (buttonMouseArea.containsMouse) {
                   return 0.1
               } else {
                   0
               }
    }

    Image {
        id: img


        fillMode: Image.PreserveAspectFit
        mipmap: true
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            topMargin: 5
            leftMargin: (root.width - root.imageWidth) / 2
            rightMargin: (root.width - root.imageWidth) / 2
        }
    }
    /* // Alternative text positioning, creates fixed box around text, maybe used in the future
    Item {
        id: textContainer
        width: parent.width - 20
        anchors {
            bottom: parent.bottom
            top: img.bottom
            bottomMargin: 5
            topMargin: 5
            horizontalCenter: parent.horizontalCenter
        }
        Text {
            id: buttonText
            color: "#ffffff"
            font.pointSize: 12
            width: parent.width
            height: parent.height
            anchors.centerIn: parent
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            elide: Text.ElideRight
            maximumLineCount: 2;
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter



        }
    }*/

    Text {
        id: buttonText
        color: "#ffffff"
        font.pointSize: 12
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
            topMargin: 5
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


