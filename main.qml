import QtQuick 2.7

import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

import QtGraphicalEffects 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    DropShadow {
        anchors.fill: textRect
        verticalOffset: 3
        radius: 8.0
        samples: 17
        color: "#AAAAAA"
    }

    Rectangle {
        id: textRect
        width: parent.width
        height: 100
        color: "#1E88E5"
        x: 0
        y: 0

        Text {
            id: infoText
            text: qsTr("Empty")
            anchors.centerIn: textRect
            color: "#FFFFFF"

            font {
                pointSize: 20
            }
        }
    }

    Button {
        text: qsTr("Choose Folder")
        anchors.centerIn: parent
        onClicked: {
            fileDialog.visible = true
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: "file:///E:/1999 - American Football/"
        //folder: shortcuts.home
        //selectFolder: true
        onAccepted: {
            infoText.text = loader.loadFromFile(fileDialog.fileUrl)
            visible = false
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
    }

    DropShadow {
        anchors.fill: playBar
        verticalOffset: -2
        radius: 6
        samples: 13
        color: "#BBBBBB"
    }

    Rectangle {
        id: playBar
        width: parent.width
        height: 100
        x: 0
        y: parent.height - height
        color: "#FFFFFF"

        Button {
            id: playButton
            anchors.centerIn: parent
            width: 80
            height: 80

            padding: 25

            property int playStatus: 0

            contentItem: Image {
                id: playButtonContent
                source: "images/playButton.svg"
                fillMode: Image.PreserveAspectFit
                smooth: true
                sourceSize.height: parent.height
                sourceSize.width: parent.width
            }

            background: Rectangle {
                color: "#1E88E5"
                radius: 40
            }

            onClicked: {
                playStatus = !playStatus
                if(!playStatus)
                    playButtonContent.source = "images/playButton.svg"
                else
                    playButtonContent.source = "images/pauseButton.svg"
            }
        }

    }
}
