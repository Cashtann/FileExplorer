import QtQuick
import fs.controllers.FilesController
import fs.controllers.ShortcutsController
import FileExplorer

Item {
    id: root

    signal clicked

    ListView {
        id: itemsContainer
        anchors {
            fill: parent
        }
        clip: true
        model: ShortcutsController
        spacing: 5

        delegate: Item {
            id: delegate

            required property string shortcutName
            required property string shortcutPath
            required property url shortcutImageSource

            property int imageWidth: 30

            height: 45

            anchors {
                left: parent.left
                right: parent.right
            }

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

                source: delegate.shortcutImageSource

                fillMode: Image.PreserveAspectFit
                width: delegate.imageWidth
                //mipmap: true
                anchors {
                    left: parent.left
                    leftMargin: 10
                    verticalCenter: parent.verticalCenter
                }
            }

            Text {
                id: buttonText

                text: delegate.shortcutName

                color: "#ffffff"
                font.pointSize: 12

                width: parent.width - img.width - 40
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
                anchors {
                    left: img.right
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                    leftMargin: 10
                    rightMargin: 10

                }
            }

            MouseArea {
                id: buttonMouseArea

                anchors.fill: parent

                hoverEnabled: true

                onClicked: {
                    FilesController.changeDirectory(delegate.shortcutPath);
                }
            }
        }
    }
}
