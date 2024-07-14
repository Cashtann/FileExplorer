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
            required property bool pathItemIsDirectory

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

            Text {
                id: buttonText

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
                    if (delegate.pathItemIsDirectory){
                        //PathsController.printCurrentSubdirectories()
                        FilesController.changeDirectory(delegate.pathItemPath);
                    }
                }
            }
        }
    }
}
