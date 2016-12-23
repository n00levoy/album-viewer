import QtQuick 2.7

import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0

import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

import QtGraphicalEffects 1.0

import "./"
import "./pages"

ApplicationWindow {
    id: window
    visible: true
    width: 1280
    height: 720
    title: qsTr("xD Player")
    Material.background: "#fafafa"

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

    Drawer {
        id: mainMenu
        width: Math.min(window.width, window.height) / 3 * 2
        height: window.height

        ListView {
            id: listView
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    if (listView.currentIndex != index) {
                        listView.currentIndex = index

                        titleLabel.text = model.title
                        pageView.replace(model.source)
                    }
                    mainMenu.close()
                }
            }

            model: ListModel {
                ListElement { title: "Главная";   source: "qrc:/pages/MainPage.qml" }
                ListElement { title: "Фонотека";  source: "qrc:/pages/Library.qml"  }
                ListElement { title: "Настройки"; source: "qrc:/pages/Settings.qml" }
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    StackView {
        id: pageView
        anchors.top: headerBlock.bottom
        anchors.bottom: playerBar.top

        height: playerBar.top - headerBlock.bottom
        width: parent.width

        initialItem: Library { }
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

        width: window.width
        height: 110

        x: 0
        y: window.height - height
    }
}
