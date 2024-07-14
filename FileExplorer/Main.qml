import QtQuick
import QtQuick.Layouts
import fs.controllers.PathsController

Window {
    id: root

    width: 1080
    height: 600
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
            id: rightbar_bg
            anchors.fill: parent
            color: "#181818"

            Flow {
                anchors.fill: parent

                spacing: 5

                Repeater {
                    model: 5
                    anchors.fill: parent

                    ItemBox {
                        imageSource: "assets/icons/folder_generic.png"
                        text: "test.jpg abcdefghjiklmnop"
                        //text: "test.jpg"
                        anchors {
                            //left: parent.left
                            //top: parent.top
                            //margins: 15
                        }
                    }
                }
            }

            ItemBox {
                imageSource: "assets/icons/folder_generic.png"
                text: "test.jpg abcdefghjiklmnop"
                //text: "test.jpg"
                anchors {
                    //left: parent.left
                    //top: parent.top
                    //margins: 15
                }
            }
        }
    }


}
