import QtQuick 2.0

import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0

import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

Item {
    Rectangle {
        anchors.centerIn: parent

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
            loader.loadFromFile(fileDialog.fileUrl)
            visible = false
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
    }
}
