import QtQuick
import fs.controllers.FilesController
import fs.controllers.PathsController
import FileExplorer

Item {
    id: root

    signal clicked

    GridView {
        id: itemsContainer
        anchors {
            fill: parent
        }
        clip: true
        model: FilesController
        //spacing: 5
        cellWidth: 100
        cellHeight: 100


        delegate: Item {
            id: delegate
            readonly property PathInfo infoProvider: PathInfo {}

            required property string pathItemName
            required property string pathItemPath
            required property url pathItemImageSource
            required property bool pathItemIsFile

            property int imageWidth: 50

            width: 95
            height: 95

            Rectangle {
                id: background

                anchors.fill: delegate
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
                source: delegate.pathItemImageSource

                fillMode: Image.PreserveAspectFit
                //mipmap: true
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                    topMargin: 5
                    leftMargin: (delegate.width - delegate.imageWidth) / 2
                    rightMargin: (delegate.width - delegate.imageWidth) / 2
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
                    text: infoProvider.name
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

                //text: infoProvider.name
                text: delegate.pathItemName

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
    }
}
