import QtQuick
import QtQuick.Layouts
import fs.controllers.FilesController
import fs.controllers.ShortcutsController
import FileExplorer

Window {
    id: root

    width: 1080
    height: 600

    // minimumWidth: 485
    minimumWidth: 580
    minimumHeight: 260

    visible: true
    title: qsTr("File Explorer")
    color: "#181818"
    //color: "#282828"

    signal searchSubmitted
    signal searchBarOutOfFocus

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

            Item {
                id: shortcutInfoPanel

                height: 50
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                }

                Text {
                    id: shortcutInfoPanelText

                    color: "#ffffff"
                    font.pointSize: 14
                    font.bold: true
                    elide: Text.ElideRight
                    text: "Quick Access"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors {
                        left: parent.left
                        right: parent.right
                        top: parent.top
                        bottom: parent.bottom
                        leftMargin: 20
                        rightMargin: 20
                        topMargin: 5
                        bottomMargin: 5
                    }
                }
            }

            ShortcutsPanel {
                id: shortcutsPanel

                anchors {
                    left: parent.left
                    right: parent.right
                    top: shortcutInfoPanel.bottom
                    bottom: parent.bottom
                    leftMargin: 20
                    rightMargin: 20
                    topMargin: 0
                    bottomMargin: 0
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
                onClicked: {
                    FilesController.goBack()
                }
            }

            ImageButton {
                id: refreshButton
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: goBackButton.right
                    leftMargin: 5
                }
                width: 40
                height: 40
                imageWidth: 30
                imageSource: "assets/icons/refresh.png"
                onClicked: {
                    FilesController.refreshAllPathItems()
                    activeFocus: true
                }
            }


            Rectangle {
                id: pathbar

                color: "#276bb0"

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

                Rectangle {
                    id: pathTextContainer

                    color: "#383838"
                    //activeFocusOnTab: true

                    radius: pathbar.radius
                    anchors {
                        fill: parent
                        margins: pathText.activeFocus ? 2 : 0
                    }
                }

                TextInput {
                    id: pathText

                    text: FilesController.currentDirectory
                    color: "#ffffff"
                    font.pointSize: 12
                    width: parent.width - 20
                    font.bold: false
                    clip: true

                    //elide: Text.ElideLeft
                    verticalAlignment: Text.AlignVCenter

                    anchors {
                        fill: parent
                        margins: 5
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }

                    onAccepted: {
                        searchSubmitted()
                    }
                    Keys.onPressed: (event)=> {
                        if (event.key === Qt.Key_Escape)
                            searchBarOutOfFocus()
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
                bottomMargin: 0
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
    onSearchSubmitted: {
        searchBarOutOfFocus()
        console.log(pathText.text)
    }

    onSearchBarOutOfFocus: {
        pathText.focus = false
    }
}
