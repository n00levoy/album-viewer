import QtQuick 2.7

import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0

import QtQuick.Layouts 1.3

ToolBar {
    id: headerBlock
    Material.foreground: "white"
    Material.primary: "#2196f3"
    height: 50
    width: parent.width

    RowLayout {
        spacing: 20
        anchors.fill: parent

        ToolButton {
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "qrc:/images/drawer.png"
            }
            onClicked: mainMenu.open()
        }

        Label {
            id: titleLabel
            text: "Фонотека"
            font.pixelSize: 24
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignJustify
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true
        }
    }
}

