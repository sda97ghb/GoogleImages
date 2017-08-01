import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ToolBar {
        id: toolbar

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }

        TextEdit {
            id: searchText
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.right: goButton.left
            anchors.leftMargin: 5
            text: ""

            Text {
                text: "What are you searching for?"
                anchors.fill: parent
                color: "gray"
                visible: searchText.text == ""
            }
        }

        ToolButton {
            id: goButton
            anchors {
                verticalCenter: parent.verticalCenter
                right: parent.right
            }
            text: "Search!"
            onClicked: {
                googleImagesSearchDialog.search(searchText.text)
            }
        }
    }

    GoogleImagesSearchDialog {
        id: googleImagesSearchDialog
        clipartMode: true
        onSelected: {
            image.source = selectedUrl
            image2.source = selectedUrl
        }
    }

    Image {
        id: image
        anchors.left: parent.left
        anchors.top: toolbar.bottom
        anchors.leftMargin: 5
        anchors.topMargin: 5

        width: 150
        height: 150
        fillMode: Image.PreserveAspectCrop

        Rectangle {
            color: "#00000000"
            border.width: 1
            border.color: "black"
            anchors.fill: parent
        }
    }
    Image {
        id: image2
        anchors.left: image.right
        anchors.top: toolbar.bottom
        anchors.leftMargin: 5
        anchors.topMargin: 5

        width: 150
        height: 150
        fillMode: Image.PreserveAspectFit

        Rectangle {
            color: "#00000000"
            border.width: 1
            border.color: "black"
            anchors.fill: parent
        }
    }
}
