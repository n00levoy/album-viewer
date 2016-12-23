import QtQuick 2.0
import QtQuick.Controls 2.0

import QtGraphicalEffects 1.0

Rectangle {
    id: playBar
    color: "#FFFFFF"

    Item
    {
        height: parent.height - 40
        width: repeatButton.x - 100
        x: 100
        anchors.verticalCenter: parent.verticalCenter

        Text
        {
            id: playBarText
        }
    }

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
}

