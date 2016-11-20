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
    title: qsTr("xD Player")

//    Item {
//        anchors.fill: parent
//        width: parent.width
//        height: parent.height
//        focus: true

//        Keys.onPressed: {
//            if(event.key === Qt.Key_Q && (event.modifiers & Qt.ControlModifier))
//            {
//                console.log("exit button pressed")
//                Qt.quit()
//            }
//        }
//    }

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
        height: 80
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
                if(playStatus)
                {
                    playButtonContent.source = "images/playButton.svg"
                    loader.pause()
                }
                else
                {
                    playButtonContent.source = "images/pauseButton.svg"
                    loader.play()
                }
            }


        }

        Button {
            id: previousButton
            anchors.right: playButton.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 20
            width: 40
            height: 40

            padding: 10

            property int playStatus: 0

            contentItem: Image {
                id: previousButtonContent
                source: "images/previousButton.svg"
                fillMode: Image.PreserveAspectFit
                smooth: true
                sourceSize.height: parent.height
                sourceSize.width: parent.width
            }

            background: Rectangle {
                color: "#FFFFFF"
            }
        }

        Button {
            id: nextButton
            anchors.left: playButton.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 20
            width: 40
            height: 40

            padding: 10

            property int playStatus: 0

            contentItem: Image {
                id: nextButtonContent
                source: "images/nextButton.svg"
                fillMode: Image.PreserveAspectFit
                smooth: true
                sourceSize.height: parent.height
                sourceSize.width: parent.width
            }

            background: Rectangle {
                color: "#FFFFFF"
            }
        }

        Button {
            id: repeatButton
            anchors.right: previousButton.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 20
            width: 40
            height: 40

            padding: 10

            property int playStatus: 0

            contentItem: Image {
                id: repeatButtonContent
                source: "images/repeatButton.svg"
                fillMode: Image.PreserveAspectFit
                smooth: true
                sourceSize.height: parent.height
                sourceSize.width: parent.width
            }

            background: Rectangle {
                color: "#FFFFFF"
            }
        }

        Button {
            id: shuffleButton
            anchors.left: nextButton.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 20
            width: 40
            height: 40

            padding: 10

            property int playStatus: 0

            contentItem: Image {
                id: shuffleButtonContent
                source: "images/shuffleButton.svg"
                fillMode: Image.PreserveAspectFit
                smooth: true
                sourceSize.height: parent.height
                sourceSize.width: parent.width
            }

            background: Rectangle {
                color: "#FFFFFF"
            }
        }

//        Image {
//            id: coverArt
//            source: "file"
//            width: 80
//            height: 80
//        }
    }
}
