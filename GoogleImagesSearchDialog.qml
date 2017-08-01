import QtQuick 2.0
import QtQuick.Dialogs 1.2
import GoogleImages 1.0

Dialog {
    id: googleImagesSearchDialog

    property bool clipartMode: true

    signal selected(string selectedUrl)

    function search(request) {
        if (request === "")
        {
            messageDialog.open()
            return
        }
        if (clipartMode)
            request += " clipart"
        googleImagesSearch.search(request)
    }

    QtObject {
        id: internal
        property int cols: 5
        property int rows: 4
    }

    width: (gridView.cellWidth + 1) * internal.cols + 10
    height: (gridView.cellHeight + 1) * internal.rows + 58

    modality: Qt.WindowModal
    title: qsTr("Select image for the card")
    standardButtons: StandardButton.Cancel

    MessageDialog {
        id: messageDialog
        text: qsTr("Can't search for empty request.")
    }

    GoogleImagesSearch {
        id: googleImagesSearch
        onGotNewImages: {
            googleImagesSearchDialog.open()
        }
    }

    GridView {
        id: gridView
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        anchors {
            horizontalCenter: parent.horizontalCenter
            horizontalCenterOffset: 1
            top: parent.top
            bottom: parent.bottom
            bottomMargin: 5
        }
        width: (cellWidth + 1) * internal.cols
        cellHeight: 149
        cellWidth: 149
        model: {
            googleImagesSearch.model
        }
        delegate: Image {
            width: 150
            height: 150
            fillMode: Image.PreserveAspectFit
            source: model.imageUrl
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    selected(model.imageUrl)
                    console.log("Selected " + model.imageUrl)
                    googleImagesSearchDialog.close()
                }
            }
            Rectangle {
                color: "#00000000"
                border.width: 1
                border.color: "black"
                anchors.fill: parent
            }
        }

        Rectangle {
            anchors.fill: parent
            anchors.rightMargin: 4
            anchors.bottomMargin: 1
            color: "white"
            border.width: 0
            z: -100
        }
    }
}
