import QtQuick
import QtQuick.Layouts
import fs.controllers.PathsController
import fs.controllers.FilesController
import FileExplorer

Window {
    id: root

    width: 1080
    height: 600

    minimumWidth: 485
    minimumHeight: 265

    visible: true
    title: qsTr("File Explorer")
    color: "#181818"
    //color: "#282828"

    Item {
        id: leftbar
        width: 240
        height: parent
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }

        Rectangle {
            id: leftbar_bg
            anchors.fill: parent
            color: "#282828"


            ShortcutButton {
                text: "Folder dupa kupa abcdefghijklmnop"
                width: parent.width - 10
                height: 40
                anchors {
                    left: parent.left
                    right: parent.right
                    margins: 5
                }
            }
        }
    }
    Item {
        id: rightbar
        height: parent
        anchors {
            left: leftbar.right
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        Rectangle {
            id: topbar

            height: 40
            color: root.color
            //color: "#383838"

            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                topMargin: 5
            }

            ImageButton {
                id: goBackButton
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                    leftMargin: 10
                }
                width: 40
                height: 40
                imageWidth: 20
                imageSource: "assets/icons/go_previous.png"


            }

            Rectangle {
                id: pathbar

                color: "#383838"

                radius: 5

                anchors {
                    left: goBackButton.right
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                    leftMargin: 100
                    rightMargin: 100
                    topMargin: 3
                    bottomMargin: 3
                }

                Text {
                    id: pathText

                    text: FilesController.currentDirectory
                    color: "#ffffff"
                    font.pointSize: 12
                    width: parent.width - 20
                    elide: Text.ElideLeft
                    verticalAlignment: Text.AlignVCenter

                    anchors {
                        fill: parent
                        margins: 5
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                }
            }
        }

        Rectangle {
            id: rightbar_bg
            anchors {
                left: parent.left
                right: parent.right
                top: topbar.bottom
                bottom: parent.bottom
                leftMargin: 20
                rightMargin: 20
                bottomMargin: 20
                topMargin: 10
            }
            color: "#181818"
            //color: "#484848"

            FilesPanel {
                id: filesPanel

                anchors {
                    fill: parent
                }
            }
        }
    }


}
