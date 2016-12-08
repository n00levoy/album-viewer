import QtQuick 2.7

import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

import QtGraphicalEffects 1.0

import "./"

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("xD Player")

    DropShadow {
        anchors.fill: headerBlock
        verticalOffset: 3
        radius: 8.0
        samples: 17
        color: "#AAAAAA"
    }

    Rectangle {
        id: headerBlock
        width: parent.width
        height: parent.height / 6
        color: "#1E88E5"
        x: 0
        y: 0

        Text {
            id: infoText
            text: qsTr("Фонотека")
            anchors.centerIn: headerBlock
            color: "#FFFFFF"

            font {
                pointSize: 20
            }
        }
    }

    Rectangle {
        anchors.centerIn: parent

        Text {
            id: playingTrackText
            anchors.horizontalCenter: parent.horizontalCenter
            y: chooseFolderButton.y - 25

            visible: false
        }

        Button {
            id: chooseFolderButton
            text: qsTr("Выберите папку")
            anchors.centerIn: parent

            onClicked: {
                fileDialog.visible = true
            }
        }

    }



    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: "file:///E:/1999 - American Football/"
        //folder: shortcuts.home
        //selectFolder: true
        onAccepted: {
            playingTrackText.text = loader.loadFromFile(fileDialog.fileUrl)
            playingTrackText.visible = true
            visible = false
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
    }

    DropShadow {
        anchors.fill: playerBar

        verticalOffset: -2
        radius: 6
        samples: 13
        color: "#BBBBBB"
    }

    PlayerBar {
        id: playerBar

        width: parent.width
        height: parent.height / 5

        x: 0
        y: parent.height - height
    }
}
