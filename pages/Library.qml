import QtQuick 2.7

import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0

import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

import QtGraphicalEffects 1.0

Item {
    DropShadow {
        anchors.fill: chooseBar
        verticalOffset: 3
        radius: 6
        samples: 13
        color: "#999999"
    }

    TabBar {
        id: chooseBar
        width: parent.width

        Material.background: "#2196f3"
        Material.accent:     "white"
        Material.foreground: "white"

        TabButton {
            id: artistButton
            text: qsTr("Исполнители")
            font.bold: true

            onClicked: {
                var x = albumButton.width

                font.bold = true
                albumButton.font.bold = false

                albumButton.implicitWidth = x
            }
        }
        TabButton {
            id: albumButton
            text: qsTr("Альбомы")

            onClicked: {
                var x = artistButton.width
                var y = width

                font.bold = true
                artistButton.font.bold = false

                artistButton.implicitWidth = x
                implicitWidth = y
            }
        }
    }

    StackLayout {
        id: chooseBarLayout
        width: parent.width
        height: parent.height

        currentIndex: chooseBar.currentIndex
        Item {
            id: artistTab
        }

        Item {
            id: albumTab
        }
    }
}
